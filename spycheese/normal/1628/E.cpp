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

const int D = 20;

struct Node {
  int val;
  int p[D];
  vector<int> e;
  int tin, tout;
  Node() {
    val = -1;
    memset(p, -1, sizeof(p));
  }
};
vector<Node> vs;

struct DSU {
  vector<int> p;
  DSU() = default;
  explicit DSU(int n) : p(n, -1) {}
  
  int get(int v) { return p[v] == -1 ? v : p[v] = get(p[v]); }
  bool merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    p[y] = x;
    return true;
  }
};

int tt = 0;
int n;
void dfs(int v) {
  vs[v].tin = tt;
  if (v < n) ++tt;
  for (int i = 1; i < D && vs[v].p[i - 1] != -1; ++i)
    vs[v].p[i] = vs[vs[v].p[i - 1]].p[i - 1];
  for (int nv : vs[v].e)
    dfs(nv);
  vs[v].tout = tt;
}

struct TNode {
  typedef int value_type;

  int min = IINF;
  int max = -IINF;
  int emin = IINF;
  int emax = -IINF;

  int set = 0;
  bool haveSet = false;

  void setX(int x) {
    min = max = x;
  }

  void doSet(int x, int cl, int cr) {
    haveSet = 1;
    set = x;
    if (x) {
      emin = min;
      emax = max;
    } else {
      emin = IINF;
      emax = -IINF;
    }
  }

  void update(TNode const &l, TNode const &r, int cl, int cr) {
    max = std::max(l.max, r.max);
    emax = std::max(l.emax, r.emax);
    min = std::min(l.min, r.min);
    emin = std::min(l.emin, r.emin);
  }

  void push(TNode &l, TNode &r, int cl, int cr) {
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
public:
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
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int q;
  cin >> n >> q;
  vs.reserve(n * 2);
  vs.resize(n);
  
  DSU dsu(n);
  vector<int> vv(n);
  iota(all(vv), 0);
  vector<pair<int, ipair>> es;
  for (int i = 0; i < n - 1; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    es.push_back({z, {x - 1, y - 1}});
  }
  sort(all(es));
  for (auto const& e : es) {
    int x = e.Y.X;
    int y = e.Y.Y;
    int x1 = vv[dsu.get(x)];
    int y1 = vv[dsu.get(y)];
    int z = sz(vs);
    vs.emplace_back();
    vs.back().val = e.X;
    vs.back().e = {x1, y1};
    vs[x1].p[0] = z;
    vs[y1].p[0] = z;
    dsu.merge(x, y);
    vv[dsu.get(x)] = z;
  }

  int root = sz(vs) - 1;
  dfs(root);

  SegTree<TNode> st(n);
  for (int i = 0; i < n; ++i)
    st.withLeaf(i, [&](TNode &v) { v.setX(vs[i].tin); });

  for (int ii = 0; ii < q; ++ii) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      cin >> l >> r;
      --l;
      st.withSeg(l, r, [&](TNode& v, int cl, int cr) { v.doSet(1, cl, cr); });
    } else if (type == 2) {
      int l, r;
      cin >> l >> r;
      --l;
      st.withSeg(l, r, [&](TNode& v, int cl, int cr) { v.doSet(0, cl, cr); });
    } else {
      int v0;
      cin >> v0;
      --v0;
      int t1 = st.t[0].emin;
      int t2 = st.t[0].emax;
      if (t1 == IINF || (t1 == t2 && t1 == vs[v0].tin)) {
        cout << "-1\n";
      } else {
        for (int i = D - 1; i >= 0; --i) {
          int v1 = vs[v0].p[i];
          if (v1 == -1) continue;
          if (t1 < vs[v1].tin || t2 >= vs[v1].tout)
            v0 = v1;
        }
        v0 = vs[v0].p[0];
        cout << vs[v0].val << "\n";
      }
    }
  }

  return 0;
}