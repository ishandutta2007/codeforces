// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
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

#include <ext/pb_ds/assoc_container.hpp>
// WARNING: functions as a set (doesn't allow duplicates); insert pairs instead if duplicates are needed.
template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
const int inf = 1000 << 20;
// =========== Solution ============= //

typedef ordered_set<int> tree;
const int MAXN = 1 << 18;
// tree seg[MAXN * 2];

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  int size = n + 2;
  vector<tree> bit(size);
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; --x;
    p[x] = i;
  }
  vector<int> v(n);
  for (int &i: v) cin >> i, --i, i = p[i];
  for (int i = 0; i < n; ++i) {
    for (int x = i + 1; x < size; x += x & -x) {
      bit[x].insert(v[i]);
    }
    // for (int x = i + MAXN; x > 0; x /= 2) {
      // seg[x].insert(v[i]);
    // }
  }
  pp(v);
  for (int i = 0; i < m; ++i) {
    int q;
    cin >> q;
    if (q == 1) {
      int lo, hi, l, r;
      cin >> lo >> hi >> l >> r, --lo, --l;
      int ans = 0;
      for (int x = r; x > 0; x &= x - 1) {
        pp(r, x, bit[x].order_of_key(hi) - bit[x].order_of_key(lo));
        ans += bit[x].order_of_key(hi) - bit[x].order_of_key(lo);
      }
      for (int x = l; x > 0; x &= x - 1) {
        pp(l, x, bit[x].order_of_key(hi) - bit[x].order_of_key(lo));
        ans -= bit[x].order_of_key(hi) - bit[x].order_of_key(lo);
      }
      cout << ans << "\n";
    } else {
      int a, b;
      cin >> a >> b; --a; --b;

      // remove a
      // for (int x = a + MAXN; x > 0; x /= 2) {
        // seg[x].erase(v[a]);
      // }
      for (int x = a + 1; x < size; x += x & -x) {
        bit[x].erase(v[a]);
      }
      // remove b
      // for (int x = b + MAXN; x > 0; x /= 2) {
        // seg[x].erase(v[b]);
      // }
      for (int x = b + 1; x < size; x += x & -x) {
        bit[x].erase(v[b]);
      }
      // insert b
      // for (int x = a + MAXN; x > 0; x /= 2) {
        // seg[x].insert(v[b]);
      // }
      for (int x = a + 1; x < size; x += x & -x) {
        bit[x].insert(v[b]);
      }
      //  insert a
      // for (int x = b + MAXN; x > 0; x /= 2) {
        // seg[x].insert(v[a]);
      // }
      for (int x = b + 1; x < size; x += x & -x) {
        bit[x].insert(v[a]);
      }
      swap(v[a], v[b]);
    }
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
// - 4/3/20 (TLE) re-initialization was too slow [cf 1329 D]
// - 4/3/20 (WA) bottom-up segtree query didn't handle [0, n) correctly
// - 4/5/20 array bounds -- two different array sizes needed [cf 18d]
// - 4/5/20 fakesolve -- greedy sol was wrong,  needed dp [cf 18d]
// - 4/6/20 fakesolve -- tried to do LIS backtracking incorrectly w/ greedy approach, needed true backtracking [cf 650d]
// - 4/6/20 array bounds -- indexing with count into vector of size n; needs to be n + 1
// - 4/7/20 typo -- forgot to change i -> j when copying var declarations x -> y (4 copies) [cf 690b1]
// - 4/8/20 implementation error -- forgot to iterate in sorted order of x [cf 1045g]
// - 4/8/20 plane sweep implementation error -- insertion & removal orders are distinct (x_i & x_i + r_i) [cf 1045g]
// - 4/8/20 inf not big enough -- 1000 << 20 vs 1 billion + 1 billion [cf 1045g]
// - 4/8/20 n ffts wayyy too slow (nlog^2n, n = 2^20, time limit = 1s) [cf 1227f2]
// - 4/8/20 int overflow (multiplied j * count[j] without LL, when adding to ll) [cf 804d]
// - 4/8/20 implementation error -- forgot to dfs again (a 3rd time) after finding both ends of diameter [cf 804d]
// - 4/8/20 typo -- cur.fi < n && cur.se < n <-- should be m
// - 4/10/20 implementation error -- need to erase before inserting into pdbs::tree [1093e]