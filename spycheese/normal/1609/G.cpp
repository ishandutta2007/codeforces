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

template<typename T>
struct Fen {
  vector<T> t;
  Fen() = default;
  explicit Fen(int n) : t(n, T(0)) {}
  void add(int p, T x) { for (; p < sz(t); p |= p + 1) t[p] += x; }
  T sum(int p) { T s = 0; for (p = min(p, sz(t)) - 1; p >= 0; p = (p&(p+1))-1) s += t[p]; return s; }
  T sum(int l, int r) { return l < r ? sum(r) - sum(l) : T(0); }

  int lowerBound(T x) {
    if (x <= T(0)) return 0;
    int y = 0;
    for (int i = 31 - __builtin_clz(sz(t)); i >= 0; --i) {
      int y1 = y + (1 << i);
      if (y1 <= sz(t) && x > t[y1 - 1]) {
        x -= t[y1 - 1];
        y = y1;
      }
    }
    return y + 1;
  }
};

struct Node {
  typedef ll value_type;

  ll add = 0;
  ll addD = 0;

  void doAdd(ll a) {
    add += a;
  }

  void doAddD(ll a) {
    addD += a;
  }

  void update(Node const &l, Node const &r, int cl, int cr) {
  }

  void push(Node &l, Node &r, int cl, int cr) {
    int mid = (cl + cr) / 2;
    if (add) {
      l.doAdd(add);
      r.doAdd(add);
      add = 0;
    }
    if (addD) {
      l.doAddD(addD);
      r.doAddD(addD);
      r.doAdd(addD * (mid - cl));
      addD = 0;
    }
  }
};

template<typename V>
class SegTree {
  int gl, gr;
  vector<V> t;

  void update(int c, int cl, int cr) {
    V &v = t[c];
    V &v1 = t[c * 2 + 1];
    V &v2 = t[c * 2 + 2];
    v.update(v1, v2, cl, cr);
  }

  void push(int c, int cl, int cr) {
    V &v = t[c];
    V &v1 = t[c * 2 + 1];
    V &v2 = t[c * 2 + 2];
    v.push(v1, v2, cl, cr);
  }

public:
  SegTree() = default;

  template<typename F>
  SegTree(int gl, int gr, F const& init) : gl(gl), gr(gr), t((gr - gl) * 4)  {
    build(0, gl, gr, init);
  }

  template<typename F>
  SegTree(int n, F const& init) : SegTree(0, n, init)  {
  }

  SegTree(int gl, int gr) : SegTree(gl, gr, [](V&, int) {}) {}
  explicit SegTree(int n) : SegTree(n, [](V&, int) {}) {}

  template<typename F>
  void build(int c, int cl, int cr, F const& init) {
    if (cl + 1 == cr) {
      init(t[c], cl);
    } else {
      int mid = (cl + cr) / 2;
      build(c * 2 + 1, cl, mid, init);
      build(c * 2 + 2, mid, cr, init);
      update(c, cl, cr);
    }
  }

  V const& getLeaf(int p) {
    int c = 0, cl = gl, cr = gr;
    while (cr - cl > 1) {
      push(c, cl, cr);
      int mid = (cl + cr) / 2;
      if (p < mid) {
        c = c * 2 + 1;
        cr = mid;
      } else {
        c = c * 2 + 2;
        cl = mid;
      }
    }
    return t[c];
  }

  template<typename F>
  void withLeaf(int p, F const& foo) { withLeaf(p, foo, 0, gl, gr); }

  template<typename F>
  void withLeaf(int p, F const& foo, int c, int cl, int cr) {
    if (cl + 1 == cr) {
      foo(t[c]);
    } else {
      push(c, cl, cr);
      int mid = (cl + cr) / 2;
      if (p < mid)
        withLeaf(p, foo, c * 2 + 1, cl, mid);
      else
        withLeaf(p, foo, c * 2 + 2, mid, cr);
      update(c, cl, cr);
    }
  }

  template<typename F>
  void withSeg(int l, int r, F const& foo) { withSeg(l, r, foo, 0, gl, gr); }

  template<typename F>
  void withSeg(int l, int r, F const& foo, int c, int cl, int cr) {
    if (cl >= r || l >= cr) return;
    if (l <= cl && cr <= r) {
      foo(t[c], cl, cr);
      return;
    }
    push(c, cl, cr);
    int mid = (cl + cr) / 2;
    withSeg(l, r, foo, c * 2 + 1, cl, mid);
    withSeg(l, r, foo, c * 2 + 2, mid, cr);
    update(c, cl, cr);
  }
};

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<ll> a(n), b(m);
  cin >> a >> b;
  ll sumAB = 0;
  for (ll x : a) sumAB += x;
  for (ll x : b) sumAB += x;

  ll b0 = b[0], bm = b[m - 1];

  Fen<ll> bdd(m - 1);
  for (int i = 0; i < m - 1; ++i)
    bdd.add(i, (b[i + 1] - b[i]) - (i == 0 ? 0LL : b[i] - b[i - 1]));
  SegTree<Node> bst(m, [&](Node &v, int i) { v.doAdd(b[i]); });

  auto solve = [&]() -> ll {
    ll ans = sumAB + a[0] * (m - 1);
    for (int i = 1; i < n; ++i) {
      ll ad = a[i] - a[i - 1];
      int j = bdd.lowerBound(ad + 1) - 1;
      j = max(1, j);
      j = min(j, m - 2);
      ans += min({b0 + (m - 1) * ad, bm, bst.getLeaf(j).add + (m - 1 - j) * ad});
    }
    return ans;
  };
  for (int ii = 0; ii < q; ++ii) {
    int type, k;
    ll d;
    cin >> type >> k >> d;
    sumAB += d * k * (k + 1) / 2;
    if (type == 1) {
      k = n - k;
      for (int i = k; i < n; ++i)
        a[i] += d * (i - k + 1);
    } else {
      bm += k * d;
      k = m - k;
      if (k == 0) b0 += d;
      bdd.add(max(0, k - 1), d);
      bst.withSeg(k, m, [&](Node &v, int cl, int) {
        v.doAddD(d);
        v.doAdd(d * (cl - k + 1));
      });
    }
    cout << solve() << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t = 1;
  //cin >> t;
  while (t--) solve();
  return 0;
}