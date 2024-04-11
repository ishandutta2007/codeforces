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

struct Treap {
  static Treap* null;
  static mt19937 rnd;
  const int prior;
  Treap *l, *r;

  int x, y;
  int size;
  int ymax;
  int yadd = 0;

  Treap(nullptr_t) : prior(0), l(this), r(this), size(0), ymax(-IINF) {}
  Treap(int x, int y) : prior(rnd() & INT_MAX), l(null), r(null), x(x), y(y) { update(); }

  void update() {
    if (this == null) return;
    size = l->size + 1 + r->size;
    ymax = max({l->ymax, y, r->ymax}) + yadd;
  }

  void push() {
    if (this == null) return;
    if (yadd) {
      l->yadd += yadd;
      r->yadd += yadd;
      y += yadd;
      yadd = 0;
    }
    l->update();
    r->update();
  }
};
Treap* Treap::null = new Treap(nullptr);
mt19937 Treap::rnd = mt19937(time(nullptr) + 233);

void deleteTree(Treap* t) {
  if (t == Treap::null) return;
  deleteTree(t->l);
  deleteTree(t->r);
  delete t;
}

Treap* merge(Treap* l, Treap* r) {
  if (l == Treap::null) return r;
  if (r == Treap::null) return l;
  if (l->prior > r->prior) {
    l->push();
    l->r = merge(l->r, r);
    l->update();
    return l;
  } else {
    r->push();
    r->l = merge(l, r->l);
    r->update();
    return r;
  }
}

void splitI(Treap* t, int i, Treap*& l, Treap*& r) {
  if (t == Treap::null) { l = r = t; return; }
  t->push();
  if (t->l->size < i) {
    l = t;
    splitI(t->r, i - t->l->size - 1, t->r, r);
  } else {
    r = t;
    splitI(t->l, i, l, t->l);
  }
  t->update();
}

Treap* insertI(Treap* t, Treap* x, int i) {
  if (t == Treap::null) return x;
  if (x->prior > t->prior) {
    splitI(t, i, x->l, x->r);
    x->update();
    return x;
  }
  t->push();
  if (i <= t->l->size)
    t->l = insertI(t->l, x, i);
  else
    t->r = insertI(t->r, x, i - 1 - t->l->size);
  t->update();
  return t;
}

Treap* eraseI(Treap* t, int i) {
  if (t == Treap::null) return t;
  t->push();
  if (t->l->size == i) {
    Treap* res = merge(t->l, t->r);
    delete t;
    return res;
  }
  if (i < t->l->size)
    t->l = eraseI(t->l, i);
  else
    t->r = eraseI(t->r, i - t->l->size - 1);
  t->update();
  return t;
}

Treap* ith(Treap* t, int i) {
  while (t != Treap::null) {
    t->push();
    if (t->l->size == i) return t;
    if (i < t->l->size)
      t = t->l;
    else {
      i -= t->l->size + 1;
      t = t->r;
    }
  }
  return Treap::null;
}

template<typename F> Treap* withIth(Treap* t, int i, F const& foo, bool mod = true) {
  if (t == Treap::null) return t;
  t->push();
  if (t->l->size == i)
    foo(t);
  else if (i < t->l->size)
    withIth(t->l, i, foo);
  else
    withIth(t->r, i - t->l->size - 1, foo);
  if (mod) t->update();
  return t;
}

template<typename F> Treap* withSeg(Treap* t, int l, int r, F const& foo) {
  Treap *t1, *t2, *t3;
  splitI(t, r, t2, t3);
  splitI(t2, l, t1, t2);
  t2 = foo(t2);
  t2->update();
  return merge(t1, merge(t2, t3));
}

template<typename F> Treap* withSegMany(Treap* t, int l, int r, F const& foo, bool mod = true) {
  if (r <= 0 || t->size <= l || t == Treap::null) return t;
  t->push();
  if (l <= 0 && t->size <= r) {
    foo(t, true);
  } else {
    withSegMany(t->l, l, r, foo, mod);
    if (l <= t->l->size && t->l->size < r)
      foo(t, false);
    withSegMany(t->r, l - t->l->size - 1, r - t->l->size - 1, foo, mod);
  }
  if (mod) t->update();
  return t;
}

