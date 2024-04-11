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
// https://pastebin.com/q12aBwya from  https://codeforces.com/blog/entry/58048
struct BipartiteMatcher {
  vector<vector<int>> G;
  vector<int> L, R, Viz;
  
  BipartiteMatcher(int n, int m) :
  G(n), L(n, -1), R(m, -1), Viz(n) {}
  
  void AddEdge(int a, int b) {
    G[a].push_back(b);
  }
  
  bool Match(int node) {
    if (Viz[node])
      return false;
    Viz[node] = true;
    
    for (auto vec : G[node]) {
      if (R[vec] == -1) {
        L[node] = vec;
        R[vec] = node;
        return true;
      }
    }
    
    for (auto vec : G[node]) {
      if (Match(R[vec])) {
        L[node] = vec;
        R[vec] = node;
        return true;
      }
    }
    
    return false;
  }
  
  int Solve() {
    bool ok = true;
    while (ok) {
       ok = false;
      fill(Viz.begin(), Viz.end(), 0);
      for (int i = 0; i < (int)L.size(); ++i)
        if (L[i] == -1 && !ok)
          ok |= Match(i);
    }
    
    int ret = 0;
    for (int i = 0; i < L.size(); ++i)
      ret += (L[i] != -1);
    return ret;
  }
};

// ============= Solution ============= //
int main() {
   int d, n;
   cin >> d >> n;
   vector<string> inp(n);
   for (string &s: inp) cin >> s;

   vector<int> ppcnt(n);
   vector<pii> bypp(n);
   BipartiteMatcher bm(n, n);
   for (int i = 0; i < n; ++i) {
      for (char c: inp[i]) {
         if (c == '1') ++ppcnt[i];
      }
      bypp[i] = pii(ppcnt[i], i);
   }
   vector<int> idx(n);
   sort(bypp.begin(), bypp.end());
   reverse(bypp.begin(), bypp.end());
   for (int i = 0; i < n; ++i) {
      idx[bypp[i].se] = i;
   }
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         if (i == j) continue;
         bool issubset = true;
         for (int k = 0; k < d; ++k) {
            if (inp[i][k] > inp[j][k]) issubset = false;
         }
         if (issubset) {
            pp(inp[i], inp[j], i, j);
            bm.AddEdge(idx[i], idx[j]);
         }
      }
   }

   bm.Solve();
   vector<int> par(n, -1);
   vector<int> indeg(n);
   for (int i = 0; i < n; ++i) {
      if (bm.L[idx[i]] != -1) {
         par[i] = bypp[bm.L[idx[i]]].se;
         ++indeg[par[i]];
      }
   }
   pp(par);

   vector<int> ord;
   vector<bool> vis(n);
   for (int i = 0; i < n; ++i) {
      int cur = i;
      while (cur != -1 && indeg[cur] == 0 && !vis[cur]) {
         vis[cur] = true;
         ord.push_back(cur);
         if (par[cur] != -1) --indeg[par[cur]];
         cur = par[cur];
      }
   }
   pp(ord);

   vector<int> ans;
   vector<bool> cur(d);
   for (int i: ord) {
      bool needReset = false;
      for (int j = 0; j < d; ++j) {
         if (inp[i][j] == '0' && cur[j]) {
            needReset = true;
         }
      }
      if (needReset) {
         ans.push_back(-1);
         cur = vector<bool>(d);
      }
      for (int j = 0; j < d; ++j) {
         if (inp[i][j] == '1' && !cur[j]) {
            cur[j] = true;
            ans.push_back(j);
         }
      }
   }

   cout << sz(ans) << "\n";
   for (int i: ans) {
      if (i == -1) cout << "R ";
      else cout << i << " ";
   }
   cout << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases