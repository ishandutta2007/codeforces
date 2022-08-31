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

struct Forge {
  ll tl, tr;
  ll t;
};

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<Forge> fs(n);
  vector<ll> xs;
  for (int i = 0; i < n; ++i) {
    cin >> fs[i].tl >> fs[i].tr >> fs[i].t;
    xs.push_back(fs[i].tl);
    xs.push_back(fs[i].tr);
  }
  sort(all(fs), [](Forge const& x, Forge const& y) { return x.t < y.t; });
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());

  vector<vector<int>> fstarts(sz(xs)), fends(sz(xs));
  int m = sz(xs);
  for (int i = 0; i < n; ++i) {
    fstarts[lower_bound(all(xs), fs[i].tl) - xs.begin()].push_back(i);
    fends[upper_bound(all(xs), fs[i].tr - fs[i].t) - xs.begin()].push_back(i);
  }

  set<int> curf;
  vector<ll> d(m, 0), dw(m, LINF);
  auto upd = [&](int i, ll nd, ll ndw) {
    if (d[i] < nd) {
      d[i] = nd;
      dw[i] = ndw;
    } else if (d[i] == nd) {
      dw[i] = min(dw[i], ndw);
    }
  };
  for (int i = 0; i < m - 1; ++i) {
    auto dodo = [&](ll cd, ll x) {
      if (curf.empty()) {
        upd(i + 1, cd, LINF);
        return;
      }
      ll x2 = xs[i + 1];
      int f = *curf.begin();
      ll t = fs[f].t;
      ll cnt = (x2 - x) / t;
      upd(i + 1, cd + cnt, LINF);
      ll x1 = x + cnt * t;
      if (x1 == x2) return;
      auto it = curf.begin();
      while (it != curf.end()) {
        f = *it;
        if (x1 + fs[f].t <= fs[f].tr) {
          upd(i + 1, cd + cnt, x1 + fs[f].t);
          break;
        }
        ++it;
      }
    };

    for (int j : fstarts[i])
      curf.insert(j);
    for (int j : fends[i])
      curf.erase(j);

    dodo(d[i], xs[i]);
    if (dw[i] < xs[i + 1])
      dodo(d[i] + 1, dw[i]);
    else if (dw[i] == xs[i + 1])
      upd(i + 1, d[i] + 1, LINF);
    else
      upd(i + 1, d[i], dw[i]);
  }

  cout << d[m - 1] << "\n";

  return 0;
}