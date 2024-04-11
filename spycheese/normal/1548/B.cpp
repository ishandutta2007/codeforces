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

template<typename T, typename F>
class AccQueue {
  vector<pair<T, T>> l, r;
  F foo;
  T def;
  void ensureLNotEmpty() {
    if (!l.empty()) return;
    while (!r.empty()) {
      T const& x = r.back().first;
      auto acc = l.empty() ? x : foo(x, l.back().second);
      l.emplace_back(move(x), acc);
      r.pop_back();
    }
  }
public:
  explicit AccQueue(F foo, T def = T()) : foo(move(foo)), def(move(def)) {}

  size_t size() const { return l.size() + r.size(); }
  bool empty() const { return l.empty() && r.empty(); }

  void push(T x) {
    T acc = r.empty() ? x : foo(r.back().second, x);
    r.emplace_back(move(x), acc);
  }

  T const& top() const {
    ensureLNotEmpty();
    return l.back();
  }

  bool pop() {
    ensureLNotEmpty();
    if (l.empty()) return false;
    l.pop_back();
    return true;
  }

  T getAcc() {
    if (l.empty() && r.empty()) return def;
    if (l.empty()) return r.back().second;
    if (r.empty()) return l.back().second;
    return foo(l.back().second, r.back().second);
  }
};

template<typename T, typename F>
AccQueue<T, F> accQueue(F foo, T def = T()) {
  return AccQueue<T, F>(move(foo), move(def));
}

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  cin >> a;
  vector<ll> b(n - 1);
  for (int i = 0; i < n - 1; ++i)
    b[i] = abs(a[i] - a[i + 1]);

  auto q = accQueue<ll>([](ll x, ll y) { return gcd(x, y); }, 0LL);
  int ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    while (i + sz(q) < n - 1)
      if (gcd(q.getAcc(), b[i + sz(q)]) != 1)
        q.push(b[i + sz(q)]);
      else
        break;
    ans = max(ans, sz(q));
    if (!q.empty()) q.pop();
  }
  cout << ans + 1 << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}