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
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
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
#define yc y_combinator
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
//
// Observation 1: Because d itself is lucky, then if you can make k, you can make k + any multiple of d
// Formulate the problem as: for every 0 <= i < d, what is the minimum x where x % d == i such that x can be written as a sum of lucky nmubers?
//
// --> this question is independent of the 10^4 queries; it can be computed offline (preprocessing)
// 
// Example 1: q = 3, d = 7.
// 7 is lucky. So if you can make x, you can make x + 7 (and x + 14, x + 21, etc)
//
// So we want to know, for each of i = 0, 1, ... 6,
// What is the minimum x (where x % 7 == i) such that you make x?
// To rephrase: Of all the makable numbers, what is the smallest one that is congruent to i mod x?
//
// Observation 2: Strategy for actually finding these key "x" values --> approach like a
//   knapsack problem
//
// Implementation strategy: vector<bool> (or bitset) of "makable" elements
//
int main() { // dobby is a free elf
   int T;
   cin >> T;

   const int maxn = 100;
   vector<vector<bool>> can(10, vector<bool>(maxn));
   for (int d = 1; d <= 9; ++d) { // 9 * 100 * 100 ~ 10^5 iterations
      // TIP (advanced -- useful for div1): use bitset<int> + AVX2 to get 1000x speedup doing these knapsack-like boolean computations -- search codeforces bitset, you'll find a good tutorial
      auto &makable = can[d];
      makable[0] = 1;
      for (int j = 0; j < 100; ++j) {
         int d0 = j % 10, d1 = j / 10;
         if (d0 == d || d1 == d) { // check if j is lucky
            for (int k = 0; k + j < maxn; ++k) {
               // if k is makable, then k + j is makable
               // "relax" this condition with the below assignment
               makable[k + j] = makable[k + j] || makable[k];
            }
         }
      }
   }

   while (T--) {
      int q, d;
      cin >> q >> d;
      pp(can[7]);
      for (int i = 0; i < q; ++i) {
         int x;
         cin >> x;
         if (x >= 100) {
            int sub = (x - 99 + d - 1) / d;
            x -= sub * d;
         }
         if (can[d][x]) {
            cout << "YES\n";
         } else {
            cout << "NO\n";
         }
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