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
const int MOD = 1000000007;
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

// ========================================================================= //

const int N = 80;

int n, k;
int e[N][N];
ipair e2[N][N][N];
int w, ans;
vector<int> dd = {0};
bool csn[N];

void go() {
  {
    static int e3[5][5];
    for (int i = 0; i < sz(dd); ++i)
      for (int j = 0; j < sz(dd); ++j) {
        int v1 = dd[i], v2 = dd[j];
        int q = 0;
        while (csn[e2[v1][v2][q].second]) ++q;
        e3[i][j] = e2[v1][v2][q].first;
      }
    static int d[6][5];
    memset(d, 0x3f, sizeof(d));
    d[0][0] = 0;
    for (int i = 0; i < w; ++i)
      for (int v = 0; v < sz(dd); ++v)
        for (int nv = 0; nv < sz(dd); ++nv)
          d[i + 1][nv] = min(d[i + 1][nv], d[i][v] + e3[v][nv]);
    ans = min(ans, d[w][0]);
  }
  if (sz(dd) == w) return;
  for (int i = dd.back() + 1; i < n; ++i) {
    if (!csn[i]) {
      csn[i] = 1;
      dd.push_back(i);
      go();
      dd.pop_back();
      csn[i] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> e[i][j];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      int v = 0;
      for (int q = 0; q < n; ++q)
        if (q != i && q != j)
          e2[i][j][v++] = {e[i][q] + e[q][j], q};
      sort(e2[i][j], e2[i][j] + v);
    }

  w = k / 2;
  ans = IINF;
  csn[0] = 1;
  go();
  cout << ans << "\n";

  return 0;
}