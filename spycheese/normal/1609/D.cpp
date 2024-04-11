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
template<typename T> T pw(T a, ll b) { T r = T(1); for (; b > 0; b >>= 1) { if (b & 1) r *= a; a *= a; } return r; }

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

struct DSUs {
  vector<int> p;
  vector<int> s;
  DSUs() = default;
  explicit DSUs(int n) : p(n, -1), s(n, 1) {}
  
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

void solve() {
  int n, d;
  cin >> n >> d;
  DSUs dsu(n);
  multiset<int> ss1, ss2;
  for (int i = 0; i < n - 1; ++i)
    ss1.insert(1);
  ss2.insert(1);
  int cans = 1;
  int ccnt = 1;
  auto upd = [&]() {
    while (!ss1.empty() && !ss2.empty()) {
      int x1 = *ss1.rbegin(), x2 = *ss2.begin();
      if (x1 > x2) {
        cans -= x2;
        ss2.erase(ss2.find(x2));
        ss1.insert(x2);
      } else break;
    }
    while (sz(ss2) > ccnt) {
      int x = *ss2.begin();
      cans -= x;
      ss2.erase(ss2.find(x));
      ss1.insert(x);
    }
    while (sz(ss2) < ccnt && !ss1.empty()) {
      int x = *ss1.rbegin();
      cans += x;
      ss1.erase(ss1.find(x));
      ss2.insert(x);
    }
  };
  for (int i = 0; i < d; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    if (dsu.get(x) != dsu.get(y)) {
      if (ss1.count(dsu.getSize(x)))
        ss1.erase(ss1.find(dsu.getSize(x)));
      else {
        cans -= dsu.getSize(x);
        ss2.erase(ss2.find(dsu.getSize(x)));
      }
      if (ss1.count(dsu.getSize(y)))
        ss1.erase(ss1.find(dsu.getSize(y)));
      else {
        cans -= dsu.getSize(y);
        ss2.erase(ss2.find(dsu.getSize(y)));
      }
      dsu.merge(x, y);
      ss1.insert(dsu.getSize(x));
      upd();
    } else {
      ++ccnt;
      upd();
    }
    cout << cans - 1 << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t = 1;
  //cin >> t;
  while (t--) solve();
  return 0;
}