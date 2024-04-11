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
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }

template<typename T>
istream & operator >> (istream &in, vector<T> &a) {
  for (T& x : a) in >> x;
  return in;
}

template<typename T>
ostream & operator << (ostream &out, vector<T> const& a) {
  bool f = true;
  for (T const& x : a) {
    if (!f) {
      out << ' ';
    } 
    f = false;
    out << x;
  }
  return out;
}

// ========================================================================= //

const int N = 200179;
const int D = 19;

int n, m;
vector<int> e[2][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    e[0][x].push_back(y);
    e[1][y].push_back(x);
  }

  int ans = IINF;

  static int d[N];
  
  memset(d, 0x3f, sizeof(d));

  vector<int> pq = {0};
  d[0] = 0;

  for (int iter = 0; iter < D; ++iter) {
    vector<int> q;
    vector<int> nq;
    int ip = 0, i = 0;
    static bool vis[N];
    memset(vis, 0, sizeof(vis));
    while (true) {
      int v = -1;
      if (ip == sz(pq)) {
        if (i == sz(q)) break;
        v = q[i++];
      } else if (i == sz(q)) {
        v = pq[ip++];
      } else {
        if (d[pq[ip]] < d[q[i]]) {
          v = pq[ip++];
        } else {
          v = q[i++];
        }
      }
      if (vis[v]) continue;
      nq.push_back(v);
      vis[v] = 1;

      for (int nv : e[iter&1][v]) {
        if (d[nv] > d[v] + 1) {
          d[nv] = d[v] + 1;
          q.push_back(nv);
        }
      }
    }

    pq = nq;
    ans = min(ans, d[n - 1] + (1 << iter) - 1);
  }

  if (ans != IINF) {
    cout << ans << "\n";
    return 0;
  }

  static ipair d2[2][N];
  memset(d2, 0x3f, sizeof(d2));
  set<pair<ipair, ipair>> q2;
  q2.insert({{0, 0}, {0, 0}});
  d2[0][0] = {0, 0};

  while (!q2.empty()) {
    auto it = q2.begin();
    ipair cd = it->first;
    int l = it->Y.X;
    int v = it->Y.Y;
    q2.erase(it);

    for (int nv : e[l][v]) {
      ipair nd = cd;
      nd.Y++;
      if (d2[l][nv] > nd) {
        q2.erase({d2[l][nv], {l, nv}});
        q2.insert({d2[l][nv] = nd, {l, nv}});
      }
    }

    ipair nd = cd;
    nd.X++;
    if (d2[l^1][v] > nd) {
      q2.erase({d2[l^1][v], {l^1, v}});
      q2.insert({d2[l^1][v] = nd, {l^1, v}});
    }
  }

  ipair res = min(d2[0][n-1], d2[1][n-1]);
  ans = 1;
  for (int i = 0; i < res.X; ++i) {
    ans += ans;
    ans %= MOD;
  }
  ans += res.Y - 1;
  ans %= MOD;
  if (ans < 0) ans += MOD;
  cout << ans << "\n";


  return 0;
}