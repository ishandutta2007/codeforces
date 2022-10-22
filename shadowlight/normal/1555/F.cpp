#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
//
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
 
 
int n, q;
 
struct DSU {
  int n;
  vector <int> p, r;
  
  DSU(int n) : n(n), p(n), r(n) {
    iota(all(p), 0);
  }
 
  int get(int v) {
    return (p[v] == v ? v : p[v] = get(p[v]));
  }
 
  bool uni(int v, int u) {
    v = get(v);
    u = get(u);
    if (v == u) return false;
 
    if (r[v] == r[u]) ++r[u];
    if (r[v] > r[u]) swap(v, u);
    p[v] = u;
    return true;
  }
};
 
struct Edge {
  int v, u, c;
  int id;
};
vector <Edge> edges;
 
const int N = 3e5 + 7;
const int Q = 5e5 + 7;
 
const int LOGN = 20;
 
vector <pair<int, int>> gr[N];
int val[N];
bool used[N];
bool res[Q];
int h[N], par[N];
int lt[N], rt[N];
int binup[N][LOGN];
int timer = 0;
 
void dfs(int v, int p, int now, int he) {
  used[v] = true;
  val[v] = now;
  h[v] = he;
  par[v] = p;
  lt[v] = rt[v] = timer++;
 
  binup[v][0] = p;
  for (int i = 1; i < LOGN; ++i) {
    binup[v][i] = -1;
    if (binup[v][i - 1] == -1) continue;
    binup[v][i] = binup[binup[v][i - 1]][i - 1];
    //per(v, i, binup[v][i]);
  }

  for (auto [u, w] : gr[v]) {
    if (u == p) continue;
    dfs(u, v, now ^ w, he + 1);
    rt[v] = max(rt[v], rt[u]);
  }
 
  //per(v, lt[v], rt[v]);
}
 
int up(int v, int d) {
  for (int i = 0; i < LOGN; ++i) {
    if (d & (1 << i)) {
      v = binup[v][i];
    }
    if (v == -1) {
      return -1;
    }
  }
  return v;
}
 
int lca(int v, int u) {
  if (h[v] < h[u]) swap(v, u);
  v = up(v, h[v] - h[u]);
  if (v == u) {
    return v;
  }
  for (int i = LOGN - 1; i >= 0; --i) {
    if (binup[v][i] == binup[u][i]) continue;
    v = binup[v][i];
    u = binup[u][i];
  }
  assert(binup[v][0] == binup[u][0]);
  return binup[v][0];
}
 
const int INF = 1e9 + 7;
 
struct Tree {
  int n;
  vector <int> t;
  vector <int> val;
 
  void add_val(int v, int x) {
    val[v] = max(val[v], x);
    t[v] = max(t[v], x);
  }
 
  void push(int v) {
    add_val(2 * v, val[v]);
    add_val(2 * v + 1, val[v]);
    val[v] = -1;
  }
 
  void relax(int v) {
    t[v] = max(t[2 * v], t[2 * v + 1]);
  }
 
  Tree(int n) : n(n), t(4 * n, -1), val(4 * n, -1) {}
 
  void add_seg(int l, int r, int x, int lt, int rt, int vt) {
    if (l >= rt || lt >= r) {
      return;
    }
    if (l <= lt && rt <= r) {
      add_val(vt, x);
      return;
    }
    push(vt);
    int mt = (lt + rt) / 2;
    add_seg(l, r, x, lt, mt, 2 * vt);
    add_seg(l, r, x, mt, rt, 2 * vt + 1);
    relax(vt);
  }
 
  void add_seg(int l, int r, int x) {
    //per("SET", l, r, x);
    add_seg(l, r, x, 0, n, 1);
  }
 
  int get(int pos, int lt, int rt, int vt) {
    //cout << lt << " " << rt << " " << pos << " " << t[vt] << endl;
    if (rt - lt == 1) {
      return t[vt];
    }
    push(vt);
    int mt = (lt + rt) / 2;
    int res;
    if (pos < mt) {
      res = get(pos, lt, mt, 2 * vt);
    } else {
      res = get(pos, mt, rt, 2 * vt + 1);
    }
    relax(vt);
    return res;
  }
 
  int get(int pos) {
    int res = get(pos, 0, n, 1);
    //per("GET", pos, ":", res);
    return res;
  }
};
 
int main(){
#ifdef LOCAL
 freopen("F_input.txt", "r", stdin);
 //freopen("K_output.txt", "w", stdout);
#endif
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 
 cin >> n >> q;
 
 DSU dsu(n);
 
 for (int i = 0; i < q; ++i) {
  int v, u, w;
  cin >> v >> u >> w;
  --v, --u;
  if (dsu.uni(v, u)) {
    gr[v].pb({u, w});
    gr[u].pb({v, w});
    res[i] = true;
  } else {
    edges.pb({v, u, w, i});
  }
 }
 
 for (int v = 0; v < n; ++v) {
  if (used[v]) continue;
  dfs(v, -1, 0, 0);
 }
 
 Tree tree(timer);
 
 for (auto e : edges) {
  int v = e.v, u = e.u, w = e.c;
  if ((val[v] ^ val[u] ^ w) != 1) continue;
 
  int l = lca(v, u);
  int he = h[l];
 
  if (tree.get(lt[v]) > he || tree.get(lt[u]) > he) {
    continue;
  }
 
  res[e.id] = true;
 
  while (v != l) {
    tree.add_seg(lt[v], rt[v] + 1, h[v]);
    v = par[v];
  }
  while (u != l) {
    tree.add_seg(lt[u], rt[u] + 1, h[u]);
    u = par[u];
  }
  //tree.add_seg(lt[l], rt[l] + 1, h[l]);
 }
 
 for (int i = 0; i < q; ++i) {
  cout << (res[i] ? "YES\n" : "NO\n");
 }
}