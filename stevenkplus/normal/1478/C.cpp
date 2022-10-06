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

// ============= Ramblings of a Deranged Mind ============= //
//
// Read this instead: https://codeforces.com/blog/entry/87294
// ... YOU HAVE BEEN WARNED...
//
// C:
//
// Observation 1:
// a[i] = a[j] implies d[i] = d[j]
// actually, a is all distinct. so nevermind, a[i] is never a[j]
//
//
// Example 1:
// D = [8 12 8 12]
// A = [1 -3 -1 3]
//   0 4 2 2 = 8
//   4 0 2 6 = 12
//   ...
// A = [-3 -1 1 3]
//
//
// When sorted... we have nice update formula (IGNORE THIS PART)
// D[0] = 8
// D[1] = D[0] + (A[1] - A[0]) * (2 - 1)
// D[i + 1] = D[i] + (A[i + 1] - A[i]) * (n - 2(i+1) - 1)
//
// D must be a mountain
// Translation of A (apply A[i] += x for all i) does not affect D.
//
// And A is symmetric! this makes D much easier to reason about;
// -10 -8 -3 3 8 10
// the values are really straightforward to compute!
// D[2] = sum of abs differences for -3
// |-3 - (-10)| + |-3 - 10| = |10 - (-10)|
//
// Observation 2: Distance from AB + BC = AC, if B is between A and C (on a number line)
// Distance AB + BC if B is not between A and C? it is more than AC -->
//   it's 2 * A (because midpoint of BC is origin)
//
// --> D is guaranteed to come in pairs, so we can sort it and look at even indices
// 8 8 12 12 --> look at 8, and 12.
// 
// Example: 8 8 12 12, -3 -1 1 3
// the first value of D_even is 2 * sum(A_positive).  [8 = 2 * (1 + 3)]
// the second value of D_even is D_even[0] + 2 * (A[1] - A[0])
// the third value of D_even is D_even[1] + A[3]
//
// this gives us a formula to compute all values of A
//
//
// Implementation: turn this into an actual solution
// 1) sort & validate that D is in pairs (D[2 * i] == D[2 * i + 1] for all i in [0, n))
// 2) halfD = vector<int>(n) --> all the even indices of d
//
// 3) a[n - 1] = halfD[n - 1] / 2 / n
//    a[n - 2] = (halfD[n - 2] / 2 - a[n - 1]) / (n - 1)
//    a[n - i] = (halfD[n - i] / 2 - sumOfAlreadyDeterminedA) / (n - i + 1)
//
// we just have make sure all the divisions here ^ result in integers.
//  - So check the mod before performing the division, and set ans = "NO" if mod is not 0.
//
// Serendipity: There's a trick, if the instance is 0<a<b<c<d, then d(a) = 2(a+b+c+d) d(b) = 2(b+b+c+d) d(c) = 2(c+c+c+d) d(d) = 2(d+d+d+d)
//
// = [0] * n, then do a[i + 1] = a[i] + (halfD[i + 1] - halfD[i]) / 2
//
//
//  -x.........x.......y,
//  y - (-x) + y - x = 2y
//  the sum of distances for the largest a is just d[-1] = 2 * n * a[-1]
//  second largest a is d[-2] = 2 * (n - 1) * a[-2] + 2 * a[-1]
//  solve this system of linear equations by eliminating / substituting in values that we already know
int main() {
   int T;
   cin >> T;
   while (T--) {
      int n;
      cin >> n;
      vector<ll> d(2 * n);
      for (ll &i: d) cin >> i;
      sort(d.begin(), d.end());
      reverse(d.begin(), d.end());

      string ans = "YES";
      vector<ll> halfD(n);
      for (int i = 0; i < n; ++i) {
         if (d[2 * i] != d[2 * i + 1] || d[2 * i] % 2) {
            ans = "NO";
            break;
         }
         if (i + 1 < n && d[2 * i + 1] == d[2 * i + 2]) {
            ans = "NO";
            break;
         }
         halfD[i] = d[2 * i] / 2;
      }
      pp(halfD);

      vector<ll> ansvals(n);
      ll pref = 0;
      for (int i = 0; i < n; ++i) {
         if ((halfD[i] - pref) % (n - i)) {
            ans = "NO";
            break;
         }
         ansvals[i] = (halfD[i] - pref) / (n - i);
         if (ansvals[i] <= 0) {
            ans = "NO";
            break;
         }
         pref += ansvals[i];
      }
      pp(ansvals);
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