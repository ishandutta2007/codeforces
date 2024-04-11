#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

class node {
 public:
  node* l;
  node* r;
  node* p;
  int time, ltime, rtime, speed, rspeed;
  long long sum, lsum;

  node(int time, int speed): time(time), speed(speed) {
    l = r = p = NULL;
    ltime = rtime = time;
    rspeed = speed;
    sum = lsum = 0;
  }

  void pull() {
    ltime = rtime = time;
    rspeed = speed;
    sum = lsum = 0;
    if (l != NULL) {
      l->p = this;
      ltime = l->ltime;
      lsum = min(lsum, sum + l->lsum);
      sum += l->sum + (long long) l->rspeed * (time - l->rtime);
      lsum = min(lsum, sum);
    }
    if (r != NULL) {
      r->p = this;
      rtime = r->rtime;
      rspeed = r->rspeed;
      sum += (long long) speed * (r->ltime - time);
      lsum = min(lsum, sum + r->lsum);
      sum += r->sum;
    }
  }
};

void rotate(node* v) {
  node* u = v->p;
  v->p = u->p;
  if (v->p != NULL) {
    if (v->p->l == u) {
      v->p->l = v;
    }
    if (v->p->r == u) {
      v->p->r = v;
    }
  }
  if (v == u->l) {
    u->l = v->r;
    v->r = u;
  } else {
    u->r = v->l;
    v->l = u;
  }
  u->pull();
  v->pull();
}

void splay(node* v, node* aim = NULL) {
  while (v->p != aim) {
    node* u = v->p;
    if (u->p != aim) {
      if ((u->l == v) ^ (u->p->l == u)) {
        rotate(v);
      } else {
        rotate(u);
      }
    }
    rotate(v);
  }
}

node* insert(node* v, node* u) {
  while (true) {
    if (u->time > v->time) {
      if (v->r == NULL) {
        v->r = u;
        u->p = v;
        break;
      } else {
        v = v->r;
      }
    } else {
      if (v->l == NULL) {
        v->l = u;
        u->p = v;
        break;
      } else {
        v = v->l;
      }
    }
  }
  splay(u);
  return u;
}

node* find(node* v, int time) {
  while (true) {
    if (time == v->time) {
      break;
    } else if (time > v->time) {
      v = v->r;
    } else {
      v = v->l;
    }
  }
  splay(v);
  return v;
}

node* find_less(node* v, int time) {
  node* res = NULL;
  node* from = NULL;
  while (v != NULL) {
    from = v;
    if (v->time < time) {
      res = v;
      v = v->r;
    } else {
      v = v->l;
    }
  }
  splay(from);
  splay(res);
  return res;
}

node* find_greater(node* v, int time) {
  node* res = NULL;
  node* from = NULL;
  while (v != NULL) {
    from = v;
    if (v->time > time) {
      res = v;
      v = v->l;
    } else {
      v = v->r;
    }
  }
  splay(from);
  splay(res);
  return res;
}

node* get_rightmost(node* v) {
  while (v->r != NULL) {
    v = v->r;
  }
  splay(v);
  return v;
}

node* merge(node* v, node* u) {
  v = get_rightmost(v);
  splay(u);
  v->r = u;
  v->pull();
  return v;
}

node* erase(node* v) {
  splay(v);
  v->l->p = v->r->p = NULL;
  return merge(v->l, v->r);
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(12);
  node* lmost = new node(0, 0);
  node* rmost = new node(inf, 0);
  lmost->r = rmost;
  lmost->pull();
  node* root = lmost;
  int tt;
  cin >> tt;
  while (tt--) {
    int type;
    cin >> type;
    if (type == 1) {
      int time, speed;
      cin >> time >> speed;
      root = insert(root, new node(time, speed));
    } else if (type == 2) {
      int time;
      cin >> time;
      root = erase(find(root, time));
    } else {
      int l, r;
      long long x;
      cin >> l >> r >> x;
      if (!x) {
        cout << l << "\n";
        continue;
      }
      root = find_less(root, l);
      node* left = root;
      root = find_greater(root, r);
      node* right = root;
      splay(left, right);
      node* v = left->r;
      if (v == NULL) {
        cout << -1 << "\n";
      } else {
        if (x + v->lsum <= 0) {
          while (true) {
            if (v->l != NULL) {
              if (x + v->l->lsum <= 0) {
                v = v->l;
              } else {
                x += v->l->sum;
                if (x + (long long) v->l->rspeed * (v->time - v->l->rtime) <= 0) {
                  cout << v->l->rtime - (double) x / v->l->rspeed << "\n";
                  break;
                } else {
                  x += (long long) v->l->rspeed * (v->time - v->l->rtime);
                  if (x + (long long) v->speed * (v->r->ltime - v->time) <= 0) {
                    cout << v->time - (double) x / v->speed << "\n";
                    break;
                  } else {
                    x += (long long) v->speed * (v->r->ltime - v->time);
                    v = v->r;
                  }
                }
              }
            } else {
              if (x + (long long) v->speed * (v->r->ltime - v->time) <= 0) {
                cout << v->time - (double) x / v->speed << "\n";
                break;
              } else {
                x += (long long) v->speed * (v->r->ltime - v->time);
                v = v->r;
              }
            }
          }
          splay(v);
          root = v;
        } else if (x + v->sum + (long long) v->rspeed * (r - v->rtime) <= 0) {
          cout << v->rtime - (double) (x + v->sum) / v->rspeed << "\n";
        } else {
          cout << -1 << "\n";
        }
      }
    }
  }
  return 0;
}