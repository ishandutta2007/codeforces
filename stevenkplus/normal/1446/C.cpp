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
   vector<int> v(n);
   for (int &i: v) cin >> i;
   vector<pii> mp;
   mp.reserve(n * 31);
   for (int i: v) {
      for (int j = 0; j <= 30; ++j) {
         mp.push_back(pii(j, i));
         i /= 2;
      }
   }

   sort(mp.begin(), mp.end());
   auto it = unique(mp.begin(), mp.end());
   mp.resize(it - mp.begin());
   auto get = [&](int height, int val) -> int {
      int ret = lower_bound(mp.begin(), mp.end(), pii(height, val)) - mp.begin();
      return ret;
   };

   int m = sz(mp);
   vector<vector<int>> ed(m);
   vector<int> sizes(m);
   pp(mp);
   for (int i = 0; i < m; ++i) {
      int val = mp[i].se;
      int height = mp[i].fi;
      if (height == 0) {
         ++sizes[i];
      }
      if (height < 30) {
         int par = get(height + 1, val / 2);
         ed[par].push_back(i);
         sizes[par] += sizes[i];
      }
   }
   pp(sizes);
   sizes.push_back(0);

   auto dfs = yc([&](auto rec, int cur) -> int {
      if (cur == m) return 0;
      pp(cur, ed[cur]);
      auto ch = ed[cur];
      int cl = sz(ch) >= 1 ? ch[0] : m;
      int cr = sz(ch) >= 2 ? ch[1] : m;
      int choice1 = max(0, sizes[cl] - 1) + rec(cr);
      int choice2 = max(0, sizes[cr] - 1) + rec(cl);
      return min(choice1, choice2);
   });
   int ans = dfs(get(30, 0));
   cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases