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
#define yc y_combinator;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

#define setmax(a, b) a = max(a, b)
// ============= Solution ============= //
int main() {
  int T;
  // cin >> T;
  T = 1;
  for (int t = 1; t <= T; ++t) {
    int n;
    cin >> n;
    set<int> A, B, C;
    C.insert(0);
    C.insert(-1);
    A.insert(0);
    int pos = 0; // next el of C to be added
    ll val = 0; // sum of sz(B) largest els of C
    ll totsum = 0;
    for (int i = 0; i < n; ++i) {
      int t, d;
      cin >> t >> d;
      pp(i, t, d);
      pp(A, B, C);
      if (d > 0) {
        totsum += d;
        C.insert(d);
        if (d > pos) {
          pos = *++C.find(pos);
          val += d - pos;
        }
        if (t == 0) {
          A.insert(d);
        } else {
          B.insert(d);
          val += pos;
          pos = *--C.find(pos);
        }
        pp(val);
      } else {
        d *= -1;
        totsum -= d;
        if (d >= pos) {
          val += pos - d;
          pp(pos, C);
          pos = *--C.find(pos);
        }
        C.erase(d);
        if (t == 0) {
          A.erase(d);
        } else {
          B.erase(d);
          pos = *++C.find(pos);
          val -= pos;
        }
      }
      pp(val, totsum);
      pp(A, B, C);
      ll ans = val + totsum;
      if (sz(B) > 0 && *A.rbegin() < *B.begin()) {
        ans += *A.rbegin() - *B.begin();
      }
      cout << ans << "\n";
    }
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases