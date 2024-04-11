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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// ============= Solution ============= //
int main() {
   int n;
   cin >> n;
   vector<ll> v(n);
   for (ll &i: v) cin >> i;
   for (int i = 0; i < n; ++i) {
      v[i] -= i;
   }

   auto solve = yc([&](auto solve, vector<ll> &v) -> vector<ll> {
      pp("solve", v);
      int n = sz(v);
      if (n <= 1) return v;
      vector<ll> a(v.begin(), v.begin() + n / 2);
      vector<ll> b(v.begin() + n / 2, v.end());
      a = solve(a);
      b = solve(b);
      vector<ll> res(n);
      for (int i = 0; i < n / 2; ++i) {
         res[i] = a[i];
      }
      for (int i = n / 2; i < n; ++i) {
         res[i] = b[i - n / 2];
      }

      int left = n / 2;
      int right = n / 2 + 1;
      ll sum = res[left];
      while (true) {
         ll rval = sum / (right - left);
         ll lval = rval;
         if (sum % (right - left) > 0) ++lval;
         if (right < n && rval < res[right]) {
            sum += res[right];
            ++right;
         } else if (left - 1 >= 0 && lval > res[left - 1]) {
            sum += res[left - 1];
            --left;
         } else {
            break;
         }
      }
      int cnt = right - left;
      for (int i = left; i < right; ++i) {
         res[i] = (sum + cnt - 1) / cnt;
         sum -= res[i];
         --cnt;
      }

      pp("solved", v, res);
      return res;
   });

   vector<ll> ans = solve(v);
   for (int i = 0; i < n; ++i) {
      ans[i] += i;
   }
   for (ll i: ans) {
      cout << i << " ";
   }
   cout << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases