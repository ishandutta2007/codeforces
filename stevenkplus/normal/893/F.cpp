// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "{"; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define pp(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

const int inf = 1000 << 20;

// =========== Solution ============= //

const int MAXN = 1 << 17;

vector<int> segs[MAXN * 2];
int segz[MAXN * 2];
vector<pii> data[MAXN * 2];

int vals[MAXN];

vector<int> ed[MAXN];
int depth[MAXN];
int id[MAXN];
int sz[MAXN];
int idcnt = 0;
void dfs(int cur, int prv = -1, int d = 0) {
  id[cur] = ++idcnt;
  sz[cur] = 1;
  depth[cur] = d;
  for (auto i: ed[cur]) {
    if (i == prv) continue;
    dfs(i, cur, d + 1);
    sz[cur] += sz[i];
  }
}

int main() {
  int n, rt;
  cin >> n >> rt;
  for (int i = 1; i <= n; ++i) {
    cin >> vals[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }

  dfs(rt);
  for (int i = 1; i <= n; ++i) {
    pp(i, depth[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = depth[i] + MAXN; j; j /= 2) {
      data[j].push_back(pii(id[i], vals[i]));
    }
  }

  for (int i = 1; i < 2 * MAXN; ++i) {
    vector<pii> &v = data[i];
    segz[i] = 1;
    sort(v.begin(), v.end());
    while (segz[i] < sz(v)) segz[i] *= 2;
    segs[i] = vector<int>(segz[i] * 2);
    for (int j = 0; j < sz(v); ++j) {
      segs[i][j + segz[i]] = v[j].se;
    }
    for (int j = segz[i] - 1; j > 0; --j) {
      segs[i][j] = min(segs[i][j * 2], segs[i][j * 2 + 1]);
    }
  }

  int m;
  cin >> m;
  int last = 0;
  for (int _m = 0; _m < m; ++_m) {
    int p, q;
    cin >> p >> q;
    int x = (p + last) % n + 1;
    int k = (q + last) % n;

    int ans = inf;
    int l = depth[x], r = min(MAXN, depth[x] + k + 1);
    pp(x, k, l, r);
    for (l += MAXN, r += MAXN; l < r; l /= 2, r /= 2) {
      vector<int> v;
      if (l & 1) {
        v.push_back(l++);
      }
      if (r & 1) {
        v.push_back(--r);
      }
      for(auto i: v) {
        pp(i, data[i]);
        int l2 = int(lower_bound(data[i].begin(), data[i].end(), pii(id[x], 0)) - data[i].begin());
        int r2 = int(lower_bound(data[i].begin(), data[i].end(), pii(id[x] + sz[x], 0)) - data[i].begin());
        pp(l2, r2);
        for (l2 += segz[i], r2 += segz[i]; l2 < r2; l2 /= 2, r2 /= 2) {
          if (l2 & 1) {
            pp(segs[i][l2]);
            ans = min(ans, segs[i][l2++]);
          }
          if (r2 & 1) {
            ans = min(ans, segs[i][--r2]);
            pp(segs[i][r2]);
          }
        }
      }
    }
    cout << ans << "\n";
    last = ans;
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN? different MAXN vs MAXM?)
// - special cases (n=1? graph not connected?)
// - initialize & re-initialize efficiently between test cases
//
// history of bugs
// - 3/28/20 forgot to initialize set with dummy node (n) [cf 1136e]
// - 3/28/20 array bounds (map was size MAXN instead of MAXK) [cf 1210b]
// - 3/29/20 array bounds ([MAXN][MAXN][4] -> [MAXN][MAXN * 2][4]) [cf 1051d]
// - 3/29/20 special cases (answer cannot be empty string) [cf 848a]
// - 3/29/20 special case / bad initialization of (ans, ansi) when backtracking [cf 733f]
// - 3/30/20 special case / "0" has length 0 in binary [cf 748b]
// - 4/2/20 fakesolve -- setup of dp states missed possible transitions / solutions [cf 771D]
// - 4/2/20 fakesolve -- cant count inversions in linear time, misunderstand structure of problem [cf 771D]