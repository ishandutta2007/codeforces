// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
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
const double pi = acos(-1.);

// ordered_set with order_of_key and find_by_order
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// WARNING: functions as a set (doesn't allow duplicates); insert pairs instead if duplicates are needed.
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ============= Solution ============= //
int main() {
  int n, q;
  cin >> n >> q;
  int size = 1;
  while (size <= n + 1) size *= 2;
  vector<int> bit(size);
  auto find = [&](int ord) -> int {
    int lo = 0;
    for (int i = size / 2; i > 0; i /= 2) {
      if (bit[lo + i] <= ord) {
        ord -= bit[lo + i];
        lo += i;
      }
    }
    return lo + 1;
  };
  auto inc = [&](int idx, int add) -> void {
    pp(idx, add);
    while (idx < size) {
      bit[idx] += add;
      idx += idx & -idx;
    }
  };
  inc(n + 1, 1);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    inc(x, 1);
  }
  for (int i = 0; i < q; ++i) {
    int x;
    cin >> x;
    if (x < 0) {
      int k = -x - 1;
      int val = find(k);
      inc(val, -1);
    } else {
      inc(x, 1);
    }
  }

  int ans = find(0);
  if (ans == n + 1) ans = 0;
  cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases