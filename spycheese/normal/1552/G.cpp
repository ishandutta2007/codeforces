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

void solve() {
  int n, k;
  cin >> n >> k;
  vector<lpair> as = {{0, 0}};
  vector<lpair> nas;
  as.reserve(10000000);
  nas.reserve(10000000);
  for (int i = 0; i < k; ++i) {
    ll x = 0;
    int len = 0;
    cin >> len;
    for (int jj = 0; jj < len; ++jj) {
      int y;
      cin >> y;
      x |= (1LL << (y - 1));
    }

    nas.clear();
    for (lpair const& ap : as) {
      ll mask0 = ap.X, mask1 = ap.Y;
      int c0 = __builtin_popcountll(mask0 & x);
      int c1 = __builtin_popcountll(mask1 & x);
      mask0 &= ~x;
      mask1 &= ~x;
      ll xx = x;
      for (int i = 0; len - i >= c1; ++i) {
        if (i >= c0) {
          nas.push_back({mask0 | (x ^ xx), mask1 | xx});
        }
        if (!xx) break;
        xx ^= (1LL << __builtin_ctzll(xx));
      }
    }
    swap(as, nas);
  }

  for (auto const& p : as) {
    ll mask0 = p.X;
    ll mask1 = p.Y;
    int cnt0 = __builtin_popcountll(mask0);
    int cnt1 = __builtin_popcountll(mask1);
    if (mask0 != (1LL << cnt0) - 1) {
      cout << "REJECTED\n";
      return;
    }
    if (mask1 != ((1LL << cnt1) - 1) << (n - cnt1)) {
      cout << "REJECTED\n";
      return;
    }
    if (cnt0 + cnt1 < n - 1) {
      cout << "REJECTED\n";
      return;
    }
  }

  cout << "ACCEPTED\n";
}

int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}