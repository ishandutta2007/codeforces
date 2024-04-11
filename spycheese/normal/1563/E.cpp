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

template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }

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
    f = false;
    out << x;
  }
  return out;
}

template<typename T> bool isZero(T const& x) { return x == T(0); }
bool isZero(float x) { return abs(x) < EPS; }
bool isZero(double x) { return abs(x) < EPS; }
bool isZero(long double x) { return abs(x) < EPS; }
template<typename T> int sgn(T const& x) { if (isZero(x)) return 0; return x > 0 ? 1 : -1; }

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> e(n);
  vector<int> a(n), b(n);
  for (int i = 1; i < n; ++i)
    cin >> a[i];
  for (int i = 1; i < n; ++i)
    cin >> b[i];
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    e[x].push_back(y);
    e[y].push_back(x);
  }

  vector<char> done(n);
  vector<ll> dp(n);
  vector<int> dprv(n);
  vector<int> vis(n);
  auto check = [&](ll s0) {
    fill(all(done), 0);
    done[0] = 1;
    int cdone = 1;
    while (cdone < n) {
      static vector<int> q;
      q.clear();
      fill(all(vis), 0);
      for (int i = 0; i < n; ++i) {
        dp[i] = (done[i] ? s0 : -LINF);
        if (done[i]) {
          q.push_back(i);
          vis[i] = 1;
        }
        dprv[i] = -1;
      }
      int ans1 = -1;
      int ans2 = -1;
      for (int i = 0; i < sz(q) && ans1 == -1; ++i) {
        int v = q[i];
        ll cd = dp[v];
        for (int nv : e[v]) {
          if (done[v] && done[nv]) continue;
          if (dp[nv] != -LINF && nv != dprv[v]) {
            ans1 = v;
            ans2 = nv;
            break;
          }
          if (vis[nv]) continue;
          if (cd <= a[nv]) continue;
          ll nd = cd + b[nv];
          dp[nv] = nd;
          q.push_back(nv);
          vis[nv] = 1;
          dprv[nv] = v;
        }
      }
        if (ans1 == -1) return false;
        int v = ans1;
        while (v != -1) {
          if (!done[v]) {
            done[v] = 1;
            ++cdone;
            s0 += b[v];
          }
          v = dprv[v];
        }
        v = ans2;
        while (v != -1) {
          if (!done[v]) {
            done[v] = 1;
            ++cdone;
            s0 += b[v];
          }
          v = dprv[v];
        }
      }
      return true;
    };

  check(15);

  int cl = 0, cr = *max_element(all(a)) + 1;
  while (cr - cl > 1) {
    int mid = (cl + cr) / 2;
    if (check(mid))
      cr = mid;
    else
      cl = mid;
  }
  cout << cr << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}