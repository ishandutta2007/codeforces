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

namespace mincost {
  struct Edge {
    int nv;
    int f, c, w;
  };

  int n;
  vector<Edge> edges;
  vector<vector<int>> e;

  void init(int n) {
    mincost::n = n;
    e.assign(n, vector<int>());
    edges.clear();
  }

  int addEdge(int v1, int v2, int c, int w) {
    e[v1].push_back(sz(edges));
    e[v2].push_back(sz(edges) + 1);
    edges.push_back({v2, 0, c, w});
    edges.push_back({v1, 0, 0, -w});
    return sz(edges) - 2;
  }

  vector<ll> initPsi(int s) {
    vector<ll> dist(n, LINF);
    dist[s] = 0;

    for (int iter = 0; iter < n - 1; ++iter) {
      for (int i = 0; i < sz(edges); ++i) {
        Edge const& edge = edges[i];
        if (edge.c == edge.f) continue;
        int x = edges[i ^ 1].nv;
        int y = edge.nv;
        dist[y] = min(dist[y], dist[x] + edge.w);
      }
    }
    return dist;
  }

  lpair mincost(int s, int t) {
    if (s == t) return {LINF, 0};
    ll flow = 0;
    ll cost = 0;
    vector<ll> psi = initPsi(s);
    vector<ll> dist(n);
    vector<int> prev(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;

    while (true) {
      fill(all(dist), LINF);
      fill(all(prev), -1);
      dist[s] = 0;
      q.emplace(0, s);
      while (!q.empty()) {
        int v = q.top().Y;
        ll cd = q.top().X;
        q.pop();
        if (cd != dist[v]) continue;
        cd += psi[v];
        for (int ei : e[v]) {
          Edge const& edge = edges[ei];
          if (edge.f == edge.c) continue;
          int nv = edge.nv;
          ll nd = cd + edge.w - psi[nv];
          if (nd < dist[nv]) {
            dist[nv] = nd;
            q.emplace(nd, nv);
            prev[nv] = ei;
          }
        }
      }
      if (prev[t] == -1) break;

      for (int i = 0; i < n; ++i)
        if (dist[i] != LINF)
          psi[i] += dist[i];

      int nf = IINF;
      int v = t;
      while (v != s) {
        int ei = prev[v];
        Edge const& edge = edges[ei];
        nf = min(nf, edge.c - edge.f);
        v = edges[prev[v] ^ 1].nv;
      }
      flow += nf;
      v = t;
      while (v != s) {
        int ei = prev[v];
        Edge &edge1 = edges[ei];
        Edge &edge2 = edges[ei ^ 1];
        edge1.f += nf;
        edge2.f -= nf;
        cost += 1LL * nf * edge1.w;
        v = edge2.nv;
      }
    }
    return {flow, cost};
  }

  void clearFlow() {
    for (Edge& edge : edges) edge.f = 0;
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(1 << n);
  cin >> a;
  struct Edge {
    int x, y;
    int c;
  };
  vector<Edge> es;
  es.reserve((1 << n) / 2 * n);
  for (int i = 0; i < (1 << n); ++i) {
    if (__builtin_popcount(i) % 2 == 1) continue;
    for (int j = 0; j < n; ++j)
      es.push_back({i, i ^ (1 << j), a[i] + a[i ^ (1 << j)]});
  }
  int m = min(sz(es), (k - 1) * (2 * n - 1) + 1);
  nth_element(es.begin(), es.begin() + m, es.end(), [&] (Edge const& a, Edge const& b) { return a.c > b.c; });
  vector<int> v2i(1 << n, -1);
  int cnt[2] = {0, 0};
  for (int i = 0; i < m; ++i) {
    int x = es[i].x, y = es[i].y;
    if (v2i[x] == -1) v2i[x] = cnt[0]++;
    if (v2i[y] == -1) v2i[y] = cnt[1]++;
  }

  mincost::init(3 + cnt[0] + cnt[1]);
  mincost::addEdge(0, 1, k, 0);
  mincost::addEdge(1, 2, k, 0);
  for (int i = 0; i < cnt[0]; ++i)
    mincost::addEdge(1, 3 + i, 1, 0);
  for (int i = 0; i < cnt[1]; ++i)
    mincost::addEdge(3 + cnt[0] + i, 2, 1, 0);
  for (int i = 0; i < m; ++i)
    mincost::addEdge(3 + v2i[es[i].x], 3 + cnt[0] + v2i[es[i].y], 1, -es[i].c);
  cout << -mincost::mincost(0, 2).second;

  return 0;
}