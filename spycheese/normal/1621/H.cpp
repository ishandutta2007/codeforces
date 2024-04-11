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

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int n;
  cin >> n;
  vector<vector<pair<int, ll>>> e(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    ll c;
    cin >> x >> y >> c;
    --x;
    --y;
    e[x].push_back({y, c});
    e[y].push_back({x, c});
  }

  int k;
  string z;
  cin >> k >> z;

  vector<ll> pass(k), fine(k);
  cin >> pass >> fine;


  ll t;
  cin >> t;

  vector<ll> dist(n);
  vector<int> nxt(n);
  vector<int> pred(n);

  function<void(int, int, int, ll)> dfs = [&](int v, int pv, int cnxt, ll cdist) {
    pred[v] = pv;
    dist[v] = cdist;
    nxt[v] = cnxt;
    for (int i = 0; i < sz(e[v]); ++i) {
      if (e[v][i].X == pv) {
        e[v][i] = e[v].back();
        e[v].pop_back();
        --i;
        continue;
      }
      int nv = e[v][i].X;
      dfs(nv, v, z[v] == z[nv] ? cnxt : nv, cdist + e[v][i].Y);
    }
  };
  dfs(0, -1, 0, 0);

  vector<int> cch(n, -1);

  int qq;
  cin >> qq;
  for (int ii = 0; ii < qq; ++ii) {
    int type;
    cin >> type;
    if (type == 1) {
      string i;
      ll c;
      cin >> i >> c;
      pass[i[0] - 'A'] = c;
    } else if (type == 2) {
      string i;
      ll c;
      cin >> i >> c;
      fine[i[0] - 'A'] = c;
    } else {
      int u;
      cin >> u;
      --u;
      if (z[u] == 'A') {
        cout << "0\n";
        continue;
      }
      int v = pred[nxt[u]];

      vector<lpair> es;

      while (v > 0) {
        ll dr = dist[v];
        ll dl = (nxt[v] == 0 ? 1 : dist[pred[nxt[v]]] + 1);

        int zi = z[v] - 'A';
        ll cnt1 = (dr - dl) / t + 1;
        ll cnt0 = cnt1 - 1;
        ll cost1 = min((__int128)pass[zi], (__int128)cnt1 * fine[zi]);
        ll cost0 = min((__int128)pass[zi], (__int128)cnt0 * fine[zi]);

        if ((dr - dl + 1) % t == 0)
          es.push_back({0, cost1});
        else {
          ll cl = dl % t, cr = (dr + 1) % t;
          if (cl <= cr) {
            es.push_back({0, cost0});
            es.push_back({cl, cost1 - cost0});
            es.push_back({cr, cost0 - cost1});
          } else {
            es.push_back({0, cost1});
            es.push_back({cr, cost0 - cost1});
            es.push_back({cl, cost1 - cost0});
          }
        }

        v = pred[nxt[v]];
      }

      es.push_back({t, 0});
      es.push_back({0, 0});
      sort(all(es));
      int ii = 0;
      for (int j = 0; j < sz(es); ++j) {
        if (ii == 0 || es[j].X != es[ii - 1].X)
          es[ii++] = es[j];
        else
          es[ii - 1].Y += es[j].Y;
      }
      es.resize(ii);

      function<int(int)> dfs2 = [&](int v) {
        if (cch[v] != -1) return cch[v];
        int ans = 0;
        for (auto nv : e[v])
          if (z[nv.X] == z[v])
            ans |= dfs2(nv.X);
        ans |= (1 << (lowerBound(es, {dist[v] % t, LINF}) - 1));
        return cch[v] = ans;
      };

      ll ans = LINF;
      ll csum = 0;
      int mask = dfs2(u);
      for (int i = 0; i < sz(es); ++i) {
        csum += es[i].Y;
        if ((1 << i) & mask)
          ans = min(ans, csum);
      }
      cout << ans << "\n";
    }
  }

  return 0;
}