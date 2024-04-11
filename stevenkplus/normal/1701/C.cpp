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
struct node;
ostream& operator<<(ostream &os, const node &node);
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
// total number of tasks = m
// total time = m if everyone is optimal
// total wasted time = # tasks not assigned optimally + workers with dead time
// total extra time = n * T - m
// find best T
//
//
// extra[T] --> number of tasks to reassign (because their workers already have T tasks to do) -- sum(max(0, cnt[i] - T))
// free[T] --> number of additional non-specialized tasks that can be done by workers w/ < T tasks -- sum((T - cnt[i]) / 2)
// if extra[T] <= free[T], then T is viable
//
//

int main() {
   int T;
   cin >> T;
   while (T--) {
      int n, m;
      cin >> n >> m;
      vector<int> cnt(n);
      for (int i = 0; i < m; ++i) {
         int x;
         cin >> x;
         --x;
         ++cnt[x];
      }

      pp(cnt);
      sort(cnt.begin(), cnt.end());
      vector<ll> extra(m), free(m);

      int oddcnt = 0;
      int cur = 0;
      ll sum = 0;
      for (int i = 0; i < m; ++i) {
         while (cur < n && cnt[cur] < i) {
            sum += cnt[cur];
            if (cnt[cur] % 2 == 1) {
               ++oddcnt;
            }
            ++cur;
         }
         int waste = i % 2 == 0 ? oddcnt : cur - oddcnt;
         free[i] = (1LL * i * cur - sum - waste) / 2;
      }
      pp(free);

      reverse(cnt.begin(), cnt.end());
      cur = 0;
      sum = 0;
      for (int i = m - 1; i >= 0; --i) {
         while (cur < n && cnt[cur] >= i) {
            sum += cnt[cur];
            ++cur;
         }
         extra[i] = sum - 1LL * i * cur;
      }
      pp(extra);

      int ans = m;
      for (int i = 0; i < m; ++i) {
         if (extra[i] <= free[i]) {
            ans = i;
            break;
         }
      }
      cout << ans << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - forgot to initialize data (is 0 the right value? -1, inf, -inf?)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases