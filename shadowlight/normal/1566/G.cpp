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

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

struct Edge {
  int v, u, w;
};

ostream &operator<<(ostream& out, Edge a) {
  out << "{" << a.w << ", " << a.v << ", " << a.u << "}";
  return out;
}

bool operator<(Edge a, Edge b) {
  if (a.w != b.w) {
    return a.w < b.w;
  }
  if (a.v != b.v) {
    return a.v < b.v;
  }
  return a.u < b.u;
}

const int N = 1e5 + 7;

map <int, int> weight[N];
map <int, int> sweight[N];
set<Edge> all_edges;
set<Edge> edges[N];

vector<Edge> total_edges[N];
vector<Edge> total;

struct Tree {
  int n;
  vector<int> t;

  Tree() {}

  Tree(vector<int>& a) : n(a.size()), t(2 * n) {
    for (int i = 0; i < n; ++i) {
      t[i + n] = a[i];
    }
    for (int i = n - 1; i > 0; --i) {
      t[i] = t[2 * i] + t[2 * i + 1];
    }
  }

  void change(int pos, int x) {
    pos += n;
    t[pos] = x;
    pos /= 2;
    while (pos) {
      t[pos] = t[2 * pos] + t[2 * pos + 1];
      pos /= 2;
    }
  }

  int get(int l, int r) {
    int res = 0;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
      if ((l & 1) == 1) {
        res += t[l++];
      }
      if ((r & 1) == 0) {
        res += t[r--];
      }
    }
    return res;
  }
};

Tree total_tree;
Tree edges_tree[N];

const ll INF = 4e9 + 7;
const int MINF = 1e9 + 7;

int now = 0;
ll res[N];

vector<vector<Edge>> upd_edges;
set <pair <ll, int>> branches;
vector<pair<int, Edge>> queries;

ll calc_branch(int v) {
  if (edges[v].size() < 3) {
    return INF;
  }
  ll res = 0;
  int cnt = 0;
  auto it = edges[v].begin();
  while (cnt < 3 && it != edges[v].end()) {
    res += it->w;
    ++cnt, ++it;
  }
  return res;
}

ll find_res(int v, int u, int w) {
  int lt = 0, rt = 1e9 + 7;
  while (rt - lt > 1) {
    int mt = (lt + rt) / 2;

    int pos = lower_bound(all(total), Edge({-1, -1, mt + 1})) - total.begin();
    int pos1 = lower_bound(all(total_edges[v]), Edge({-1, -1, mt + 1})) - total_edges[v].begin();
    int pos2 = lower_bound(all(total_edges[u]), Edge({-1, -1, mt + 1})) - total_edges[u].begin();

    int a = total_tree.get(0, pos - 1);
    int b = edges_tree[v].get(0, pos1 - 1) + edges_tree[u].get(0, pos2 - 1);
    if (w <= mt) {
      --b;
    }

    if (a == b) {
      lt = mt;
    } else {
      rt = mt;
    }
  }
  if (rt == 1e9 + 7) {
    return INF;
  }
  return rt + w;
}

int main(){
#ifdef LOCAL
  freopen("G_input.txt", "r", stdin);
  //freopen("G_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int v, u, w;
    cin >> v >> u >> w;
    --v, --u;
    if (v > u) swap(v, u);

    Edge now = {v, u, w};

    all_edges.insert(now);
    edges[v].insert(now);
    edges[u].insert(now);

    total.pb(now);
    total_edges[v].pb(now);
    total_edges[u].pb(now);

    weight[v][u] = w;
    sweight[v][u] = w;
  }
  int start = total.size();

  for (int v = 0; v < n; ++v) {
    branches.insert({calc_branch(v), v});
  }

  vector<Edge> tet;
  int cnt = 0;
  auto it = all_edges.begin();
  while (cnt < 3 && it != all_edges.end()) {
    tet.pb(*it);
    ++cnt;
    ++it;
  }
  upd_edges.pb(tet);
  res[0] = branches.begin()->x;

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int tp;
    int v, u, w = -1;
    cin >> tp >> v >> u;
    --v, --u;
    if (v > u) swap(v, u);

    if (tp) {
      cin >> w;
      weight[v][u] = w;
    } else {
      w = weight[v][u];
      weight[v].erase(u);
    }

    branches.erase({calc_branch(v), v});
    branches.erase({calc_branch(u), u});

    Edge now = {v, u, w};
    if (tp) {
      all_edges.insert(now);
      edges[v].insert(now);
      edges[u].insert(now);

      total.pb(now);
      total_edges[v].pb(now);
      total_edges[u].pb(now);
    } else {
      all_edges.erase(now);
      edges[v].erase(now);
      edges[u].erase(now);
    }
    queries.pb({tp, now});

    vector<Edge> tet;
    int cnt = 0;
    auto it = all_edges.begin();
    while (cnt < 3 && it != all_edges.end()) {
      tet.pb(*it);
      ++cnt;
      ++it;
    }
    upd_edges.pb(tet);
  

    branches.insert({calc_branch(v), v});
    branches.insert({calc_branch(u), u});
    res[i + 1] = branches.begin()->x;
  }

  sort(all(total));
  vector<int> on;
  for (auto e : total) {
    on.pb(sweight[e.v][e.u] == e.w);
  }

  total_tree = Tree(on);

  for (int v = 0; v < n; ++v) {
    sort(all(total_edges[v]));
    vector<int> on;
    for (auto e : total_edges[v]) {
      on.pb(sweight[e.v][e.u]== e.w);
    }

    edges_tree[v] = Tree(on);
  }

  for (int i = 0; i <= q; ++i) {
    for (auto e : upd_edges[i]) {
      uin(res[i], find_res(e.v, e.u, e.w));
      //per(e, find_res(e.v, e.u, e.w));
    }
    cout << res[i] << "\n";
    
    if (i != q) {
      auto [tp, e] = queries[i];
      int v = e.v, u = e.u;

      int pos = lower_bound(all(total),  e) - total.begin();
      int pos1 = lower_bound(all(total_edges[v]), e) - total_edges[v].begin();
      int pos2 = lower_bound(all(total_edges[u]), e) - total_edges[u].begin();

      total_tree.change(pos, tp);
      edges_tree[v].change(pos1, tp);
      edges_tree[u].change(pos2, tp);
    }
  }

}