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

const int N = 23;

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int sx, sy;
    cin >> sx >> sy;
    static int a1[N][N], a2[N][N], a3[N][N];
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    memset(a3, 0, sizeof(a3));
    auto tr = [&] (int a[N][N], int x, int y) {
      for (int i = x - 1; i <= x + 1; ++i)
        for (int j = y - 1; j <= y + 1; ++j)
          if (i >= 0 && i < sx && j >= 0 && j < sy && a[i][j])
            return 0;
      a[x][y] = 1;
      return 1;
    };

    int h1 = 0, h2 = 0, h3 = 0;
    for (int y = 0; y < sy; ++y) h1 += tr(a1, 0, y);
    for (int x = 0; x < sx; ++x) h1 += tr(a1, x, sy - 1);
    for (int y = sy - 1; y >= 0; --y) h1 += tr(a1, sx - 1, y);
    for (int x = sx - 1; x >= 0; --x) h1 += tr(a1, x, 0);
    for (int y = 1; y < sy; ++y) h2 += tr(a2, 0, y);
    for (int x = 0; x < sx; ++x) h2 += tr(a2, x, sy - 1);
    for (int y = sy - 1; y >= 0; --y) h2 += tr(a2, sx - 1, y);
    for (int x = sx - 1; x >= 0; --x) h2 += tr(a2, x, 0);
    h3 += tr(a3, 1, 0);
    for (int y = 0; y < sy; ++y) h3 += tr(a3, 0, y);
    for (int x = 0; x < sx; ++x) h3 += tr(a3, x, sy - 1);
    for (int y = sy - 1; y >= 0; --y) h3 += tr(a3, sx - 1, y);
    for (int x = sx - 1; x >= 0; --x) h3 += tr(a3, x, 0);

    if (h1 >= h2 && h1 >= h3) {
      for (int i = 0; i < sx; ++i) {
        for (int j = 0; j < sy; ++j)
          cout << a1[i][j];
        cout << "\n";
      }
    } else if (h2 >= h1 && h2 >= h3) {
      for (int i = 0; i < sx; ++i) {
        for (int j = 0; j < sy; ++j)
          cout << a2[i][j];
        cout << "\n";
      }
    } else {
      for (int i = 0; i < sx; ++i) {
        for (int j = 0; j < sy; ++j)
          cout << a3[i][j];
        cout << "\n";
      }
    }
    cout << "\n";
  }
  return 0;
}