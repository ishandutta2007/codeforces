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

const int K = 19;

int ans[K + 1][1 << K];

vector<ipair> go(bool *a, int k) {
  if (k == 0) {
    if (*a)
      return {{0, 0}};
    else
      return {{IINF, IINF}};
  }
  int k1 = k - 1;
  vector<ipair> v0 = go(a, k1);
  vector<ipair> v1 = go(a + (1 << k1), k1);
  vector<ipair> v(1 << k);
  for (int i = 0; i < 1 << k1; ++i) {
    ans[k][i] = min(ans[k][i], v0[i].Y + v1[i].X + 1);
    v[i].X = (v0[i].X == IINF ? v1[i].X + (1 << k1) : v0[i].X);
    v[i].Y = (v1[i].Y == IINF ? v0[i].Y + (1 << k1) : v1[i].Y);
  }
  for (int i = (1 << k1); i < 1 << k; ++i) {
    int i1 = i - (1 << k1);
    ans[k][i] = min(ans[k][i], v1[i1].Y + v0[i1].X + 1);
    v[i].X = (v1[i1].X == IINF ? v0[i1].X + (1 << k1) : v1[i1].X);
    v[i].Y = (v0[i1].Y == IINF ? v1[i1].Y + (1 << k1) : v0[i1].Y);
  }
  for (auto &p : v) {
    p.X = min(p.X, IINF);
    p.Y = min(p.Y, IINF);
  }
  return v;
}

void solve() {
  int n, k;
  cin >> n >> k;
  memset(ans, 0x3f, sizeof(ans));
  static bool a[1 << K];
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[x] = 1;
  }
  go(a, k);
  for (int i = 0; i < 1 << k; ++i) {
    int x = IINF;
    for (int j = 1; j <= k; ++j)
      x = min(x, ans[j][i & ((1 << j) - 1)]);
    cout << x << " ";
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