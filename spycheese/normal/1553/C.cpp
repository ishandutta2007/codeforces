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
  string s;
  cin >> s;
  int ans = 10;
  for (int mask = 0; mask < 1 << 10; ++mask) {
    int a = 0;
    bool fail = false;
    for (int i = 0; i < 10; ++i) {
      int x = !!(mask & (1 << i));
      if (x != s[i] - '0' && s[i] != '?') {
        fail = 1;
        break;
      }
      if (x) a += (i % 2 == 0 ? 1 : -1);
      if (a > 0 && a > (10 - i) / 2) {
        ans = min(ans, i + 1);
        break;
      }
      if (a < 0 && -a > (9 - i) / 2) {
        ans = min(ans, i + 1);
        break;
      }
    }
    if (fail) continue;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}