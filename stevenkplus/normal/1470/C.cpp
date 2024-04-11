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
mt19937 rng((unsigned)(chrono::steady_clock::now().time_since_epoch().count()));

// ============= Solution ============= //
// subscribe to me on youtube: https://www.youtube.com/channel/UCl9IahGhVii0YrjdJvM1XNg
int main() {
   int n, k;
   cin >> n >> k;
   int cur = 0;
   vector<int> v(n, k);
   int m = 1000;
   vector<int> ans(n, 1);
   int f = 0;
   for (int i = 0; i < m; ++i) {
      pp(v);
      pp(ans);
      if (f == 1) {
         cur += n - 2;
      } else if (f == 2) {
         cur = cur;
         f = 1;
      } else {
         cur += 200;
         cur += rng() % 10;
      }
      cur %= n;
      cout << "? " << cur + 1 << endl;
      int val;
      cin >> val;

      if (f == 0 && val != k) {
         f = 1;
      }
      if (f == 1 && val == k) {
         f = 2;
      }
      for (int j = 0; j < n; ++j) {
         if (v[j] != val) {
            int off = (cur - j + n) % n;
            ans[off] = 0;
         }
      }

      vector<int> w(n);
      for (int j = 0; j < n; ++j) {
         if (j == 0) {
            w[j + 1] += v[j];
         } else {
            w[j - 1] += v[j] / 2;
            w[(j + 1) % n] += (v[j] + 1) / 2;
         }
      }
      v = w;
   }

   pp(ans);
   int a = -1;
   for (int i = 0; i < n; ++i) {
      if (ans[i]) {
         if (a != -1) {
            throw "gg";
         }
         a = i;
      }
   }
   if (a == -1) {
      while(true);
   }
   cout << "! " << a + 1 << endl;
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases