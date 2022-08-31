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

template<typename K, typename V> V getOrDef(map<K, V> const& a, K const& k, V const& def = V()) { auto it = a.find(k); return it == a.end() ? def : it->second; }
template<typename K, typename V> V getOrDef(unordered_map<K, V> const& a, K const& k, V const& def = V()) { auto it = a.find(k); return it == a.end() ? def : it->second; }

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

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  DSU dsu(n);
  vector<vector<int>> e(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    if (dsu.merge(x, y)) {
      e[x].push_back(y);
      e[y].push_back(x);
    }
  }
  int qn;
  cin >> qn;
  vector<ipair> qs(qn);
  vector<int> cnt(n, 0);
  for (ipair &p : qs) {
    cin >> p;
    --p.X;
    --p.Y;
    ++cnt[p.X];
    ++cnt[p.Y];
  }

  int odd = 0;
  for (int x : cnt)
    odd += x % 2;
  if (odd != 0) {
    cout << "NO\n";
    cout << odd / 2 << "\n";
    return 0;
  }
  cout << "YES\n";
  for (ipair const& p : qs) {
    int v1 = p.X, v2 = p.Y;
    vector<int> s;
    function<bool(int, int)> dfs = [&](int v, int pv) -> bool {
      s.push_back(v);
      if (v == v2) return true;
      for (int nv : e[v])
        if (nv != pv && dfs(nv, v))
          return true;
      s.pop_back();
      return false;
    };
    dfs(v1, -1);
    cout << sz(s) << "\n";
    for (int x : s)
      cout << x + 1 << " ";
    cout << "\n";
  }
  return 0;
}