template<typename F> Treap* forEach(Treap* t, F const& foo, bool mod = true) {
  if (t == Treap::null) return t; 
  t->push();
  forEach(t->l, foo, mod);
  foo(t);
  forEach(t->r, foo, mod);
  if (mod) t->update();
  return t;
}

template<typename F> Treap* lowerBound(Treap* t, F const& foo) {
  Treap* res = Treap::null;
  while (t != Treap::null) {
    t->push();
    if (foo(t)) {
      t = t->l;
      res = t;
    } else
      t = t->r;
  }
  return res;
}

void splitX(Treap* t, int x, Treap*& l, Treap*& r) {
  if (t == Treap::null) { l = r = t; return; }
  t->push();
  if (t->x < x) {
    l = t;
    splitX(t->r, x, t->r, r);
  } else {
    r = t;
    splitX(t->l, x, l, t->l);
  }
  t->update();
}

Treap* insertX(Treap* t, Treap* x) {
  if (t == Treap::null) return x;
  if (x->prior > t->prior) {
    splitX(t, x->x, x->l, x->r);
    x->update();
    return x;
  }
  t->push();
  if (x->x <= t->x)
    t->l = insertX(t->l, x);
  else
    t->r = insertX(t->r, x);
  t->update();
  return t;
}

Treap* eraseX(Treap* t, int x) {
  if (t == Treap::null) return t;
  t->push();
  if (t->x == x) {
    Treap* res = merge(t->l, t->r);
    delete t;
    return res;
  }
  if (x < t->x)
    t->l = eraseX(t->l, x);
  else
    t->r = eraseX(t->r, x);
  t->update();
  return t;
}

bool containsX(Treap* t, int x) {
  while (t != Treap::null) {
    t->push();
    if (t->x == x) return true;
    t = (t->x < x ? t->r : t->l);
  }
  return false;
}

Treap* findX(Treap* t, int x) {
  while (t != Treap::null) {
    t->push();
    if (t->x == x) return t;
    t = (t->x < x ? t->r : t->l);
  }
  return Treap::null;
}

Treap* insertUniqueX(Treap* t, Treap* x) {
  if (t == Treap::null) return x;
  if (x->prior > t->prior) {
    if (containsX(t, x->x)) return t;
    splitX(t, x->x, x->l, x->r);
    x->update();
    return x;
  }
  t->push();
  if (x->x <= t->x)
    t->l = insertX(t->l, x);
  else
    t->r = insertX(t->r, x);
  t->update();
  return t;
}

Treap* lowerBoundX(Treap* t, int x) {
  return lowerBound(t, [&](Treap* b) { return x <= b->x; });
}

template<typename F> Treap* withX(Treap* t, int x, F const& foo, bool mod = true) {
  if (t == Treap::null) return t;
  t->push();
  if (t->x == x)
    foo(t);
  else if (x < t->x)
    withX(t->l, x, foo);
  else
    withX(t->r, x, foo);
  if (mod) t->update();
  return t;
}

template<typename F> Treap* withSegX(Treap* t, int l, int r, F const& foo) {
  Treap *t1, *t2, *t3;
  splitX(t, r, t2, t3);
  splitX(t2, l, t1, t2);
  t2 = foo(t2);
  t2->update();
  return merge(t1, merge(t2, t3));
}
void solve() {
  int n;
  cin >> n;
  vector<int> order(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    order[x] = i;
  }
  if (is_sorted(all(order))) {
    cout << "0\n";
    return;
  }
  int ans = 0;
  Treap *t = Treap::null;
  int j = 0;
  for (int x : order) {
    Treap *t1, *t2;
    splitX(t, x, t1, t2);
    int i = t1->size;
    int y = (x % 2 == 0 ? x - i + 1 : x - i) + t2->size;
    t1->yadd += 1;
    t1->update();
    t2->yadd -= 1;
    t2->update();
    t = merge(t1, merge(new Treap(x, y), t2));
    while (containsX(t, j)) {
      t = withX(t, j, [&](Treap* a) { a->y = -IINF; });
      ++j;
    }
    ans = max(ans, t->ymax);
  }
  cout << ans << "\n";
  deleteTree(t);
}

int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}