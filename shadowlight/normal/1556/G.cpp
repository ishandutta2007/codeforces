#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

set<pair<ll, ll>> segs;
set<pair<ll, ll>> connected_segs;
vector<ll> values;

struct DSU {
  int n;
  vector<int> p;
  vector<int> r;

  DSU(int n) : n(n), p(n), r(n) {
    iota(all(p), 0);
  }

  int get(int v) {
    return (p[v] == v ? v : p[v] = get(p[v]));
  }

  bool uni(int v, int u) {
    v = get(v);
    u = get(u);
    assert(v > 0 && u > 0);
    if (v == u) {
      return false;
    }
    //per("uni", values[v], values[u]);
    if (r[v] > r[u]) swap(v, u);
    if (r[v] == r[u]) ++r[u];
    p[v] = u;
    return true;
  }
} dsu(0);

struct Query {
  int tp;
  ll a, b;
};

vector<Query> qs;
int n, m;
map<ll, int> num;


const ll INF = (ll)1e18 + 7;

ll find_seg(ll x) {
  auto it = segs.upper_bound({x + 1, -1});
  if (it == segs.begin()) {
    return -1;
  }
  --it;
  if (it->y < x) {
    return -1;
  }
  return it->x;
}

void insert_segment(ll l, ll r) {
  auto it = connected_segs.upper_bound({l, r});
  if (it != connected_segs.begin()) {
    --it;
    if (it->y < l) {
      ++it;
    }
  }

  vector<pair<ll, ll>> inserted;
  while (it != connected_segs.end() && it->x <= r) {
    assert(!(l <= it->x && it->y <= r));
    ll x = it->x, y = it->y;
    connected_segs.erase(it++);
    
    assert(x < l && r < y);

    if (x < l) {
      auto it = segs.upper_bound({l, r});
      assert(it != segs.begin());
      --it;
      inserted.pb({x, it->y});
    } 

    if (y > r) {
      auto it = segs.upper_bound({r, INF});
      inserted.pb({it->x, y});
    }
  }

  for (auto t : inserted) {
    connected_segs.insert(t);
  }

  int index = -1;
  ll val = 0;
  for (int i = n - 1; i >= 0; --i) {
    if ((l & (1LL << i)) != (r & (1LL << i))) {
      index = i;
      break;
    } else {
      val += (1LL << i) & l;
    }
  }
  vector<pair<ll, ll>> cur;
  if (l == r) {
    cur.pb({l, r});
  } else {
    assert(index != -1);
    cur.pb({l, val + (1LL << index) - 1});
    cur.pb({val + (1LL << index), r});
  }

  index = max(index, 0);
  for (auto [ln, rn] : cur) {
    segs.insert({ln, rn});
    connected_segs.insert({ln, rn});
  }

  //per(segs);
  for (auto [ln, rn] : cur) {
    dsu.uni(num[ln], num[rn]);
    assert(ln <= rn);
    //per(connected_segs);

    for (int k = n - 1; k >= index; --k) {
      assert((ln & (1LL << k)) == (rn & (1LL << k)));

      ll lt = ln ^ (1LL << k), rt = rn ^ (1LL << k);

      auto it = connected_segs.lower_bound({lt, -1});
      if (it != connected_segs.begin()) {
        --it;
        if (it->y < lt) {
          ++it;
        }
      }

      if (it == connected_segs.end()) continue;
      bool need_to_add = false;

        auto t = segs.lower_bound({lt, -1});
        bool has = false;
        if (t != segs.end() && t->x <= rt) has = true;
        if (t != segs.begin()) {
            --t;
            if (t->y >= lt) {
                has = true;
            }
        }
        if (!has) continue;
             
       
      ll x = it->x, y = it->y;
      while (it != connected_segs.end() && it->x <= rt) {
        need_to_add = true;
        y = it->y;
        dsu.uni(num[ln], num[it->x]);
        connected_segs.erase(it++);
      }
      if (need_to_add) connected_segs.insert({x, y});
    }
    for (int k = index - 1; k >= 0; --k) {
      ll lt, rt;
      if (ln & (1LL << index)) {
        lt = ln;
        if (rn & (1LL << k)) {
          rt = rn | ((1LL << k) - 1);
        } else {
          lt = (rn & (~((1LL << k) - 1))) + (1LL << k);
          rt = rn + (1LL << k);
        }
      } else {
        rt = rn;
        if (ln & (1LL << k)) {
          lt = ln - (1LL << k);
          rt = (ln | ((1LL << k) - 1)) - (1LL << k);
        } else {
          lt = ln & (~((1LL << k) - 1));
        }
      }
      
      auto it = connected_segs.lower_bound({lt, -1});
      if (it != connected_segs.begin()) {
        --it;
        if (it->y < lt) {
          ++it;
        }
      }

      if (it == connected_segs.end()) continue;

      bool need_to_add = false;

      auto t = segs.lower_bound({lt,-1});
        bool has = false;
        if (t != segs.end() && t->x <= rt) has = true;
        if (t != segs.begin()) {
            --t;
            if (t->y >= lt) {
                has = true;
            }
        }
        if (!has) continue;

      ll x = it->x, y = it->y;
      while (it != connected_segs.end() && it->x <= rt) {
        need_to_add = true;
        y = it->y;
        dsu.uni(num[ln], num[it->x]);
        connected_segs.erase(it++);
      }
      if (need_to_add) connected_segs.insert({x, y});
    }
  }
}

