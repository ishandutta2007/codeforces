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

struct Fen {
  vector<ll> t;
  Fen(int n) : t(n, 0) {}

  void add(int p, ll x) {
    for (; p < sz(t); p |= p + 1) t[p] += x;
  }

  ll sum(int p) {
    ll s = 0;
    for (p = min(p, sz(t)) - 1; p >= 0; p = (p&(p+1))-1) s += t[p];
    return s;
  }

  ll sum(int l, int r) {
    return l < r ? sum(r) - sum(l) : 0;
  }
};

const int M = 300111;

void solve() {
  int n;
  cin >> n;
  ll ans = 0;
  ll psum = 0;
  Fen fen1(M), fen2(M);
  
  for (int i = 0; i < n; ++i) {
    ll cans1 = 0, cans2 = 0;
    int a;
    cin >> a;

    for (int b = 0; b < M; b += a)
      cans1 += fen1.sum(b, b + a) * (b / a);
    cans1 = psum - a * cans1;

    cans2 = fen2.sum(a + 1);
    cans2 = 1LL * i * a - cans2;

    ans += cans1 + cans2;
    cout << ans << " ";

    psum += a;
    fen1.add(a, 1);
    for (int b = a; b < M; b += a)
      fen2.add(b, a);
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  //cin >> t;
  while (t--) solve();
  return 0;
}