#include <bits/stdc++.h>

using namespace std;

class segtree {
  vector<int> tree;
  int n;

  void pull(int x, int z) {
    tree[x] = min(tree[x + 1], tree[z]);
  }

  void modify(int x, int l, int r, int p, int v) {
    if (l == r) {
      tree[x] = v;
    } else {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
      if (p <= y) {
        modify(x + 1, l, y, p, v);
      } else {
        modify(z, y + 1, r, p, v);
      }
      pull(x, z);
    }
  }

  int query(int x, int l, int r, int p) {
    if (l == r) {
      return tree[x];
    } else {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
      if (p <= y) {
        return query(x + 1, l, y, p);
      } else {
        return min(tree[x + 1], query(z, y + 1, r, p));
      }
    }
  }
 
 public:
  segtree(int n): n(n) {
    tree.resize(n * 2 - 1);
  }

  void modify(int p, int v) {
    modify(0, 0, n - 1, p, v);
  }

  int query(int p) {
    return query(0, 0, n - 1, p);
  }
};

struct node {
  node* l = NULL;
  node* r = NULL;
  long long a = 0;
  long long b = 0;
};

class persistent_segtree {
  vector<node*> roots;
  int n;

  void modify(node* &x, int l, int r, int ll, int rr, long long a, long long b) {
    if (x == NULL) {
      x = new node();
    } else {
      x = new node(*x);
    }
    if (ll <= l && r <= rr) {
      x->a += a;
      x->b += b;
    } else {
      int y = (l + r) >> 1;
      if (ll <= y) {
        modify(x->l, l, y, ll, rr, a, b);
      }
      if (rr > y) {
        modify(x->r, y + 1, r, ll, rr, a, b);
      }
    }
  }

  long long query(node* x, int l, int r, int p, int v) {
    if (x == NULL) {
      return 0;
    }
    long long res = x->a * v + x->b;
    if (l != r) {
      int y = (l + r) >> 1;
      if (p <= y) {
        res += query(x->l, l, y, p, v);
      } else {
        res += query(x->r, y + 1, r, p, v);
      }
    }
    return res;
  }

 public:
  persistent_segtree(int n): n(n) {
    roots.push_back(NULL);
  }

  void extend() {
    roots.push_back(roots.back());
  }

  void modify(int l, int r, long long a, long long b) {
    modify(roots.back(), 0, n - 1, l, r, a, b);
  }

  long long query(int p, int v) {
    return query(roots[v + 1], 0, n - 1, p, v + 1);
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  segtree st(n + 1);
  persistent_segtree pst(n + 1);
  map<int, int> prefix;
  prefix[-1] = -1;
  prefix[0] = 0;
  prefix[n + 1] = 0;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int a, l, r, k;
    cin >> a >> l >> r >> k;
    a = (a + ans) % (n + 1);
    l = (l + ans) % (i + 1);
    r = (r + ans) % (i + 1);
    if (l > r) {
      swap(l, r);
    }
    k = (k + ans) % (n + 1);
    st.modify(a, i + 1);
    pst.extend();
    if (prefix.count(a)) {
      int pre = prev(prefix.find(a))->second;
      int nxt = next(prefix.find(a))->first;
      int old = prefix[a];
      prefix.erase(a);
      int cur = a;
      while (cur < nxt) {
        int value = st.query(cur);
        int low = cur;
        int high = nxt - 1;
        while (low < high) {
          int mid = (low + high + 1) >> 1;
          if (st.query(mid) == value) {
            low = mid;
          } else {
            high = mid - 1;
          }
        }
        pst.modify(cur, low, value - old, -(long long) (value - old) * i);
        if (value != pre) {
          prefix[cur] = value;
        }
        cur = low + 1;
      }
    }
    auto solve = [&](int l, int r, int p) {
      if (p < 0) {
        return (long long) (r - l + 2) * (r - l + 1) / 2;
      }
      if (pst.query(p, r) - pst.query(p, r - 1) <= l) {
        return 0ll;
      }
      int low = l, high = r;
      while (low < high) {
        int mid = (low + high) >> 1;
        if (pst.query(p, mid) - pst.query(p, mid - 1) > l) {
          high = mid;
        } else {
          low = mid + 1;
        }
      }
      return (pst.query(p, r) - pst.query(p, high - 1)) - (long long) l * (r - high + 1);
    };
    ans = solve(l, r, k - 1) - solve(l, r, k);
    cout << ans << "\n";
  }
  return 0;
}