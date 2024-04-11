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

template<typename T> bool isZero(T const& x) { return x == T(0); }
bool isZero(float x) { return abs(x) < EPS; }
bool isZero(double x) { return abs(x) < EPS; }
bool isZero(long double x) { return abs(x) < EPS; }

template<typename A, typename B> istream& operator >> (istream& in, pair<A, B>& p) { return in >> p.X >> p.Y; }
template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> const& p) { return out << p.X << " " << p.Y; }

// ========================================================================= //

template<typename T>
struct Fen {
  vector<T> t;
  Fen(int n) : t(n, T(0)) {}
  void add(int p, T x) { for (; p < sz(t); p |= p + 1) t[p] += x; }
  T sum(int p) { T s = 0; for (p = min(p, sz(t)) - 1; p >= 0; p = (p&(p+1))-1) s += t[p]; return s; }
  T sum(int l, int r) { return l < r ? sum(r) - sum(l) : T(0); }
};

struct DSU {
  vector<int> p;
  DSU() = default;
  DSU(int n) : p(n, -1) {}
  
  int get(int v) { return p[v] == -1 ? v : p[v] = get(p[v]); }
  bool merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    p[y] = x;
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> a(n), b(m);
  cin >> a >> b;

  vector<int> order(n);
  iota(all(order), 0);
  sort(all(order), [&](int x, int y) { return a[x] < a[y]; });

  DSU dsu(n);
  vector<int> w(n, -1);

  struct Query {
    int x, y;
    int w;
  };
  vector<Query> qs;

  for (int i : order) {
    int j1 = (i == 0 ? -1 : w[dsu.get(i - 1)]);
    int j2 = (i == n - 1 ? -1 : w[dsu.get(i + 1)]);

    if (j1 == -1 && j2 == -1) {
      qs.push_back({a[i], a[i], 1});
    } else if (j1 != -1 && j2 != -1) {
      int x = a[j1], y = a[j2];
      if (x > y) swap(x, y);
      qs.push_back({y, a[i], -1});
    }

    w[i] = i;
    if (j1 != -1 && a[j1] < a[w[i]]) w[i] = j1;
    if (j2 != -1 && a[j2] < a[w[i]]) w[i] = j2;
    if (j1 != -1) dsu.merge(i, j1);
    if (j2 != -1) dsu.merge(i, j2);
  }
  
  ll ans = 0;

  order.resize(m);
  iota(all(order), 0);
  sort(all(order), [&](int x, int y) { return b[x] < b[y]; });
  sort(all(qs), [](Query const& a, Query const& b) { return a.x > b.x; });

  DSU dsu2(m);
  vector<int> w2(m, -1);
  Fen<int> fen(200111);
  int k = 0;
  for (int ii = 0; ii < m; ++ii) {
    int i = order[ii];
    while (k < sz(qs) && qs[k].x + b[i] > x) {
      ans += qs[k].w * fen.sum(x - qs[k].y + 1);
      ++k;
    }

    int j1 = (i == 0 ? -1 : w2[dsu2.get(i - 1)]);
    int j2 = (i == m - 1 ? -1 : w2[dsu2.get(i + 1)]);

    w2[i] = i;
    if (j1 != -1) {
      fen.add(b[j1], -1);
      if (b[j1] < b[w2[i]]) w2[i] = j1;
    }
    if (j2 != -1) {
      fen.add(b[j2], -1);
      if (b[j2] < b[w2[i]]) w2[i] = j2;
    }
    if (j1 != -1) dsu2.merge(i, j1);
    if (j2 != -1) dsu2.merge(i, j2);
    fen.add(b[w2[i]], 1);
  }

  while (k < sz(qs)) {
    ans += qs[k].w * fen.sum(x - qs[k].y + 1);
    ++k;
  }

  cout << ans << "\n";

  return 0;
}