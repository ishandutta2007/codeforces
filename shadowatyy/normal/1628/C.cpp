#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)
#define ll LL
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
#define siz(c) SIZ(c)
const int inf = 1e9+7;
const ll INF = 1e18L+7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " =", (x), " "

#ifndef LOCAL
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set =
  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#else
#include</Users/dawid/algo/mac/ordered_set>
#endif

const int N = 1007;

int n;

int g[N][N];
int cnt_diag[2 * N];

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

bool ins(int x, int y) {
  return min(x, y) >= 0 && max(x, y) < n;
}

int diags() {
  for (int d = 0; d <= 2 * n - 2; ++d)
    cnt_diag[d] = 0;

  int acc = 0;
  for (int s = 1; s <= 2 * n - 3; s += 2) {
    debug(I(s));
    if (s < n) {
      for (int d = s - 1; d >= 0; d -= 2) {
        cnt_diag[d] ^= 1;
        debug(I(d));
      }
    } else {
      for (int d = s + 1; d <= 2 * n - 2; d += 2) {
        cnt_diag[d] ^= 1;
        debug(I(d));
      }
    }
  }

  for (int d = 0; d <= 2 * n - 2; ++d) {
    if (cnt_diag[d]) {
      for (int x = max(0, d - n + 1); x <= min(d, n - 1); x += 2) {
        acc ^= g[x][d - x];
        debug(x, d - x);
      }
    }
  }

  return acc;
}

void swap_col() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n - 1 - j; ++j)
      swap(g[i][j], g[i][n - 1 - j]);
  }
}

void solve() {
  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
    }
  }

  int ans = diags();
  swap_col();
  ans ^= diags();
  cout << ans << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--)
    solve();
}