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

const int K = 63;

void solve() {
  int n;
  cin >> n;
  vector<ll> aa(n);
  cin >> aa;
  struct Seg {
    ll x;
    int l, r, c;
    int plen;
  };
  struct St {
    vector<Seg> st, stc[K];
    void pop() {
      Seg s = st.back();
      st.pop_back();
      stc[s.c].pop_back();
    }
    void push(ll x, int l, int r, int c) {
      st.push_back({x, l, r, c, -1});
      stc[c].push_back({x, l, r, c, (stc[c].empty() ? 0 : stc[c].back().plen) + r - l});
    }
    int getCnt(int c, int r) {
      int bl = -1, br = sz(stc[c]);
      while (br - bl > 1) {
        auto mid = (bl + br) / 2;
        if (stc[c][mid].l < r)
          bl = mid;
        else
          br = mid;
      }
      if (bl == -1) {
        return 0;
      }
      Seg s = stc[c][bl];
      int ans = s.plen - (s.r - s.l);
      ans += max(0, min(s.r, r) - s.l);
      return ans;
    }
    int getCnt(int c, int l, int r) {
      return getCnt(c, r) - getCnt(c, l);
    }
  };
  int cans = 0;
  auto doPop = [&](St &st1, St &st2) {
    Seg s = st1.st.back();
    cans -= st2.getCnt(s.c, s.l, s.r);
    st1.pop();
  };
  auto doPush = [&](int l, int r, int c, ll x, St &st1, St &st2) {
    st1.push(x, l, r, c);
    cans += st2.getCnt(c, l, r);
  };
  St st1, st2;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll x = aa[i];
    int c = __builtin_popcountll(x);

    while (!st1.st.empty() && st1.st.back().x >= x)
      doPop(st1, st2);
    doPush(st1.st.empty() ? 0 : st1.st.back().r, i + 1, c, x, st1, st2);

    while (!st2.st.empty() && st2.st.back().x <= x)
      doPop(st2, st1);
    doPush(st2.st.empty() ? 0 : st2.st.back().r, i + 1, c, x, st2, st1);

    ans += cans;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t = 1;
  //cin >> t;
  while (t--) solve();
  return 0;
}