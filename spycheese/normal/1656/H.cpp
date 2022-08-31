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

typedef __int128_t int128;
typedef __uint128_t uint128;

istream& operator >>(istream &in, int128 &a) {
  a = 0; string s; in >> s;
  bool sign = !s.empty() && s[0] == '-';
  for (int i = sign; i < sz(s); ++i) a = a * (uint128)10 + (uint128)(s[i] - '0');
  return in;
}
istream& operator >>(istream &in, uint128 &a) {
  a = 0; string s; in >> s;
  bool sign = !s.empty() && s[0] == '-';
  for (int i = sign; i < sz(s); ++i) a = a * (uint128)10 + (uint128)(s[i] - '0');
  return in;
}
ostream& operator <<(ostream &out, uint128 a) {
  if (a == 0) return out << '0';
  string s; while (a) { s += '0' + a % 10; a /= 10; }
  reverse(all(s)); return out << s;
}
ostream& operator <<(ostream &out, int128 a) {
  if (a < 0) return out << '-' << -(uint128)a;
  return out << (uint128)a;
}

int128 gcd(int128 a, int128 b) { return b ? gcd(b, a % b) : a; }
int128 lcm(int128 a, int128 b) { return a / gcd(a, b) * b; }

struct Node {
  typedef int128 value_type;

  int128 x = 1;

  void setX(int128 x) {
    this->x = x;
  }

  void update(Node const &l, Node const &r, int cl, int cr) {
    x = lcm(l.x, r.x);
  }

  void push(Node &l, Node &r, int cl, int cr) {
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
  int t;
  cin >> t;
  while (t--) {
    int na, nb;
    cin >> na >> nb;
    vector<int128> a(na), b(nb);
    cin >> a >> b;
    vector<SegTree<Node>> ta, tb;
    for (int i = 0; i < na; ++i)
      ta.push_back(SegTree<Node>(nb, [&](Node &v, int j) { v.setX(gcd(a[i], b[j])); }));
    for (int i = 0; i < nb; ++i)
      tb.push_back(SegTree<Node>(na, [&](Node &v, int j) { v.setX(gcd(a[j], b[i])); }));

    vector<char> ua(na, 1), ub(nb, 1);

    auto delA = [&](int i) {
      ua[i] = 0;
      for (int j = 0; j < nb; ++j)
        if (ub[j])
          tb[j].withLeaf(i, [&](Node &v) { v.setX(1); });
    };
    auto delB = [&](int i) {
      ub[i] = 0;
      for (int j = 0; j < na; ++j)
        if (ua[j])
          ta[j].withLeaf(i, [&](Node &v) { v.setX(1); });
    };

    while (true) {
      bool deld = false;
      for (int i = 0; i < na; ++i)
        if (ua[i] && a[i] != ta[i].t[0].x) {
          delA(i);
          deld = 1;
        }
      for (int i = 0; i < nb; ++i)
        if (ub[i] && b[i] != tb[i].t[0].x) {
          delB(i);
          deld = 1;
        }
      if (!deld)
        break;
    }

    int sa = 0, sb = 0;
    for (int i = 0; i < na; ++i)
      sa += ua[i];
    for (int i = 0; i < nb; ++i)
      sb += ub[i];
    if (sa == 0 || sb == 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << sa << " " << sb << "\n";
      for (int i = 0; i < na; ++i)
        if (ua[i])
          cout << a[i] << " ";
      cout << "\n";
      for (int i = 0; i < nb; ++i)
        if (ub[i])
          cout << b[i] << " ";
      cout << "\n";
    }
  }
  return 0;
}