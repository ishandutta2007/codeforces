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
struct node;
ostream& operator<<(ostream &os, const node &node);
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

typedef priority_queue<pii, vector<pii>, greater<pii> > PQ;

// ============= Solution ============= //
int main() {
   int T;
   cin >> T;
   while (T--) {
      int n, m;
      cin >> n >> m;
      vector<string> v(n);
      for (string &s: v) cin >> s;
      map<string, pair<pii, int>> seen;
      for (int j = 0; j < n; ++j) {
         string s = v[j];
         for (int i = 0; i + 2 <= m; ++i) {
            if (i + 3 <= m) seen[s.substr(i, 3)] = make_pair(pii(i, 3), j);
            seen[s.substr(i, 2)] = make_pair(pii(i, 2), j);
         }
      }
      string s;
      cin >> s;
      vector<bool> ok(m + 1);
      vector<int> trace(m + 1);
      ok[0] = true;
      for (int i = 0; i < m; ++i) {
         if (!ok[i]) continue;
         if (seen.count(s.substr(i, 2))) {
            ok[i + 2] = true;
            trace[i + 2] = 2;
         }
         if (i + 3 <= m && seen.count(s.substr(i, 3))) {
            ok[i + 3] = true;
            trace[i + 3] = 3;
         }
      }
      if (!ok[m]) {
         cout << "-1\n";
         continue;
      }
      vector<pair<pii, int>> ans;
      int cur = m;
      while (cur) {
         ans.push_back(seen[s.substr(cur - trace[cur], trace[cur])]);
         cur -= trace[cur];
      }
      reverse(ans.begin(), ans.end());
      cout << sz(ans) << "\n";
      for (auto p: ans) {
         cout << p.fi.fi + 1 << " " << p.fi.fi + p.fi.se << " " << p.se + 1 << "\n";
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