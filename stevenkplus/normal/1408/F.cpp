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

const ld eps = 1E-10;
const int inf = 1000 << 20;
int sub_to_errichto() {
   int n;
   cin >> n;
   vector<pii> ans;

   vector<vector<int>> data;
   vector<int> groups;
   auto join = [&](int a, int b) -> int {
      assert(sz(data[a]) == sz(data[b]));
      int c = sz(data);
      data.push_back(vector<int>());

      int k = sz(data[a]);
      for (int i = 0; i < k; ++i) {
         data[c].push_back(data[a][i]);
         data[c].push_back(data[b][i]);
         ans.push_back(pii(data[a][i], data[b][i]));
      }
      return c;
   };

   auto split = [&](int a, int k) -> int {
      assert(k < sz(data[a]));
      int c = sz(data);
      data.push_back(vector<int>());
      data[c].insert(data[c].end(), data[a].end() - k, data[a].end());
      data[a].resize(sz(data[a]) - k);
      return c;
   };

   auto make = [&](int i) -> int {
      int c = sz(data);
      data.push_back(vector<int>({i}));
      return c;
   };

   auto size = [&](int i) -> int {
      return sz(data[i]);
   };

   for (int i = 0; i < n; ++i) {
      groups.push_back(make(i));
   }

   while (true) {
      vector<int> ngroups;
      // groups is always desc order of size
      for (int i = 0; i < sz(groups); ++i) {
         if (i + 1 < sz(groups) && size(groups[i]) == size(groups[i + 1])) {
            ngroups.push_back(join(groups[i], groups[i + 1]));
            ++i;
         } else {
            ngroups.push_back(groups[i]);
         }
      }
      if (sz(groups) == sz(ngroups)) break;
      groups = ngroups;
   }

   while (sz(groups) > 2) {
      int a = groups[0];
      int b = groups.back();
      groups.pop_back();
      int c = split(a, size(b));
      int d = join(b, c);
      while (sz(groups) > 1 && size(groups.back()) == size(d)) {
         d = join(groups.back(), d);
         groups.pop_back();
      }
      groups.push_back(d);
   }

   cout << sz(ans) << "\n";
   for (pii p: ans) {
      cout << p.fi + 1 << " " << p.se + 1 << "\n";
   }



}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases