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
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }

template<typename T>
istream & operator >> (istream &in, vector<T> &a) {
  for (T& x : a) in >> x;
  return in;
}

template<typename T>
ostream & operator << (ostream &out, vector<T> const& a) {
  bool f = true;
  for (T const& x : a) {
    if (!f) {
      out << ' ';
    } 
    f = false;
    out << x;
  }
  return out;
}

// ========================================================================= //

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), ar(n);
  cin >> a;
  for (int &x : a) --x;
  for (int i = 0; i < n; ++i)
    ar[a[i]] = i;
  vector<int> b(m);
  cin >> b;
  for (int &x : b) --x;

  vector<int> c(n, -1);
  for (int i = 0; i < m; ++i) {
    c[ar[b[i]]] = i;
  }

  int ans = 1;
  for (int i = 0; i < n; ++i) {
    if (c[i] == -1) {
      continue;
    }
    int v = 0;
    if (i != 0 && c[i-1] < c[i]) ++v;
    if (i != n-1 && c[i+1] < c[i]) ++v;
    ans = (ans * v) % MOD;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }


  return 0;
}