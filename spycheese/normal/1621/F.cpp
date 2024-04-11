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

ll solve1(vector<int> const& w0, ll a, ll b, ll c, int t) {
  vector<int> w;
  for (int i = 0; i < sz(w0); i += 2)
    w.push_back(w0[i]);
  int rem1 = 0;
  for (int i = 1; i < sz(w0); i += 2)
    rem1 += max(0, w0[i] - 1);
  ll ans = 0;
  ll cans = 0;
  int i2 = 0;
  vector<int> order;
  for (int i = 1; i < sz(w) - 1; ++i)
    order.push_back(i);
  sort(all(order), [&](int x, int y) { return w[x] < w[y]; });
  order.push_back(0);
  if (sz(w) != 1)
    order.push_back(sz(w) - 1);
  set<int> ones;
  for (int i = 1; i < sz(w) - 1; ++i)
    if (w[i] == 1)
      ones.insert(i);
  for (;; t = !t) {
    ans = max(ans, cans);
    if (t == 1) {
      if (rem1 == 0) break;
      --rem1;
      cans += b;
    } else {
      while (i2 < sz(w) && w[order[i2]] <= 1) ++i2;
      if (i2 < sz(w)) {
        ans = max(ans, cans + a);
      }
      if (rem1 != 0) {
        if (i2 < sz(w)) {
          int i = order[i2];
          --w[i];
          if (w[i] == 1 && i != 0 && i != sz(w) - 1)
            ones.insert(i);
          cans += a;
          continue;
        }
      }
      if (ones.empty()) {
        if (w[0] != 0) {
          --w[0];
          cans -= c;
          continue;
        }
        if (w.back() != 0) {
          --w.back();
          cans -= c;
          continue;
        }
      } else {
        int i = *ones.begin();
        ones.erase(i);
        --w[i];
        cans -= c;
        ++rem1;
        continue;
      }
      break;
    }
  }
  ans = max(ans, cans);
  return ans;
}

void solve() {
  int n;
  ll a, b, c;
  cin >> n >> a >> b >> c;
  string s;
  cin >> s;
  vector<int> w = {0};
  for (char c : s) {
    if (c == '0' + (sz(w) - 1) % 2)
      ++w.back();
    else
      w.push_back(1);
  }
  if (sz(w) % 2 == 0)
    w.push_back(0);
  if (b <= c) {
    int t0 = 0, t1 = 0;
    for (int i = 0; i < sz(w); i += 2)
      t0 += max(0, w[i] - 1);
    for (int i = 1; i < sz(w); i += 2)
      t1 += max(0, w[i] - 1);
    if (t1 == t0)
      cout << t0 * (a + b) << "\n";
    else if (t1 > t0)
      cout << a * t0 + b * (t0 + 1) << "\n";
    else
      cout << a * (t1 + 1) + b * t1 << "\n";
    return;
  }

  cout << max(solve1(w, a, b, c, 0), solve1(w, a, b, c, 1)) << "\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}