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
#define sub_to_errichto main
// =========== Book ============ //

const int inf = 1000 << 20;
const ll infl = 1LL << 60;

// ============= Solution ============= //
int sub_to_errichto() { // fml
   int T;
   cin >> T;
   while (T--) {
      int n, k;
      cin >> n >> k;
      string s;
      cin >> s;
      auto improve = [&](char c) -> char {
         if (c == 'a') return 'a';
         if (c == 'a' + k - 1) return 'a';
         return c - 1;
      };
      bool lastSwap = false;
      for (int i = 0; i < n; ++i) {
         pp(i, s, lastSwap);
         if (lastSwap) {
            if (i - 2 >= 0 && s[i - 1] < s[i - 2]) {
               swap(s[i - 2], s[i - 1]);
            } else {
               s[i - 1] = improve(s[i - 1]);
            }
            lastSwap = false;
            continue;
         }
         if (i - 1 >= 0) {
            if (i + 1 < n && s[i + 1] < s[i] && s[i + 1] < s[i - 1]) {
               swap(s[i], s[i + 1]);
               lastSwap = true;
               continue;
            } else if (s[i] < s[i - 1]) {
               swap(s[i], s[i - 1]);
               continue;
            }
         }
         if (i + 1 < n && s[i + 1] == 'a') {
            s[i] = improve(s[i]);
            continue;
         }
         if (i + 2 < n && s[i + 2] < improve(s[i]) && s[i + 2] < improve(s[i + 1])) {
            s[i] = improve(s[i]);
            continue;
         } else if (i + 1 < n && improve(s[i + 1]) < improve(s[i])) {
            swap(s[i], s[i + 1]);
            pp("swap");
            lastSwap = true;
            continue;
         }
         s[i] = improve(s[i]);
      }
      cout << s << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases