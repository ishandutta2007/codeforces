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

template<typename A, typename B> istream& operator >> (istream& in, pair<A, B>& p) { return in >> p.X >> p.Y; }
template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> const& p) { return out << p.X << " " << p.Y; }

// ========================================================================= //

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  for (int i = 0; i < n; ++i) --a[i];

  vector<vector<int>> eb(n);
  for (int i = 0; i < n; ++i) eb[a[i]].push_back(i);

  vector<int> b(n, -1);
  for (int i = 0; i < n; ++i) {
    if (eb[i].empty()) continue;
    int v = -1;
    for (int c : eb[i])
      if (v == -1 || eb[c].empty())
        v = c;
    b[v] = i;
  }

  vector<int> d1, d2, d12;
  for (int i = 0; i < n; ++i) {
    if (b[i] == -1) {
      if (eb[i].empty()) d12.push_back(i);
      else d1.push_back(i);
    } else if (eb[i].empty())
      d2.push_back(i);
  }

  if (sz(d12) == 1) {
    b[d1.back()] = d12[0];
    b[d12[0]] = d2.back();
    d1.pop_back();
    d2.pop_back();
    for (int i = 0; i < sz(d1); ++i)
      b[d1[i]] = d2[i];
  } else {
    for (int i = 0; i < sz(d1); ++i)
      b[d1[i]] = d2[i];
    for (int i = 0; i < sz(d12); ++i)
      b[d12[i]] = d12[(i + 1) % sz(d12)];
  }

  int ans = 0;
  for (int i = 0; i < n; ++i)
    ans += (a[i] == b[i]);
  cout << ans << "\n";
  for (int x : b) cout << x + 1 << " ";
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}