int main(){
#ifdef LOCAL
  freopen("G_input.txt", "r", stdin);
  //freopen("G_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  values.pb(-1);

  vector<pair<ll, ll>> banned;
  for (int i = 0; i < m; ++i) {
    string tp;
    ll l, r;
    cin >> tp >> l >> r;
    qs.pb({tp == "ask" ? 1 : 0, l, r}); 
    if (qs.back().tp) continue;

    banned.pb({l, r});

    int index = -1;
    ll val = 0;
    for (int i = n - 1; i >= 0; --i) {
      if ((l & (1LL << i)) != (r & (1LL << i))) {
        index = i;
        break;
      } else {
        val += (1LL << i) & l;
      }
    }
    vector<pair<ll, ll>> cur;
    if (l == r) {
      cur.pb({l, r});
    } else {
      assert(index != -1);
      cur.pb({l, val + (1LL << index) - 1});
      cur.pb({val + (1LL << index), r});
    }

    for (auto t : cur) {
      if (!num.count(t.x)) {
        num[t.x] = values.size();
        values.pb(t.x);
      }
      if (!num.count(t.y)) {
        num[t.y] = values.size();
        values.pb(t.y);
      }
    }
  }
  
  sort(all(banned));
  ll pr = -1;
  vector <pair<ll, ll>> sq;
  for (auto [a, b] : banned) {
    if (a > pr + 1) {
      ll l = pr + 1, r = a - 1;

      int index = -1;
      ll val = 0;
      for (int i = n - 1; i >= 0; --i) {
        if ((l & (1LL << i)) != (r & (1LL << i))) {
          index = i;
          break;
        } else {
          val += (1LL << i) & l;
        }
      }
      vector<pair<ll, ll>> cur;
      if (l == r) {
        cur.pb({l, r});
      } else {
        assert(index != -1);
        cur.pb({l, val + (1LL << index) - 1});
        cur.pb({val + (1LL << index), r});
      }

      for (auto t : cur) {
        if (!num.count(t.x)) {
          num[t.x] = values.size();
          values.pb(t.x);
        }
        if (!num.count(t.y)) {
          num[t.y] = values.size();
          values.pb(t.y);
        }
      }
      sq.pb({l, r});
    }
    pr = b;
  }

  if ((1LL << n) > pr + 1) {
    ll l = pr + 1, r = (1LL << n) - 1;

    int index = -1;
    ll val = 0;
    for (int i = n - 1; i >= 0; --i) {
      if ((l & (1LL << i)) != (r & (1LL << i))) {
        index = i;
        break;
      } else {
        val += (1LL << i) & l;
      }
    }
    vector<pair<ll, ll>> cur;
    if (l == r) {
      cur.pb({l, r});
    } else {
      assert(index != -1);
      cur.pb({l, val + (1LL << index) - 1});
      cur.pb({val + (1LL << index), r});
    }

    for (auto t : cur) {
      if (!num.count(t.x)) {
        num[t.x] = values.size();
        values.pb(t.x);
      }
      if (!num.count(t.y)) {
        num[t.y] = values.size();
        values.pb(t.y);
      }
    }
    sq.pb({l, r});
  }

  //per(values);

  dsu = DSU(values.size());

  for (auto t : sq) {
    insert_segment(t.x, t.y);
  }

  vector<int> res;
  reverse(all(qs));

  for (auto q : qs) {
    if (q.tp) {
      //per("ans", q.a, q.b);
      //per(segs);
      ll x = find_seg(q.a), y = find_seg(q.b);

      assert(x != -1 && y != -1);
      res.pb(dsu.get(num[x]) == dsu.get(num[y]));
      continue;
    }
    insert_segment(q.a, q.b);
  }

  reverse(all(res));
  for (int x : res) {
    cout << x << "\n";
  }
}