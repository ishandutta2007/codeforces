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
#define sub_to_errichto main
// =========== Book ============ //

// ============= Solution ============= //
int sub_to_errichto() {
   int n;
   cin >> n;
   vector<int> v(n + 1);
   for (int i = 1; i <= n; ++i) cin >> v[i];
   vector<int> a, b;
   bool bad = false;
   vector<pii> ans;
   for (int i = n; i > 0; --i) {
      if (v[i] == 0) {
         continue;
      } else if (v[i] == 1) {
         ans.push_back(pii(i, i));
         a.push_back(i);
      } else if (v[i] == 2) {
         if (a.empty()) {
            bad = true;
            break;
         }
         int nxt = a.back();
         a.pop_back();
         ans.push_back(pii(nxt, i));
         b.push_back(i);
      } else if (v[i] == 3) {
         int nxt;
         if (!b.empty()) {
            nxt = b.back();
            b.pop_back();
         } else if (!a.empty()) {
            nxt = a.back();
            a.pop_back();
         } else {
            bad = true;
            break;
         }
         ans.push_back(pii(i, nxt));
         ans.push_back(pii(i, i));
         b.push_back(i);
      }
   }
   if (bad) {
      cout << "-1\n";
   } else {
      cout << sz(ans) << "\n";
      for (pii p: ans) {
         cout << p.fi << " " << p.se << "\n";
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