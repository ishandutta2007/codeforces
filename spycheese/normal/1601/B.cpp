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

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  cin >> a >> b;
  ++n;
  a.insert(a.begin(), 0);
  b.insert(b.begin(), 0);

  set<int> rem;
  for (int i = 0; i < n - 1; ++i)
    rem.insert(i);
  vector<int> q = {n - 1};
  vector<int> dp(n, -1);
  dp[n - 1] = -2;
  for (int qi = 0; qi < sz(q); ++qi) {
    int v = q[qi];
    int v2 = min(n - 1, v + b[v]);
    int v1 = max(0, v2 - a[v2]);
    while (true) {
      auto it = rem.lower_bound(v1);
      if (it == rem.end() || *it >= v2) break;
      q.push_back(*it);
      dp[*it] = v;
      rem.erase(it);
    }
  }

  if (dp[0] == -1) {
    cout << "-1\n";
    return 0;
  }
  vector<int> ans;
  int v = 0;
  while (v >= 0) {
    ans.push_back(v);
    v = dp[v];
  }
  ans.pop_back();
  reverse(all(ans));
  cout << sz(ans) << "\n";
  cout << ans << "\n";

  return 0;
}