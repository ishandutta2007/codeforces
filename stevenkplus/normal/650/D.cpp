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

template <typename T> class Seg {
  int size;
  vector<T> data;
  function<T (T, T)> func;
  T zero;
  public:
  Seg(int n, function<T (T, T)> f, T z) {
    size = 1;
    func = f;
    zero = z;
    while (size < n) size *= 2;
    data = vector<T>(size * 2, zero);
  }

  T ask(int left, int right) {
    T ret = zero;
    for (left += size, right += size; left < right; left /= 2, right /= 2) {
      if (left & 1) {
        ret = max(ret, data[left++]);
      }
      if (right & 1) {
        ret = max(ret, data[right - 1]);
      }
    }
    return ret;
  }

  void insert(int x, T val) {
    pp("insert", x, val);
    for (x += size; x > 0; x /= 2) {
      data[x] = max(data[x], val);
    }
  }
};

// =========== Solution ============= //

int main() {
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  vector<int> inp(n);
  for (int i = 0; i < n; ++i) {
    cin >> inp[i];
    mp[inp[i]] = 0;
  }
  vector<vector<pii>> q(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b; --a;
    q[a].push_back(pii(b, i));
    mp[b] = 0;
  }
  int cnt = 0;
  for (auto &k: mp) {
    k.se = cnt++;
  }
  for (auto &i : inp) {
    i = mp[i];
  }
  for (auto &v : q) {
    for (auto &i : v) {
      i.fi = mp[i.fi];
    }
  }

  auto maxfn = [&](int a, int b) -> int { return max(a, b); };

  pp(inp);
  pp(q);
  vector<int> F(m), R(m);
  vector<int> FW(n), RW(n);
  int L = 0;
  for (int rep = 0; rep < 2; ++rep) {
    Seg<int> seg(cnt, maxfn, 0);
    auto &v = rep ? R : F;
    auto &w = rep ? RW : FW;
    for (int _i = 0; _i < n; ++_i) {
      int i = rep ? n - 1 - _i : _i;
      for (auto k: q[i]) {
        int l = rep ? k.fi + 1 : 0;
        int r = rep ? cnt : k.fi;
        v[k.se] = seg.ask(l, r) + 1;
      }
      int l = rep ? inp[i] + 1 : 0;
      int r = rep ? cnt : inp[i];
      w[i] = seg.ask(l, r) + 1;
      seg.insert(inp[i], w[i]);
    }
    L = seg.ask(0, cnt);
  }

  vector<int> cnts(n + 1);
  for (int i = 0; i < n; ++i) {
    if (FW[i] + RW[i] - 1 == L) {
      ++cnts[FW[i]];
    }
  }
  pp(L);
  pp(F);
  pp(R);

  vector<int> ans(m);
  for (int i = 0; i < n; ++i) {
    for (auto k: q[i]) {
      int c1 = F[k.se] + R[k.se] - 1;
      int c2 = (FW[i] + RW[i] - 1 < L || cnts[FW[i]] > 1) ? L: L - 1;
      ans[k.se] = max(c1, c2);
    }
  }

  for (int i: ans) {
    cout << i << "\n";
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