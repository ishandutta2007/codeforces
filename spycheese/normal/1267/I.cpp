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
mt19937 mmtw(time(nullptr) + 123312226);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }

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
    f = false;
    out << x;
  }
  return out;
}

template<typename T> bool isZero(T const& x) { return x == T(0); }
bool isZero(float x) { return abs(x) < EPS; }
bool isZero(double x) { return abs(x) < EPS; }
bool isZero(long double x) { return abs(x) < EPS; }
template<typename T> int sgn(T const& x) { if (isZero(x)) return 0; return x > 0 ? 1 : -1; }

void solve() {
  int n;
  cin >> n;
  vector<string> chc(n * 2, string(n * 2, ' '));
  auto cmp = [&](int x, int y) -> bool {
    char c;
    if (chc[x][y] != ' ') c = chc[x][y];
    else {
      cout << "? " << x + 1 << " " << y + 1 << "\n";
      cout.flush();
      string s;
      cin >> s;
      c = s[0];
      chc[x][y] = c;
    }
    return c == '>';
  };

  vector<int> ord(n * 2);
  iota(all(ord), 0);
  for (int i = 0; i < n * 2; ++i)
    swap(ord[i], ord[rnd(i, n * 2 - 1)]);
  vector<ipair> ps;
  for (int i = 0; i < n; ++i) {
    int x = ord[i * 2], y = ord[i * 2 + 1];
    if (!cmp(x, y)) swap(x, y);
    ps.push_back({x, y});
  }
  if (n == 3) {
    sort(all(ps), [&](ipair x, ipair y) { return cmp(x.Y, y.Y); });
    int b = ps[0].Y;
    int c = ps[1].X, d = ps[2].X;
    if (!cmp(c, d)) swap(c, d);
    cmp(b, d);
  } else if (n == 4) {
    sort(all(ps), [&](ipair x, ipair y) { return cmp(x.Y, y.Y); });
    int c = ps[2].X, d = ps[3].X;
    if (!cmp(c, d)) swap(c, d);
    if (cmp(ps[1].Y, d)) {
      cmp(ps[1].Y, c);
    } else {
      cmp(ps[0].Y, d);
      cmp(ps[1].X, d);
      cmp(ps[1].X, ps[0].Y);
    }
  } else if (n == 5) {
    sort(all(ps), [&](ipair x, ipair y) { return cmp(x.Y, y.Y); });
    int a[3] = {ps[2].X, ps[3].X, ps[4].X};
    sort(a, a + 3, [&](int x, int y) { return cmp(x, y); });
    int b[5] = {a[1], a[2], ps[0].Y, ps[1].X, ps[1].Y};
    for (int i = 0; i < 5; ++i)
      for (int j = 0; j < i; ++j)
        cmp(b[i], b[j]);
  } else {
    while (!ps.empty()) {
      sort(all(ps), [&](ipair x, ipair y) { return cmp(x.Y, y.Y); });
      ps[0].X = ps.back().X;
      if (!cmp(ps[0].X, ps[0].Y)) swap(ps[0].X, ps[0].Y);
      ps.pop_back();
    }
  }

  cout << "!\n";
  cout.flush();
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}