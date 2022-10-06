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

const int inf = 1000 << 20;


// ============= Solution ============= //
int main() {
   int n;
   cin >> n;
   vector<int> v(2 * n);
   for (int i = 0; i < 2 * n; ++i) {
      v[i] = i + 1;
   }

   auto flip = [&](int x) -> int {
      if (x < n) return x + n;
      else return x - n;
   };
   if (n % 2 == 0) {
      cout << "First" << endl;
      vector<int> p(2 * n);
      for (int i = 0; i < 2 * n; ++i) {
         p[i] = 1 + (i % n);
      }
      for (int i: p) {
         cout << i << " ";
      }
      cout << endl;
   } else {
      cout << "Second" << endl;
      vector<int> p(2 * n);
      for (int &i: p) cin >> i, --i;
      vector<int> sums(n);
      for (int i = 0; i < 2 * n; ++i) {
         sums[p[i]] += i;
      }
      vector<bool> taken(2 * n);
      for (int i = 0; i < 2 * n; ++i) {
         pp(i);
         int cur = i;
         while (!taken[cur] && !taken[flip(cur)]) {
            pp(cur);
            taken[cur] = true;
            cur = flip(sums[p[cur]] - cur);
         }
      }

      ll sum = 0;
      for (int i = 0; i < 2 * n; ++i) {
         if (taken[i]) {
            sum += v[i];
         }
      }
      pp(taken, sum);
      if (sum % (2 * n) != 0) {
         for (int i = 0; i < 2 * n; ++i) {
            taken[i] = !taken[i];
         }
      }
      for (int i = 0; i < 2 * n; ++i) {
         if (taken[i]) {
            cout << v[i] << " ";
         }
      }
      cout << endl;
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases