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

const int N = 100179;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  vector<int> b(n);
  cin >> b;
  sort(all(a), greater<int>());
  sort(all(b), greater<int>());
  vector<int> as(n + 1, 0);
  for (int i = 0; i < n; ++i)
    as[i + 1] = as[i] + a[i];
  vector<int> bs(n + 1, 0);
  for (int i = 0; i < n; ++i)
    bs[i + 1] = bs[i] + b[i];
  int cl = -1, cr = 300000;
  while (cr - cl > 1) {
    int mid = (cl + cr) / 2;
    int k = mid + n;
    int k2 = k - k / 4;
    int him = bs[min(n, k2)];
    int me = 0;
    if (k2 <= mid) me = 100 * k2;
    else me = 100 * mid + as[k2 - mid];
    if (me >= him)
      cr = mid;
    else
      cl = mid;
  }
  cout << cr << "\n";
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