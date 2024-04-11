#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ipair;
typedef pair <ll, ll> lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double DINF = numeric_limits<double>::infinity();
const double DNAN = numeric_limits<double>::quiet_NaN();
const double EPS = 1e-9;
const double PI = acos((double)-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

template<typename T, typename M> T& updMin(T& a, M const& b) { if (b < a) a = b; return a; }
template<typename T, typename M> T& updMax(T& a, M const& b) { if (a < b) a = b; return a; }

ll divFloor(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? a / b : (a - b + 1) / b; }
ll divCeil(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? (a + b - 1) / b : a / b; }
ll divFloorS(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? (a + b - 1) / b - 1 : a / b - 1; }
ll divCeilS(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? a / b + 1 : (a - b + 1) / b + 1; }
template<typename T> T pw(T a, ll b) { T r = T(1); if (b <= 0) return r; for (;; b >>= 1) { if (b & 1) r *= a; if (b) a *= a; else return r; } }

template<typename T> void unique(vector<T> &a) { sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> int lowerBound(vector<T> const& a, T const& x) { return lower_bound(all(a), x) - a.begin(); }
template<typename T> int upperBound(vector<T> const& a, T const& x) { return upper_bound(all(a), x) - a.begin(); }

template<typename K, typename V> V getOrDef(map<K, V> const& a, K const& k, V const& def = V()) { auto it = a.find(k); return it == a.end() ? def : it->second; }
template<typename K, typename V> V getOrDef(unordered_map<K, V> const& a, K const& k, V const& def = V()) { auto it = a.find(k); return it == a.end() ? def : it->second; }
template<typename T> T getOrDef(vector<T> const& a, int i, T const& def = T()) { return i < 0 || i >= sz(a) ? def : a[i]; }
template<typename T> T getOrDef(vector<vector<T>> const& a, int i, int j, T const& def = T()) { return i < 0 || i >= sz(a) ? def : getOrDef(a[i], j, def); }
template<typename T> T backOrDef(vector<T> const& a, T const& def = T()) { return a.empty() ? def : a.back(); }

template<typename A, typename B> istream& operator >> (istream& in, pair<A, B>& p) { return in >> p.X >> p.Y; }
template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> const& p) { return out << p.X << " " << p.Y; }
template<typename T> istream& operator >> (istream& in, vector<T>& a) { for (T& x : a) in >> x; return in; }
template<typename T> ostream& operator << (ostream& out, vector<T> const& a) {
  bool f = true;
  for (T const& x : a) {
    if (!f) out << " ";
    f = false; out << x;
  }
  return out;
}
template<typename T> ostream& operator << (ostream& out, vector<vector<T>> const& a) {
  for (vector<T> const& x : a) out << x << "\n";
  return out;
}

template<typename T> bool isZero(T const& x) { return x == T(0); }
bool isZero(float x) { return abs(x) < EPS; }
bool isZero(double x) { return abs(x) < EPS; }
bool isZero(long double x) { return abs(x) < EPS; }
template<typename T> int sgn(T const& x) { if (isZero(x)) return 0; return x > 0 ? 1 : -1; }

struct DSU {
  vector<int> p;
  vector<int> s;
  DSU() = default;
  explicit DSU(int n) : p(n, -1), s(n, 1) {}
  
  int get(int v) { return p[v] == -1 ? v : p[v] = get(p[v]); }
  int getSize(int v) { return s[get(v)]; }
  bool merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    p[y] = x;
    s[x] += s[y];
    return true;
  }
};

struct Tree {
  int n;
  vector<vector<ipair>> e;
  vector<int> dep;
  vector<vector<ipair>> dp;
  vector<ipair> tio;
  int ctime;

  explicit Tree(vector<vector<ipair>> e) : n(sz(e)), e(move(e)) {
    dep.resize(n, -1);
    dp.emplace_back(n, ipair(-1, -1));
    ctime = 0;
    tio.resize(n);
    dfs1(0, -1, -1, 0);
  }

  void dfs1(int v, int p, int pw, int cdep) {
    tio[v].X = ctime++;
    dep[v] = cdep;
    int cp = p;
    int cpw = pw;
    for (int i = 0; cp != -1; ++i) {
      if (sz(dp) == i) dp.emplace_back(n, ipair(-1, -1));
      dp[i][v] = {cp, cpw};
      cpw = max(cpw, dp[i][cp].Y);
      cp = dp[i][cp].X;
    }
    ++cdep;
    for (int i = 0; i < sz(e[v]); ++i) {
      int nv = e[v][i].X;
      if (dep[nv] != -1) {
        e[v][i--] = e[v].back();
        e[v].pop_back();
        continue;
      }
      dfs1(nv, v, e[v][i].Y, cdep);
    }
    tio[v].Y = ctime;
  }

