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
 
int main() {
  // srand(time(0));
  ios::sync_with_stdio(false); cin.tie(0);
  int sx, n;
  cin >> sx >> n;
  vector<int> a(n);
  cin >> a;
 
  int ansL = -1, ansR = -1;
  auto go = [&](int sl, int sr) -> bool {
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
      l += sl;
      r += sr;
      int cl, cr;
      if (i == n - 1)
        cl = cr = sx;
      else {
        cl = a[i];
        cr = a[i + 1];
      }
      if (r < cl || l > cr) return false;
      l = max(l, cl);
      r = min(r, cr);
    }
    if (ansL == -1 || ansR - ansL > sr - sl) {
      ansL = sl;
      ansR = sr;
    }
    return true;
  };
 
  auto calc = [&](int sl) -> int {
    int cl = sl - 1, cr = sx + 1;
    while (cr - cl > 1) {
      int mid = (cl + cr) / 2;
      if (go(sl, mid))
        cr = mid;
      else
        cl = mid;
    }
    if (cr == sx + 1)
      return IINF;
    return cr - sl;
  };
 
  int l1 = 1, l2 = sx + 1;
  calc(l1);
  while (l2 - l1 > 1) {
    int mid = (l1 + l2) / 2;
    if (calc(mid) != IINF)
      l1 = mid;
    else
      l2 = mid;
  }
 
  vector<ipair> ss;
  int l = 0, r = 0;
  for (int i = 0; i < n; ++i) {
    ss.push_back({l, r});
    l += ansL;
    r += ansR;
    int cl, cr;
    if (i == n - 1)
      cl = cr = sx;
    else {
      cl = a[i];
      cr = a[i + 1];
    }
    l = max(l, cl);
    r = min(r, cr);
  }
  int x = sx;
  vector<int> ans = {x};
  while (!ss.empty()) {
    ipair s = ss.back();
    ss.pop_back();
    int l = x - ansR, r = x - ansL;
    if (s.X <= l && l <= s.Y)
      x = l;
    else if (s.X <= r && r <= s.Y)
      x = r;
    else
      x = s.X;
    ans.push_back(x);
  }

 
  reverse(all(ans));
  for (int i = 0; i < sz(ans) - 1; ++i)
    cout << ans[i] << " " << ans[i + 1] << "\n";
 
  return 0;
}