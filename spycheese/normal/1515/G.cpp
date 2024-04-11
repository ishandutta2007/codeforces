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
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos((double)-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }

template<typename T> istream& operator >> (istream& in, vector<T>& a) { for (T& x : a) in >> x; return in; }
template<typename T> ostream& operator << (ostream& out, vector<T> const& a) {
  bool f = true;
  for (T const& x : a) {
    if (!f) out << " ";
    f = false;
    out << x;
  }
  return out;
}

template<typename A, typename B> istream& operator >> (istream& in, pair<A, B>& p) { return in >> p.X >> p.Y; }
template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> const& p) { return out << p.X << " " << p.Y; }

// ========================================================================= //

int n;

vector<vector<pair<int, ll>>> e, eb;
vector<int> order;
vector<char> vis;
vector<int> comp;

void dfs1(int v) {
  if (vis[v]) return;
  vis[v] = true;
  for (auto const& nv : e[v])
    dfs1(nv.X);
  order.push_back(v);
}

void dfs2(int v, int cc) {
  if (comp[v] != -1) return;
  comp[v] = cc;
  for (auto const& nv : eb[v])
    dfs2(nv.X, cc);
}

vector<ll> val;

ll dfs3(int v, int cc, ll cval) {
  ll ans = 0;
  vis[v] = true;
  val[v] = cval;
  for (auto [nv, l] : e[v]) {
    if (comp[nv] != cc) continue;
    if (vis[nv]) {
      ans = gcd(ans, abs(cval + l - val[nv]));
    } else {
      ans = gcd(ans, dfs3(nv, cc, cval + l));
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);

  int m;
  cin >> n >> m;
  e.resize(n);
  eb.resize(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    ll l;
    cin >> x >> y >> l;
    --x;
    --y;
    e[x].push_back({y, l});
    eb[y].push_back({x, l});
  }

  vis.resize(n);
  for (int i = 0; i < n; ++i)
    dfs1(i);
  comp.resize(n, -1);

  int cc = 0;
  reverse(all(order));
  for (int v : order) {
    if (comp[v] != -1) continue;
    dfs2(v, cc);
    ++cc;
  }

  for (int i = 0; i < n; ++i)
    for (auto const& p : eb[i])
      e[i].push_back({p.X, -p.Y});

  vector<ll> cans(cc, -1);
  fill(all(vis), 0);
  val.resize(n);
  for (int i = 0; i < n; ++i) {
    if (cans[comp[i]] != -1) continue;
    cans[comp[i]] = dfs3(i, comp[i], 0);
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int v;
    ll a, b;
    cin >> v >> a >> b;
    --v;
    ll c = cans[comp[v]];
    bool ok = false;
    if (a == 0)
      ok = true;
    else if (c != 0) {
      c = gcd(c, b);
      ok = (a % c == 0);
    }
    cout << (ok ? "YES" : "NO") << "\n";
  }

  return 0;
}