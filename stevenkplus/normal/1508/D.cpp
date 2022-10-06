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

// ============= Solution ============= //
int main() {
   int n;
   cin >> n;
   vector<int> x(n), y(n), a(n);
   int best = 0;
   for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i] >> a[i];
      --a[i];
      if (a[i] == i) continue;
      if (x[i] < x[best] || (x[i] == x[best] && y[i] < y[best])) {
         best = i;
      }
   }
   vector<pair<ld, int>> ord;
   for (int i = 0; i < n; ++i) {
      if (a[i] == i) continue;
      if (i == best) continue;
      if (x[best] == x[i]) {
         ord.emplace_back(numeric_limits<ld>::max(), i);
      } else {
         ord.emplace_back(ld(y[i] - y[best]) / (x[i] - x[best]), i);
      }
   }
   sort(ord.begin(), ord.end());
   vector<int> par(n);
   for (int i = 0; i < n; ++i) {
      par[i] = i;
   }
   auto find = yc([&](auto rec, int x) -> int {
      if (par[x] == x) return x;
      return par[x] = rec(par[x]);
   });
   auto join = [&](int a, int b) -> void {
      a = find(a);
      b = find(b);
      par[a] = b;
   };
   for (int i = 0; i < n; ++i) {
      join(i, a[i]);
   }

   vector<pii> ans;
   for (int i = 0; i + 1 < sz(ord); ++i) {
      if (find(ord[i].se) != find(ord[i + 1].se)) {
         ans.push_back(pii(ord[i].se, ord[i + 1].se));
         swap(a[ord[i].se], a[ord[i + 1].se]);
         join(ord[i].se, ord[i + 1].se);
      }
   }
   while (a[best] != best) {
      ans.push_back(pii(best, a[best]));
      swap(a[best], a[a[best]]);
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