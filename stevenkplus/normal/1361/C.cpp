// AVX-enabled std::bitset Pragmas (before #includes!)
// - bitset<200000> takes ~ 1ms per 1000 operations on GNU C++14 & GNU C++17
// #pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
// #pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
// #pragma GCC target("avx2")  //Enable AVX

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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
const int inf = 1000 << 20;
/**
 * Author: Simon Lindholm
 * Date: 2019-12-31
 * License: CC0
 * Source: folklore
 * Description: Eulerian undirected/directed path/cycle algorithm.
 * Input should be a vector of (dest, global edge index), where
 * for undirected graphs, forward/backward edges have the same index.
 * Returns a list of nodes in the Eulerian path/cycle with src at both start and end, or
 * empty list if no cycle/path exists.
 * To get edge indices back, add .second to s and ret.
 * Time: O(V + E)
 * Status: stress-tested
 */

typedef vector<int> vi;
vector<pii> eulerWalk(vector<vector<pii>>& gr, int nedges, pii src) {
  int n = sz(gr);
  vi D(n), its(n), eu(nedges);
  vector<pii> ret, s = {src};
  while (!s.empty()) {
    pii x = s.back();
    int y, e, &it = its[x.fi], end = sz(gr[x.fi]);
    if (it == end){ ret.push_back(x); s.pop_back(); continue; }
    tie(y, e) = gr[x.fi][it++];
    int ee = (e - 1) / 2;
    if (!eu[ee]) {
      D[x.fi]--, D[y]++;
      eu[ee] = 1; s.push_back({y, e});
    }}
  for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
  return {ret.rbegin(), ret.rend()};
}
// =========== Solution ============= //

int _gcd(int a, int b) {
  if (a == 0) return b;
  return _gcd(b % a, a);
}

int main() {
  int n;
  cin >> n;
  vector<int> v1, v2;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    v1.push_back(a);
    v2.push_back(b);
  }
  for (int i = 20; i >= 0; --i) {
    pp(i);
    int x = 1 << i;
    pp(x);
    vector<int> deg(x);
    vector<int> par(x);
    auto find = y_combinator([&](auto find, int n) -> int {
      if (n == par[n]) return n;
      return par[n] = find(par[n]);
    });
    for (int j = 0; j < x; ++j) {
      par[j] = j;
    }
    vector<vector<pii>> gr(x);

    for (int j = 0; j < n; ++j) {
      int a = v1[j] % x;
      int b = v2[j] % x;
      pp(a, b);
      gr[a].push_back(pii(b, j * 2 + 1));
      gr[b].push_back(pii(a, j * 2 + 2));
      ++deg[a];
      ++deg[b];
      par[find(a)] = find(b);
      ppp("done");
    }
    int cur = -1;
    bool bad = false;
    for (int j = 0; j < x; ++j) {
      if (deg[j] == 0) continue;
      if (deg[j] % 2 == 1) bad = true;
      if (cur != -1 && cur != find(j)) bad = true;
      cur = find(j);
    }
    if (bad) continue;
    cout << i << "\n";
    vector<pii> v = eulerWalk(gr, n, {v1[0] % x, -2});
    for (auto p: v) {
      int k = p.se;
      if (k == -2) continue;
      cout << k << " " << (((k - 1) ^ 1) + 1) << " ";
    }
    cout << "\n";
    break;
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN? different MAXN vs MAXM?)
// - special cases (n=1? graph not connected?)
// - sorting (input or ouput must be in particular order?)
// - initialize & re-initialize efficiently between test cases