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

vector<int> sparseD = {0, 0};
void updateSparseD(int n) {
  for (int i = sz(sparseD); i <= n; ++i) {
    int v = sparseD.back();
    if (i >= (1 << (v + 1))) ++v;
    sparseD.push_back(v);
  }
}

template<typename T, typename Cmp = less<T>>
struct Sparse {
  vector<vector<T>> s;
  Cmp cmp;

  T min(T const& a, T const& b) {
    if (cmp(a, b)) return a;
    return b;
  }

  Sparse() : s(1) {}

  Sparse(vector<T> a) {
    int n = sz(a);
    int d = 1;
    while ((1 << d) <= n) ++d;
    s.resize(d);
    s[0] = move(a);
    for (int i = 1; i < d; ++i) {
      s[i].resize(n - (1 << i) + 1);
      for (int j = 0; j < sz(s[i]); ++j)
        s[i][j] = min(s[i-1][j], s[i-1][j + (1 << (i - 1))]);
    }
    updateSparseD(n);
  }

  void push_back(T x) {
    s[0].push_back(move(x));
    int n = sz(s[0]);
    for (int i = 1; (1 << i) <= n; ++i) {
      if (sz(s) == i) s.emplace_back();
      s[i].push_back(min(s[i-1].back(), s[i-1][n - (1 << i)]));
    }
    updateSparseD(n);
  }

  void pop_back() {
    for (auto &v : s) {
      if (v.empty()) break;
      v.pop_back();
    }
  }

  T get(int l, int r) {
    if (l >= r) return numeric_limits<T>::max();
    int d = sparseD[r - l];
    return min(s[d][l], s[d][r - (1 << d)]);
  }
};

struct Node {
  typedef ll value_type;

  ll sum = 0;
  ll add = 0;
  ll addA = 0;

  void setX(ll x) {
    sum = x;
  }

  void doAdd(ll a, int cl, int cr) {
    add += a;
    sum += a * (cr - cl);
  }

  void doAddA(ll a, int cl, int cr) {
    addA += a;
    sum += a * ((cr - cl) * (cr - cl - 1LL) / 2);
  }

  void update(Node const &l, Node const &r, int cl, int cr) {
    sum = l.sum + r.sum;
  }

  void push(Node &l, Node &r, int cl, int cr) {
    int mid = (cl + cr) / 2;
    if (add) {
      l.doAdd(add, cl, mid);
      r.doAdd(add, mid, cr);
      add = 0;
    }
    if (addA) {
      l.doAddA(addA, cl, mid);
      r.doAddA(addA, mid, cr);
      r.doAdd(addA * (mid - cl), mid, cr);
      addA = 0;
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

  int nextGeq(int p, typename V::value_type x) { return nextGeq(p, x, 0, gl, gr); }

  int nextGeq(int p, typename V::value_type x, int c, int cl, int cr) {
    if (cr <= p || t[c].max < x) return gr;
    if (cl + 1 == cr) return cl;
    push(c, cl, cr);
    int mid = (cl + cr) / 2;
    int res = nextGeq(p, x, c * 2 + 1, cl, mid);
    if (res != gr) return res;
    return nextGeq(p, x, c * 2 + 2, mid, cr);
  }

  int prevGeq(int p, typename V::value_type x) { return prevGeq(p, x, 0, gl, gr); }

  int prevGeq(int p, typename V::value_type x, int c, int cl, int cr) {
    if (cl > p || t[c].max < x) return gl - 1;
    if (cl + 1 == cr) return cl;
    push(c, cl, cr);
    int mid = (cl + cr) / 2;
    int res = prevGeq(p, x, c * 2 + 2, mid, cr);
    if (res != gl - 1) return res;
    return prevGeq(p, x, c * 2 + 1, cl, mid);
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q, k;
  cin >> n >> q >> k;
  vector<int> a(n);
  cin >> a;
  Sparse<int> ast(a);

  struct Query {
    int l, cnt;
    ll ans = 0;
  };
  vector<Query> qs(q);
  vector<vector<int>> l2q(n);
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    qs[i].l = l;
    qs[i].cnt = divCeil(r - l, k);
    l2q[l].push_back(i);
  }

  for (int rem = 0; rem < k && rem < n; ++rem) {
    int n2 = (n - rem + k - 1) / k;
    SegTree<Node> sg(n2);
    vector<ipair> sk;
    sk.push_back({-IINF, n2});
    for (int i = n2 - 1; i >= 0; --i) {
      int j = i * k + rem;
      int aa = ast.get(j, min(n, j + k + 1));
      while (sk.back().X >= aa) {
        int ci = sk.back().Y;
        ll caa = -sk.back().X;
        int ci2 = sk[sz(sk) - 2].Y;
        sg.withSeg(ci, ci2, [&](Node &vv, int cl, int cr) {
          vv.doAddA(caa, cl, cr);
          vv.doAdd(caa * (cl - ci + 1LL), cl, cr);
        });
        sg.add(ci2, n2, caa * 1LL * (ci2 - ci));
        sk.pop_back();
      }
      int i2 = sk.back().Y;
      sg.withSeg(i, i2, [&](Node &vv, int cl, int cr) {
        vv.doAddA(aa, cl, cr);
        vv.doAdd(aa * (cl - i + 1LL), cl, cr);
      });
      sg.add(i2, n2, aa * 1LL * (i2 - i));
      sk.push_back({aa, i});
      for (int qi : l2q[j]) {
        Query &qq = qs[qi];
        qq.ans = a[j] + (qq.cnt >= 2 ? sg.getLeaf(i + qq.cnt - 2).sum : 0LL);
      }
    }
  }

  for (int i = 0; i < q; ++i)
    cout << qs[i].ans << "\n";

  return 0;
}