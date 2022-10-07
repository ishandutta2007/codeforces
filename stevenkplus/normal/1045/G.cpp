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

#define segZero 0
#define segT ll
#define segF(x, y) ((x) + (y))
class Seg {
  int size;
  vector<segT> data;
  public:
  Seg(int n) {
    size = 1; while (size < n) size *= 2;
    data = vector<segT>(size * 2, segZero);
  }
  segT ask(int left, int right) {
    segT ret = segZero;
    for (left += size, right += size; left < right; left /= 2, right /= 2) {
      if (left & 1) ret = segF(ret, data[left++]);
      if (right & 1) ret = segF(ret, data[--right]);
    }
    return ret;
  }
  void insert(int x, segT val) { for (x += size; x > 0; x /= 2) data[x] = segF(data[x], val); }
};

class Bit {
  int size;
  vector<ll> data;
  public:
  Bit(int n) { size = n + 2; data = vector<ll>(size); }
  ll ask(int x) { ll ret = 0; for (++x; x; x &= x - 1) ret += data[x]; return ret; }
  void inc(int x, ll val) { for (++x; x < size; x += x & -x) data[x] += val; }
};

// =========== Solution ============= //

template<typename K> void assign (map<K, int> &mp) {
  int cnt = 0;
  for (auto &k: mp) {
    k.se = cnt++;
  }
}

template<typename K> void assignv (vector<K> &v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
}
#define findv(v, x) int(lower_bound(v.begin(), v.end(), x) - v.begin())


int main() {
  int n, k;
  cin >> n >> k;
  pp(n, k);
  vector<int> X(n), R(n), Q(n);
  vector<pii> xi(n);
  // map<int, int> qmp;
  vector<int> qv;
  for (int i = 0; i < n; ++i) {
    cin >> X[i] >> R[i] >> Q[i];
    xi[i] = pii(X[i], i);
    // qmp[Q[i]];
    qv.push_back(Q[i]);
  }
  sort(xi.begin(), xi.end());
  pp(X); pp(R); pp(Q);
  // assign(qmp);
  assignv(qv);
  // vector<map<int, int>> mps(sz(qmp));
  // vector<map<int, int>> mps(sz(qv));
  vector<vector<int>> vs(sz(qv));
  for (int i = 0; i < n; ++i) {
    // mps[qmp[Q[i]]][X[i]];
    // mps[findv(qv, Q[i])][X[i]];
    vs[findv(qv, Q[i])].push_back(X[i]);
  }
  // vector<Seg> segs;
  vector<Bit> bits;
  // for (auto &mp: mps) {
  for (auto &v: vs) {
    // mp[inf * 2];
    v.push_back(inf * 2);
    // assign(mp);
    assignv(v);
    // segs.push_back(Seg(sz(mp)));
    // bits.push_back(Bit(sz(mp)));
    bits.push_back(Bit(sz(v)));
  }

  // pp(qmp);
  pp(qv);
  // pp(mps);
  pp(vs);
  // pp(segs);
  ll ans = 0;
  set<pii> w;
  for (auto _i: xi) {
    int i = _i.se;
    while (sz(w) && w.begin()->fi < X[i]) {
      pii p = *w.begin();
      w.erase(w.begin());
      int j = p.se;
      // int qj = qmp[Q[j]];
      int qj = findv(qv, Q[j]);
      // int xq = mps[qj][X[j]];
      int xq = findv(vs[qj], X[j]);
      // segs[qj].insert(xq, -1);
      bits[qj].inc(xq, -1);
    }
    int left = X[i] - R[i];
    int right = X[i] + R[i] + 1;
    pp(left, right);

    // for (int q = Q[i] - k; q <= Q[i] + k; ++q) {
    //   for (auto _q = qmp.lower_bound(Q[i] - k); _q != qmp.end() && _q->fi <= Q[i] + k; ++_q) {
    for (int q = Q[i] - k; q <= Q[i] + k; ++q) {
      // auto _q = qmp.find(q); if (_q == qmp.end()) continue;
      int qi = findv(qv, q); if (qi == sz(qv) || qv[qi] != q) continue;
      // int leftQ = mps[qi].lower_bound(left)->se;
      int leftQ = findv(vs[qi], left);
      // int rightQ = mps[qi].lower_bound(right)->se;
      int rightQ = findv(vs[qi], right);
      // pp(mps[qi], leftQ, rightQ);
      // ll val = segs[qi].ask(leftQ, rightQ);
      ll val = bits[qi].ask(rightQ - 1) - bits[qi].ask(leftQ - 1);
      pp(val);
      ans += val;
    }

    // int qi = qmp[Q[i]];
    int qi = findv(qv, Q[i]);
    // int xq = mps[qi][X[i]];
    int xq = findv(vs[qi], X[i]);
    pp("insert", qi, xq, 1);
    // segs[qi].insert(xq, 1);
    bits[qi].inc(xq, 1);
    w.insert(pii(X[i] + R[i], i));
  }

  cout << ans << "\n";
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