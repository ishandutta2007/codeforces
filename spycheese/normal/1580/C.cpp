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

const int SS = 440;
const int N = 200111;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ipair> ts(n);
  cin >> ts;
  struct Seg {
    int l, r;
    int x, y;
  };
  vector<Seg> segs;
  vector<int> t2s(n, -1);
  for (int i = 0; i < m; ++i) {
    int o, t;
    cin >> o >> t;
    --t;
    if (o == 1) {
      t2s[t] = sz(segs);
      segs.push_back({i, m, ts[t].X, ts[t].Y});
    } else {
      segs[t2s[t]].r = i;
      t2s[t] = -1;
    }
  }

  static int ansS[N];
  static vector<int> smalls[SS];
  for (int j = 0; j < sz(segs); ++j) {
    Seg const &s = segs[j];
    int p = s.x + s.y;
    if (p >= SS) {
      for (int i = s.l + s.x; i < s.r; i += p) {
        ansS[i]++;
        ansS[min(s.r, i + s.y)]--;
      }
    } else {
      smalls[p].push_back(j);
    }
  }

  static int ans[N];

  for (int p = 2; p < SS; ++p) {
    if (smalls[p].empty()) continue;
    static int ansSS[N * 2];
    memset(ansSS, 0, sizeof(int) * (m + 1));
    for (int si : smalls[p]) {
      Seg const& s = segs[si];
      int l = s.l + s.x;
      int r = s.r;
      if (l >= r) continue;
      int y = s.y;
      y = min(r - l, y);
      int j = l + divCeil(r - l, p) * p;
      for (int i = l; i < l + y; ++i) {
        ansSS[i]++;
        ansSS[j]--;
        ++j;
        if (j >= r + p) j -= p;
      }
    }
    for (int i = 0; i < m; ++i) {
      ans[i] += ansSS[i];
      if (i + p < m)
        ansSS[i + p] += ansSS[i];
    }
  }

  int cans = 0;
  for (int i = 0; i < m; ++i) {
    cans += ansS[i];
    cout << cans + ans[i] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  //cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
  return 0;
}