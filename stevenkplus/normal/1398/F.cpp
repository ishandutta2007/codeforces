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
      string s;
      cin >> s;
      vector<int> a, b;
      a.push_back(-1);
      b.push_back(-1);
      for (int i = 0; i < n; ++i) {
         if (s[i] == '0') a.push_back(i);
         else if (s[i] == '1') b.push_back(i);
      }
      for (int len = 1; len <= n; ++len) {
         int pos = 0;
         int ans = 0;
         while (pos + len <= n) {
            int x = *--lower_bound(a.begin(), a.end(), pos + len);
            int y = *--lower_bound(b.begin(), b.end(), pos + len);
            if (x < pos || y < pos) {
               ++ans;
               pos += len;
            } else {
               pos = min(x, y) + 1;
            }
            pp(len, pos, ans);
         }
         cout << ans << " ";

         if (len % 10 == 0) {
            // thin it out
            vector<int> na, nb;
            for (int i: a) {
               if (sz(na) < 2) {
                  na.push_back(i);
               } else {
                  int x = na[sz(na) - 2];
                  if (i - x <= len) {
                     na.back() = i;
                  } else {
                     na.push_back(i);
                  }
               }
            }
            for (int i: b) {
               if (sz(nb) < 2) {
                  nb.push_back(i);
               } else {
                  int x = nb[sz(nb) - 2];
                  if (i - x <= len) {
                     nb.back() = i;
                  } else {
                     nb.push_back(i);
                  }
               }
            }
            a = na;
            b = nb;
         }
      }
      cout << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases