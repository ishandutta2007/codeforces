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
  DSU() = default;
  explicit DSU(int n) : p(n, -1) {}
  
  int get(int v) { return p[v] == -1 ? v : p[v] = get(p[v]); }
  bool merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    p[y] = x;
    return true;
  }
};

vector<int> solve(vector<int> const& a, vector<int> const& b) {
  int n = sz(a);
  DSU dsu(n);
  vector<int> p(n);
  vector<vector<int>> psA(n + 1), psB(n + 1);
  for (int i = 0; i < n; ++i) psA[a[i]].push_back(i);
  for (int i = 0; i < n; ++i) psB[b[i]].push_back(i);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j < sz(psA[i]); ++j) {
      p[psA[i][j]] = psB[i][j];
      dsu.merge(psA[i][j], psB[i][j]);
    }

  for (int i = 0; i <= n; ++i)
    for (int j = 0; j < sz(psA[i]) - 1; ++j) {
      int v1 = psA[i][j], v2 = psA[i][j + 1];
      if (dsu.merge(v1, v2))
        swap(p[v1], p[v2]);
    }

  return p;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  vector<vector<int>> ps(n + 1);
  for (int i = 0; i < n; ++i) {
    ps[a[i]].push_back(i);
  }
  int cnt1 = 0;
  for (int i = 0; i <= n; ++i)
    if (sz(ps[i]) % 2 == 1)
      ++cnt1;
  if (cnt1 > 1) {
    cout << "NO\n";
    return;
  }
  DSU dsu(n);

  for (int i = 0; i < n; ++i)
    dsu.merge(i, n - 1 - i);
  for (auto const& pp : ps)
    for (int i = 0; i < sz(pp) - 1; ++i)
      dsu.merge(pp[i], pp[i + 1]);

  vector<int> b(n, 0);
  for (int i = 0; i <= n; ++i)
    if (sz(ps[i]) % 2 == 1) {
      if (ps[i].back() == n / 2 && sz(ps[i]) == 1) {
        cout << "NO\n";
        return;
      }
      b[n / 2] = i;
      dsu.merge(n / 2, ps[i].back());
      ps[i].pop_back();
      break;
    }

  int pos1 = -1;
  set<int> was;
  for (int i = 0; i < n / 2; ++i) {
    if (was.count(dsu.get(i))) continue;
    was.insert(dsu.get(i));
    int c = a[i];
    if (sz(ps[c]) == 0) {
      c = 0;
      while (!(sz(ps[c]) > 0 && dsu.get(ps[c][0]) == dsu.get(i))) ++c;
    }
    if (pos1 != -1) {
      b[pos1] = c;
      b[n - pos1 - 1] = c;
      ps[c].pop_back();
      ps[c].pop_back();
    }
    pos1 = i;
  }

  int j = 0;
  for (int i = 0; i < n / 2; ++i)
    if (b[i] == 0) {
      while (ps[j].empty()) ++j;
      ps[j].pop_back();
      ps[j].pop_back();
      b[i] = b[n - 1 - i] = j;
    }

  cout << "YES\n";
  vector<int> p = solve(b, a);
  for (int x : p) cout << x + 1 << " ";
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}