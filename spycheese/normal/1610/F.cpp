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
template<typename T> T pw(T a, ll b) { T r = T(1); for (; b > 0; b >>= 1) { if (b & 1) r *= a; a *= a; } return r; }

template<typename K, typename V> V getOrDef(map<K, V> const& a, K const& k, V const& def = V()) { auto it = a.find(k); return it == a.end() ? def : it->second; }
template<typename K, typename V> V getOrDef(unordered_map<K, V> const& a, K const& k, V const& def = V()) { auto it = a.find(k); return it == a.end() ? def : it->second; }
template<typename T> T getOrDef(vector<T> const& a, int i, T const& def = T()) { return i < 0 || i >= sz(a) ? def : a[i]; }
template<typename T> T getOrDef(vector<vector<T>> const& a, int i, int j, T const& def = T()) { return i < 0 || i >= sz(a) ? def : getOrDef(a[i], j, def); }
template<typename T> T backOrDef(vector<T> const& a, T const& def = T()) { return a.empty() ? def : a.back(); }

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

vector<int> ans, e1i, e2i, es, et, ew;
vector<vector<ipair>> e1, e2;
vector<char> odd1, odd2;

void setAns(int v, ipair nvp) {
  if (v == es[nvp.Y])
    ans[nvp.Y] = 1;
  else
    ans[nvp.Y] = 2;
}

int go(int v, vector<vector<ipair>> const& e, vector<int> &ei, vector<char> &odd) {
  while (true) {
    if (ei[v] == sz(e[v])) return v;
    ipair nvp = e[v][ei[v]++];
    if (ans[nvp.Y]) continue;
    setAns(v, nvp);
    odd[v] ^= 1;
    odd[nvp.X] ^= 1;
    v = nvp.X;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int n, m;
  cin >> n >> m;
  ans.resize(m);
  es.resize(m);
  et.resize(m);
  ew.resize(m);
  e1.resize(n);
  e2.resize(n);
  odd1.resize(n);
  odd2.resize(n);
  e1i.resize(n);
  e2i.resize(n);
  for (int i = 0; i < m; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    --x;
    --y;
    es[i] = x;
    et[i] = y;
    ew[i] = c;
    if (c == 1) {
      e1[x].emplace_back(y, i);
      e1[y].emplace_back(x, i);
    } else {
      e2[x].emplace_back(y, i);
      e2[y].emplace_back(x, i);
    }
  }

  int ansC = 0;
  for (int i = 0; i < n; ++i) {
    ansC += odd1[i] = sz(e1[i]) % 2;
    odd2[i] = sz(e2[i]) % 2;
  }

  for (int iter = 0; iter < 3; ++iter) {
    for (int i = 0; i < n; ++i) {
      int v = i;
      if (iter == 0 && odd1[v] == odd2[v]) continue;
      if (iter == 1 && !odd1[v]) continue;
      if (iter == 2) {
        while (e1i[v] != sz(e1[v])) go(v, e1, e1i, odd1);
        while (e2i[v] != sz(e2[v])) go(v, e2, e2i, odd2);
        continue;
      }
      while (true) {
        if (odd1[v])
          v = go(v, e1, e1i, odd1);
        else if (odd2[v])
          v = go(v, e2, e2i, odd2);
        else
          break;
      }
    }
  }

  cout << ansC << "\n";
  for (int x : ans)
    cout << x;
  cout << "\n";

  return 0;
}