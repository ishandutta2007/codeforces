// =========== Template ========== //
#include <bits/stdc++.h>
#include<bits/extc++.h>
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
struct splitmix64_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } }; // https://github.com/ecnerwala/cp-book/blob/master/src/hash_map.hpp
struct splitmix64_hash_pll { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(pll x) const { static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x.fi * 132453374217LL + x.se + FIXED_RANDOM); } }; // https://github.com/ecnerwala/cp-book/blob/master/src/hash_map.hpp thanks kevin
template <typename K, typename V, typename Hash = splitmix64_hash> using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
template <typename K, typename Hash = splitmix64_hash> using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;
template<typename A, typename B, typename C> ostream& operator<<(ostream &os, const hash_map<A, B, C> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
// hash_map<ll, ll> hm; hash_map<pll, pll, splitmix64_hash_pll> hm2;
// hash_set<pll, splitmix64_hash_pll> hs;
// =========== Book ============ //

namespace hk {
   // hk::go(g, btoa)
   // pre: g maps [0,n-1] to {[0,m-1]}... btoa has size m.
   // post: btoa[y] now contains -1 or x
   //
   // auto [indA, indB] = hk:independent_set(g, btoa)
   // pre: you already ran hk::go
   // post: indA and indB contain max independent set
   //
   // notes: runs on |V|, |E| <= 10^5 in about 1s
   // |max independent set| = n + m - |min cut|
   // |min cut| = |max matching|
   // https://codeforces.com/contest/1721/submission/170113679
   using vi = vector<int>;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) x.begin(), x.end()
   bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
      if (A[a] != L) return 0; A[a] = -1; for (int b : g[a]) if (B[b] == L + 1) { B[b] = 0; if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B)) return btoa[b] = a, 1; } return 0;
   }
   int go(vector<vi>& g, vi& btoa) {
      int res = 0; fill(all(btoa), -1); vi A(g.size()), B(btoa.size()), cur, next; for (;;) { fill(all(A), 0); fill(all(B), 0); cur.clear(); for (int a : btoa) if(a != -1) A[a] = -1; rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a); for (int lay = 1;; lay++) { bool islast = 0; next.clear(); for (int a : cur) for (int b : g[a]) { if (btoa[b] == -1) { B[b] = lay; islast = 1; } else if (btoa[b] != a && !B[b]) { B[b] = lay; next.push_back(btoa[b]); } } if (islast) break; if (next.empty()) return res; for (int a : next) A[a] = lay; cur.swap(next); } rep(a,0,sz(g)) res += dfs(a, 0, g, btoa, A, B); }
   }
   pair<vector<int>, vector<int>> independent_set(vector<vi> &g, vi& btoa) {
      vector<pii> res; int n = sz(g), m = sz(btoa); vector<bool> reachableA(n), reachableB(m); vector<int> queue; for (int i = 0; i < n; ++i) { reachableA[i] = true; } for (int i: btoa) { if (i != -1) { reachableA[i] = false; } } for (int i = 0; i < n; ++i) { if (reachableA[i]) queue.push_back(i); } int j = 0; while (j < sz(queue)) { int cur = queue[j++]; reachableA[cur] = true; for (int nxt: g[cur]) { if (reachableB[nxt]) continue; reachableB[nxt] = true; if (btoa[nxt] != -1) { queue.push_back(btoa[nxt]); } } } vector<int> resA, resB; for (int i = 0; i < n; ++i) { if (reachableA[i]) resA.push_back(i); } for (int i = 0; i < m; ++i) { if (!reachableB[i]) resB.push_back(i); } return {resA, resB};
   }
}

// Problem Statement
// Interactive. Given a bipartite graph, maintain the max matching and support removing the minimal number of nodes to reduce the size of max matching by 1
//
// ============= Solution ============= //
// Consider network flow graph where capacities of edges from X to Y are infinite and source-X and Y-sink are 1. Since min cut = max flow, the question is now to remove a node that reduces min cut by 1.
// Removing a node is equivalent to cutting the source-X or Y-sink edge, so it's now clear that each query can be handled by removing an edge in the min cut -- you will never need to remove more than 1 node. Additionally the min cut is static so we can precompute the sequence of nodes to remove in advance.
// Maintaining the max matching throughout these queries can be done by computing a single max matching in the beginning, and when removing a node x, just removing the pair that x was part of (guaranteed to be exactly 1 of them)

// Fast bipartite matching -- Hopcroft Karp
// Recovering min cut from max flow -- label each node as reachable from source or not reachable. Cut the nodes in X that are not reachable, and the nodes in Y that are reachable

int main() {
   int n1, n2, m, q;
   cin >> n1 >> n2 >> m >> q;
   vector<vector<int>> g(n1);
   hash_map<pll, int, splitmix64_hash_pll> weights;
   for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b, --a, --b;
      g[a].push_back(b);
      weights[{a, b}] = i + 1;
   }
   vector<int> btoa(n2);
   hk::go(g, btoa);
   pp(btoa);
   auto [indA, indB] = hk::independent_set(g, btoa);
   vector<bool> inCutA(n1, true), inCutB(n2, true);
   vector<int> atob(n1, -1);
   for (int i: indA) inCutA[i] = false;
   for (int i: indB) inCutB[i] = false;
   int curA = 0, curB = 0;
   ll sumEd = 0;
   hash_set<pll, splitmix64_hash_pll> max_matching;
   for (int i = 0; i < n2; ++i) {
      if (btoa[i] != -1) {
         atob[btoa[i]] = i;
         max_matching.insert(pii(btoa[i], i));
         sumEd += weights[{btoa[i], i}];
      }
   }
   pp(max_matching, sumEd);
   while (q--) {
      int qt;
      cin >> qt;
      if (qt == 1) {
         while (curA < n1 && !inCutA[curA]) ++curA;
         while (curA == n1 && curB < n2 && !inCutB[curB]) ++curB;
         int val;
         pll p;
         if (curA == n1) {
            val = -(curB + 1);
            p = pll(btoa[curB], curB);
            ++curB;
         } else {
            val = curA + 1;
            p = pll(curA, atob[curA]);
            ++curA;
         }
         sumEd -= weights[p];
         max_matching.erase(p);
         cout << "1\n";
         cout << val << "\n";
         cout << sumEd << "\n";
         cout.flush();
      } else {
         cout << sz(max_matching) << "\n";
         for (auto p: max_matching) {
            cout << weights[p] << " ";
         }
         cout << "\n";
         cout.flush();
      }
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - forgot to initialize data (is 0 the right value? -1, inf, -inf?)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases