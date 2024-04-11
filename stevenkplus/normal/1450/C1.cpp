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

const int inf = 1000 << 20;

// ============= Solution ============= //
int main() { // i am free!
   int T;
   cin >> T;
   while (T--) {
      int n;
      cin >> n;
      vector<string> grid(n);
      for (string &s: grid) {
         cin >> s;
      }

      int tot = 0;
      vector<int> xs(3), ys(3);
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < n; ++j) {
            int k = (i + j) % 3;
            if (grid[i][j] == 'X') {
               ++xs[k];
               ++tot;
            } else if (grid[i][j] == 'O') {
               ++ys[k];
               ++tot;
            }
         }
      }

      bool found = false;
      pii ij;
      for (int i = 0; i < 3; ++i) {
         for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            if (xs[i] + ys[j] <= tot / 3) {
               ij = pii(i, j);
               found = true;
            }
         }
         if (found) break;
      }

      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < n; ++j) {
            int k = (i + j) % 3;
            if (grid[i][j] == '.') continue;
            if (k == ij.fi) {
               grid[i][j] = 'O';
            } else if (k == ij.se) {
               grid[i][j] = 'X';
            }
         }
      }

      for (string s: grid) {
         cout << s << "\n";
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