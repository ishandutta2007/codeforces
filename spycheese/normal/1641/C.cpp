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
template<typename T> T pw(T a, ll b) { T r = T(1); if (b <= 0) return r; for (;; b >>= 1) { if (b & 1) r *= a; if (b) a *= a; else return r; } }

template<typename T> void unique(vector<T> &a) { sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> int lowerBound(vector<T> const& a, T const& x) { return lower_bound(all(a), x) - a.begin(); }
template<typename T> int upperBound(vector<T> const& a, T const& x) { return upper_bound(all(a), x) - a.begin(); }

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

struct Node {
  typedef ll value_type;

  ll max = 0;
  ll min = 0;

  ll set = 0;
  bool haveSet = false;

  void setX(ll x) {
    max = min = x;
  }

  void doSet(ll x, int cl, int cr) {
    haveSet = 1;
    set = x;
    max = x;
    min = x;
  }

  void update(Node const &l, Node const &r, int cl, int cr) {
    max = std::max(l.max, r.max);
    min = std::min(l.min, r.min);
  }

  void push(Node &l, Node &r, int cl, int cr) {
    int mid = (cl + cr) / 2;
    if (haveSet) {
      l.doSet(set, cl, mid);
      r.doSet(set, mid, cr);
      haveSet = 0;
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

  template<typename F>
  void forEach(F const& foo) { forEach(gl, gr, foo); }

  template<typename F>
  void forEach(int l, int r, F const& foo) { forEach(l, r, foo, 0, gl, gr); }

  template<typename F>
  void forEach(int l, int r, F const& foo, int c, int cl, int cr) {
    if (cl >= r || l >= cr) return;
    if (cl + 1 == cr) {
      foo(t[c], cl);
      return;
    }
    push(c, cl, cr);
    int mid = (cl + cr) / 2;
    forEach(l, r, foo, c * 2 + 1, cl, mid);
    forEach(l, r, foo, c * 2 + 2, mid, cr);
    update(c, cl, cr);
  }

  typename V::value_type getSum(int l, int r) { return getSum(l, r, 0, gl, gr); }

  typename V::value_type getSum(int l, int r, int c, int cl, int cr) {
    if (cl >= r || l >= cr) return 0;
    if (l <= cl && cr <= r)
      return t[c].sum;
    push(c, cl, cr);
    int mid = (cl + cr) / 2;
    return getSum(l, r, c * 2 + 1, cl, mid) + getSum(l, r, c * 2 + 2, mid, cr);
  }

  typename V::value_type getMin(int l, int r) { return getMin(l, r, 0, gl, gr); }

  typename V::value_type getMin(int l, int r, int c, int cl, int cr) {
    if (cl >= r || l >= cr) return numeric_limits<typename V::value_type>::max();
    if (l <= cl && cr <= r)
      return t[c].min;
    push(c, cl, cr);
    int mid = (cl + cr) / 2;
    return min(getMin(l, r, c * 2 + 1, cl, mid), getMin(l, r, c * 2 + 2, mid, cr));
  }

  typename V::value_type getMax(int l, int r) { return getMax(l, r, 0, gl, gr); }

  typename V::value_type getMax(int l, int r, int c, int cl, int cr) {
    if (cl >= r || l >= cr) return numeric_limits<typename V::value_type>::lowest();
    if (l <= cl && cr <= r)
      return t[c].max;
    push(c, cl, cr);
    int mid = (cl + cr) / 2;
    return max(getMax(l, r, c * 2 + 1, cl, mid), getMax(l, r, c * 2 + 2, mid, cr));
  }

  void add(int l, int r, typename V::value_type x) { return add(l, r, x, 0, gl, gr); }

  void add(int l, int r, typename V::value_type x, int c, int cl, int cr) {
    if (cl >= r || l >= cr) return;
    if (l <= cl && cr <= r) {
      t[c].doAdd(x, cl, cr);
      return;
    }
    push(c, cl, cr);
    int mid = (cl + cr) / 2;
    add(l, r, x, c * 2 + 1, cl, mid);
    add(l, r, x, c * 2 + 2, mid, cr);
    update(c, cl, cr);
  }

  int nextLeq(int p, typename V::value_type x) { return nextLeq(p, x, 0, gl, gr); }

  int nextLeq(int p, typename V::value_type x, int c, int cl, int cr) {
    if (cr <= p || t[c].min > x) return gr;
    if (cl + 1 == cr) return cl;
    push(c, cl, cr);
    int mid = (cl + cr) / 2;
    int res = nextLeq(p, x, c * 2 + 1, cl, mid);
    if (res != gr) return res;
    return nextLeq(p, x, c * 2 + 2, mid, cr);
  }

  int prevLeq(int p, typename V::value_type x) { return prevLeq(p, x, 0, gl, gr); }

  int prevLeq(int p, typename V::value_type x, int c, int cl, int cr) {
    if (cl > p || t[c].min > x) return gl - 1;
    if (cl + 1 == cr) return cl;
    push(c, cl, cr);
    int mid = (cl + cr) / 2;
    int res = prevLeq(p, x, c * 2 + 2, mid, cr);
    if (res != gl - 1) return res;
    return prevLeq(p, x, c * 2 + 1, cl, mid);
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q;
  cin >> n >> q;

  SegTree<Node> healthy(n);
  SegTree<Node> illSegs(n, [&](Node &v, int) { v.setX(IINF); });

  for (int ii = 0; ii < q; ++ii) {
    int type;
    cin >> type;
    if (type == 0) {
      int l, r, x;
      cin >> l >> r >> x;
      --l;
      if (x == 0) {
        healthy.withSeg(l, r, [&](Node& v, int cl, int cr) { v.doSet(1, cl, cr); });
      } else {
        illSegs.withLeaf(l, [&](Node& v) { v.setX(min<ll>(v.min, r)); });
      }
    } else {
      int i;
      cin >> i;
      --i;
      if (healthy.getLeaf(i).max) {
        cout << "NO\n";
        continue;
      }
      int l = max(-1, healthy.prevLeq(i - 1, 0));
      int r = min(n, healthy.nextLeq(i + 1, 0));
      if (illSegs.getMin(l + 1, i + 1) <= r)
        cout << "YES\n";
      else
        cout << "N/A\n";
    }
  }

  return 0;
}