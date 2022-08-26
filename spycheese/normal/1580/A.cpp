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

template<typename T, typename M> T& updMin(T& a, M const& b) { if (b < a) a = b; return a; }
template<typename T, typename M> T& updMax(T& a, M const& b) { if (a < b) a = b; return a; }

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
    f = false; out << x;
  }
  return out;
}
template<typename T> ostream& operator << (ostream& out, vector<vector<T>> const& a) {
  for (vector<T> const& x : a) out << x << "\n";
  return out;
}

template<typename T> bool isZero(T const& x) { return x == T(0); }
bool isZero(float x) { return abs(x) < EPS; }
bool isZero(double x) { return abs(x) < EPS; }
bool isZero(long double x) { return abs(x) < EPS; }
template<typename T> int sgn(T const& x) { if (isZero(x)) return 0; return x > 0 ? 1 : -1; }

void solve() {
  int sx, sy;
  cin >> sx >> sy;
  vector<string> f(sx);
  cin >> f;
  int ans = IINF;
  for (int x1 = 0; x1 < sx; ++x1) {
    vector<int> cntI(sy), cntO(sy);
    for (int x2 = x1 + 2; x2 < sx; ++x2) {
      for (int y = 0; y < sy; ++y)
        if (f[x2 - 1][y] == '0')
          cntO[y]++;
        else
          cntI[y]++;
      if (x2 - x1 + 1 < 5) continue;
      function<void(int, int)> foo = [&](int l, int r) { 
        if (r - l < 4) return;
        int yy = (l + r) / 2;
        foo(l, yy);
        foo(yy, r);
        int c1[3] = {IINF, IINF, IINF};
        int c2[3] = {IINF, IINF, IINF};
        int cc = 0;
        for (int y = yy - 1; y >= l; --y) {
          updMin(c1[min(2, yy - y - 1)], cc + cntO[y]);
          cc += cntI[y];
          cc += (f[x1][y] == '0');
          cc += (f[x2][y] == '0');
        }
        cc = 0;
        for (int y = yy; y < r; ++y) {
          updMin(c2[min(2, y - yy)], cc + cntO[y]);
          cc += cntI[y];
          cc += (f[x1][y] == '0');
          cc += (f[x2][y] == '0');
        }
        for (int i = 0; i < 3; ++i)
          for (int j = 0; j < 3; ++j)
            if (i + j >= 2)
              ans = min(ans, c1[i] + c2[j]);
      };
      foo(0, sy);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
  return 0;
}