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

const int N = 404;

int n, mod;

int main() {
  ios::sync_with_stdio(false);

  cin >> n >> mod;
  ++n;

  static int cc[N][N];
  for (int i = 0; i < N; ++i) {
    cc[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      cc[i][j] = (cc[i-1][j-1] + cc[i-1][j]) % mod;
  }

  static int w[N];
  for (int i = 1; i < N; ++i)
    for (int j = 0; j < i; ++j)
      w[i] = (w[i] + cc[i-1][j]) % mod;

  static int d[N][N];
  d[0][0] = 1;
  for (int cn = 2; cn <= n; ++cn)
    for (int k = 1; k < cn; ++k)
      for (int x = 1; x <= min(cn - 1, k); ++x)
        d[cn][k] = (d[cn][k] + d[cn - x - 1][k - x] * 1LL * w[x] % mod * cc[k][x]) % mod;

  int ans = 0;
  for (int i = 0; i <= n; ++i)
    (ans += d[n][i]) %= mod;
  cout << ans << "\n";


  return 0;
}