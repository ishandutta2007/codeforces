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

// ============= Solution ============= //
int main() {
  // Strategy: iterate over characters from left to right.
  // Maintain a counter of #open - #close encountered (nesting levels).
  // If counter is about to go negative, skip over it (and count it as a move-to-end of the string operation)

  // 1) does this yield a balanced bracket sequence? Yes...
  //   We take a subsequence of the input s, call it s_kept. All the characters we deleted from s to obtain s_sub are closing brackets; call the subsequence containing just those characters s_deleted.
  //   All prefixes of s_kept will have non-negative nesting level.
  //   Concatenating s_kept with s_deleted will yield a string whose prefixes are also non-negative, because sum(s_kept) = -sum(s_deleted).
  //   The concatenation of s_kept and s_deleted is exactly the string you would get by performing the "move-to-end" operation on all brackets in s_deleted, so therefore the construction is valid.
  //
  // 2) is there any better sequence of moves? No...
  //   Consider the most negative value of nesting level among all prefixes of s. Let it be -x.
  //   A single operation will only change that value by at most 1 (in either direction).
  //   Therefore there must be at least x operations.
  //   x is obtained by the above strategy, because every operation done increases all negative prefixes.

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int ans = 0;
    int cur = 0;
    int n;
    string s;
    cin >> n >> s;
    for (char c: s) {
      if (c == '(') ++cur;
      else --cur;
      ans = max(ans, -cur);
    }
    cout << ans << "\n";
  }

}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases