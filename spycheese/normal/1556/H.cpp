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
typedef int ll;
typedef unsigned long long ull;
typedef pair<int, int> ipair;
typedef pair <ll, ll> lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = IINF;
const double DINF = numeric_limits<double>::infinity();
const double DNAN = numeric_limits<double>::quiet_NaN();
const double EPS = 1e-9;
const double PI = acos((double)-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
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

const int N = 52;

struct MatroidLimit {
  vector<int> cls, lim;
  vector<vector<int>> classes;
  int n;
  vector<int> ccnt;
  vector<char> contains;

  MatroidLimit(vector<int> cls, vector<int> lim) :
    cls(move(cls)), lim(move(lim)), n(sz(this->cls)), ccnt(sz(this->lim), 0), contains(n, 0) {
    classes.resize(sz(this->lim));
    for (int i = 0; i < n; ++i)
      if (this->cls[i] != -1)
        classes[this->cls[i]].push_back(i);
  }

  void add(int x) {
    contains[x] = 1;
    int c = cls[x];
    if (c == -1) return;
    ++ccnt[c];
  }

  void remove(int x) {
    contains[x] = 0;
    int c = cls[x];
    if (c == -1) return;
    --ccnt[c];
  }

  void update() {}

  bool canAdd(int x) {
    int c = cls[x];
    return !contains[x] && (c == -1 || ccnt[c] < lim[c]);
  }

  void getEdgesFrom(vector<vector<int>> &ee) {
    for (auto const& c : classes)
      for (int i : c) {
        if (!contains[i]) continue;
        for (int j : c) {
          if (contains[j]) continue;
          ee[i].push_back(j);
        }
      }
  }
};

struct MatroidForest {
  vector<ipair> e;
  int vn, n;
  vector<char> contains;

  vector<vector<ipair>> e1;
  vector<int> comp, dep;
  vector<ipair> pred;

  MatroidForest(vector<ipair> e, int vn, vector<ipair> fixedE = {}) :
    e(move(e)), vn(vn), n(sz(this->e)), contains(n, 0), e1(vn) {
    for (ipair const& p : fixedE) {
      e1[p.X].emplace_back(p.Y, -1);
      e1[p.Y].emplace_back(p.X, -1);
    }
    update();
  }

  void add(int x) {
    contains[x] = 1;
    int v1 = e[x].X, v2 = e[x].Y;
    e1[v1].push_back({v2, x});
    e1[v2].push_back({v1, x});
  }

  void remove(int x) {
    contains[x] = 0;
  }

  void dfs(int v, int cc, int cdep) {
    dep[v] = cdep;
    comp[v] = cc;
    for (int i = 0; i < sz(e1[v]); ++i) {
      int ei = e1[v][i].Y;
      if (ei != -1 && !contains[ei]) {
        e1[v][i] = e1[v].back();
        e1[v].pop_back();
        --i;
        continue;
      }
      int nv = e1[v][i].X;
      if (comp[nv] != -1) continue;
      pred[nv] = {v, ei};
      dfs(nv, cc, cdep + 1);
    }
  }

  void update() {
    comp.resize(vn);
    pred.resize(vn);
    dep.resize(vn);
    fill(all(comp), -1);
    int cc = 0;
    for (int i = 0; i < vn; ++i) {
      if (comp[i] != -1) continue;
      dfs(i, cc++, 0);
    }
  }

  bool canAdd(int x) {
    return comp[e[x].X] != comp[e[x].Y];
  }

  void getEdgesTo(vector<vector<int>> &ee) {
    for (int i = 0; i < n; ++i) {
      if (contains[i]) continue;
      int v1 = e[i].X, v2 = e[i].Y;
      if (comp[v1] == comp[v2]) {
        while (v1 != v2) {
          if (dep[v1] < dep[v2]) swap(v1, v2);
          if (pred[v1].Y != -1) ee[i].push_back(pred[v1].Y);
          v1 = pred[v1].X;
        }
      }
    }
  }
};

int matroidIntersect(MatroidLimit &mat1, MatroidForest &mat2) {
  assert(mat1.n == mat2.n);
  int ansN = 0;
  int n = mat1.n;
  vector<int> vs(n);
  vector<int> q;
  vector<vector<int>> e(n);
  while (true) {
    fill(all(vs), -1);
    q.clear();
    for (int i = 0; i < n; ++i) e[i].clear();
    mat1.getEdgesFrom(e);
    mat2.getEdgesTo(e);
    for (int i = 0; i < n; ++i)
      if (mat1.canAdd(i)) {
        vs[i] = -2;
        q.push_back(i);
      }
    int av = -1;
    for (int i = 0; i < sz(q); ++i) {
      int v = q[i];
      if (mat2.canAdd(v)) {
        av = v;
        break;
      }
      for (int nv : e[v]) {
        if (vs[nv] == -1) {
          q.push_back(nv);
          vs[nv] = v;
        }
      }
    }
    if (av == -1) break;
    ++ansN;
    int v = av;
    bool add = 1;
    while (v >= 0) {
      if (!add) {
        mat1.remove(v);
        mat2.remove(v);
      }
      v = vs[v];
      add = !add;
    }
    v = av;
    add = 1;
    while (v >= 0) {
      if (add) {
        mat1.add(v);
        mat2.add(v);
      }
      v = vs[v];
      add = !add;
    }
    mat1.update();
    mat2.update();
  }
  return ansN;
}

pair<int, ll> matroidIntersectW(MatroidLimit &mat1, MatroidForest &mat2, vector<ll> const& w) {
  assert(mat1.n == mat2.n);
  ll ansW = 0;
  int ansN = 0;
  int n = mat1.n;
  vector<pair<ll, int>> vs(n);
  vector<pair<ll, int>> nvs(n);
  vector<int> q1, q2;
  vector<vector<int>> e(n);
  while (true) {
    fill(all(vs), make_pair(LINF, -1));
    q1.clear();
    q2.clear();
    for (int i = 0; i < n; ++i) e[i].clear();
    mat1.getEdgesFrom(e);
    mat2.getEdgesTo(e);
    for (int i = 0; i < n; ++i)
      if (mat1.canAdd(i)) {
        vs[i].X = 0;
        q1.push_back(i);
      }
    int av = -1;
    ll ad = LINF;
    bool sgn = 0;
    for (int iter = 0; !q1.empty() && iter < n; ++iter) {
      copy(all(vs), nvs.begin());
      for (int v : q1) {
        ll cd = vs[v].X + (sgn ? -w[v] : w[v]);
        if (cd == LINF) continue;
        for (int nv : e[v]) {
          if (cd < nvs[nv].X) {
            if (nvs[nv].X == vs[nv].X) q2.push_back(nv);
            nvs[nv] = {cd, v};
          }
        }
        if (mat2.canAdd(v) && cd < ad) {
          ad = cd;
          av = v;
        }
      }
      swap(vs, nvs);
      swap(q1, q2);
      q2.clear();
      sgn = !sgn;
    }
    if (av == -1) break;
    ++ansN;
    int v = av;
    bool add = 1;
    while (v != -1) {
      if (!add) {
        mat1.remove(v);
        mat2.remove(v);
        ansW -= w[v];
      }
      v = vs[v].Y;
      add = !add;
    }
    v = av;
    add = 1;
    while (v != -1) {
      if (add) {
        mat1.add(v);
        mat2.add(v);
        ansW += w[v];
      }
      v = vs[v].Y;
      add = !add;
    }
    mat1.update();
    mat2.update();
  }
  return {ansN, ansW};
}

int n, k;
int e[N][N];
vector<ipair> es;
int deg0[5];
int comp0[5];

ll solve(vector<ipair> const& fixedE) {
  MatroidForest mat1(es, n, fixedE);
  vector<int> cls(sz(es), -1);
  for (int i = 0; i < sz(es); ++i)
    if (min(es[i].X, es[i].Y) < k)
      cls[i] = min(es[i].X, es[i].Y);
  MatroidLimit mat2(cls, vector<int>(deg0, deg0 + k));
  vector<ll> w;
  for (int i = 0; i < sz(es); ++i)
    w.push_back(e[es[i].X][es[i].Y]);
  auto ans = matroidIntersectW(mat2, mat1, w);
  return ans.X == n - 1 - sz(fixedE) ? ans.Y : LINF;
}

struct DSU {
  vector<int> p;
  DSU() = default;
  DSU(int n) : p(n, -1) {}
  
  int get(int v) { return p[v] == -1 ? v : p[v] = get(p[v]); }
  bool merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    p[y] = x;
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < k; ++i)
    cin >> deg0[i];
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      cin >> e[i][j];
      e[j][i] = e[i][j];
    }

  for (int i = 0; i < k; ++i)
    for (int j = k; j < n; ++j)
      es.push_back({i, j});
  DSU dsu(n);
  vector<ipair> order;
  for (int i = k; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      order.push_back({i, j});
  sort(all(order), [](ipair const& a, ipair const& b) { return e[a.X][a.Y] < e[b.X][b.Y]; });
  for (ipair const& a : order) {
    if (dsu.merge(a.X, a.Y)) {
      es.push_back(a);
    }
  }

  ll ans = LINF;
  for (int mask = 0; mask < (1 << (k * (k - 1) / 2)); ++mask) {
    if (__builtin_popcount(mask) >= k) continue;
    iota(comp0, comp0 + k, 0);
    int curI = 0;
    int cdeg[5];
    memset(cdeg, 0, sizeof(cdeg));
    ll cans = 0;
    vector<ipair> fixedE;
    for (int i = 0; i < k; ++i)
      for (int j = 0; j < i; ++j) {
        if (mask & (1 << curI)) {
          cans += e[i][j];
          fixedE.push_back({i, j});
          ++cdeg[i];
          ++cdeg[j];
          int ci = comp0[i], cj = comp0[j];
          if (ci == cj) goto fail;
          replace(comp0, comp0 + k, ci, cj);
        }
        ++curI;
      }
    for (int i = 0; i < k; ++i)
      if (cdeg[i] > deg0[i])
        goto fail;

    for (int i = 0; i < k; ++i)
      deg0[i] -= cdeg[i];
    ans = min(ans, cans + solve(fixedE));
    for (int i = 0; i < k; ++i)
      deg0[i] += cdeg[i];
    fail:;
  }

  cout << ans << "\n";

  return 0;
}