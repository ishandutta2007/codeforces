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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  vector<int> sum(n + 1);
  for (int i = 0; i < n; ++i)
    sum[i + 1] = sum[i] + a[i];
  vector<int> ans;
  auto op = [&](int i) {
    assert(i >= 0 && i + 3 <= n);
    ans.push_back(i + 1);
    int x = a[i] ^ a[i + 1] ^ a[i + 2];
    a[i] = a[i + 1] = a[i + 2] = x;
  };

  int c = -1;

  for (int c1 = 0; c1 < n; ++c1) {
    if (a[c1]) continue;
    if (sum[c1] % 2 == 1) continue;
    if ((sum[n] - sum[c1]) % 2 == 1) continue;
    c = c1;
    break;
  }

  if (c == -1) {
    for (int i = 0; i < n; ) {
      if (a[i]) { ++i; continue; }
      int j = i;
      while (j < n && a[j] == 0) ++j;
      if ((j - i) % 2 == 1) {
        if (i == 0 || j == n) { i = j; continue; }
        for (int x = 0; x < (j - i) / 2; ++x)
          op(j - x * 2 - 2);
        op(i - 1);
        break;
      }
      i = j;
    }
    for (int c1 = 0; c1 < n; ++c1) {
      if (a[c1]) continue;
      if (sum[c1] % 2 == 1) continue;
      if ((sum[n] - sum[c1]) % 2 == 1) continue;
      c = c1;
      break;
    }
    if (c == -1) {
      cout << "NO\n";
      return;
    }
  }

  for (int i = c - 1; i >= 0; --i) {
    if (a[i] == 0) continue;
    assert(i != 0);
    if (a[i - 1] == 1) {
      op(i - 1);
      continue;
    }
    assert(i != 1);
    if (a[i - 2] == 1) {
      op(i - 2);
      continue;
    }
    op(i - 2);
    ++i;
  }
  for (int i = c + 1; i < n; ++i) {
    if (a[i] == 0) continue;
    assert(i != n - 1);
    if (a[i + 1] == 1) {
      op(i - 1);
      continue;
    }
    assert(i != n - 2);
    if (a[i + 2] == 1) {
      op(i);
      continue;
    }
    op(i);
    --i;
  }

  assert(sz(ans) <= n);
  cout << "YES\n" << sz(ans) << "\n" << ans << "\n";
  for (int x : a) assert(!x);
}

int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
  return 0;
}