  int upMax(int v, int c) {
    int ans = -1;
    for (int i = 0; c; ++i) {
      int m = 1 << i;
      if (c & m) {
        ans = max(ans, dp[i][v].Y);
        c ^= m;
        v = dp[i][v].X;
      }
    }
    return ans;
  }

  bool isAnc(int x, int y) { return tio[x].X <= tio[y].X && tio[y].X < tio[x].Y; }

  int lca(int x, int y) {
    if (isAnc(x, y)) return x;
    for (int i = sz(dp) - 1; i >= 0; --i) {
      int nx = dp[i][x].X;
      if (nx != -1 && !isAnc(nx, y)) x = nx;
    }
    return dp[0][x].X;
  }

  int pathMax(int x, int y) {
    int z = lca(x, y);
    return max(upMax(x, dep[x] - dep[z]), upMax(y, dep[y] - dep[z]));
  }
};

struct Edge0 {
  int x, y;
  ll w;
  int i0;
  vector<ipair> eb;
};

const int N = 200222;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<Edge0> es0(m);
  for (int i = 0; i < m; ++i) {
    cin >> es0[i].x >> es0[i].y >> es0[i].w;
    --es0[i].x;
    --es0[i].y;
    es0[i].i0 = i;
  }
  sort(all(es0), [&](Edge0 const& a, Edge0 const& b) { return a.w < b.w; });
  
  vector<vector<ipair>> e1(n);

  DSU dsu1(n);
  for (int i = 0; i < m; ++i)
    if (dsu1.merge(es0[i].x, es0[i].y)) {
      e1[es0[i].x].push_back({es0[i].y, i});
      e1[es0[i].y].push_back({es0[i].x, i});
    }
  Tree tree1(e1);
  for (Edge0 const& e : es0) {
    es0[tree1.pathMax(e.x, e.y)].eb.push_back({e.x, e.y});
  }

  dsu1 = DSU(n);
  DSU dsu2(n);
  vector<vector<ipair>> e2(n);

  vector<vector<int>> comps2(n);
  for (int i = 0; i < n; ++i)
    comps2[i].push_back(i);

  for (int i = 0; i < m; ++i) {
    int xr = dsu1.get(es0[i].x);
    int yr = dsu1.get(es0[i].y);
    if (xr == yr) continue;
    auto cs1 = move(comps2[xr]);
    auto cs2 = move(comps2[yr]);

    map<ipair, int> ecnts;
    for (ipair p : es0[i].eb) {
      int x = dsu2.get(p.X);
      int y = dsu2.get(p.Y);
      ++ecnts[{x, y}];
      ++ecnts[{y, x}];
    }

    vector<ipair> merges;
    set<int> nmg;
    for (int i = 1; i < sz(cs2); ++i)
      nmg.insert(i);
    for (int v1 : cs1) {
      vector<int> ce;
      for (auto it = ecnts.lower_bound(ipair(v1, -1)); it != ecnts.end() && it->X.X == v1; ++it) {
        int v2 = it->X.Y;
        if (it->Y != 1LL * dsu2.getSize(v1) * dsu2.getSize(v2)) continue;
        ce.push_back(lower_bound(all(cs2), v2) - cs2.begin());
      }
      if (sz(ce) == sz(cs2)) continue;
      for (int i = 0; i <= sz(ce); ++i) {
        int l = (i == 0 ? 0 : ce[i - 1] + 1);
        int r = (i == sz(ce) ? sz(cs2) : ce[i]);
        if (l == r) continue;
        merges.push_back({v1, cs2[l]});
        auto it = nmg.lower_bound(l + 1);
        while (it != nmg.end() && *it < r) {
          merges.push_back({cs2[*it - 1], cs2[*it]});
          it = nmg.erase(it);
        }
      }
    }

    for (ipair p : merges) {
      int x = p.X, y = p.Y;
      if (dsu2.merge(x, y)) {
        e2[x].push_back({y, es0[i].w});
        e2[y].push_back({x, es0[i].w});
      }
    };

    vector<int> ncc;
    for (int x : cs1) ncc.push_back(dsu2.get(x));
    for (int x : cs2) ncc.push_back(dsu2.get(x));
    unique(ncc);
    dsu1.merge(xr, yr);
    comps2[dsu1.get(xr)] = move(ncc);
  }

  Tree tree2(e2);
  vector<int> ans(m);
  for (Edge0 const& e : es0) {
    ans[e.i0] = tree2.pathMax(e.x, e.y);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}