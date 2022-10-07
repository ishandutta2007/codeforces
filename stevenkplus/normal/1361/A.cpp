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

const int inf = 1000 << 20;
// =========== Solution ============= //

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> ed(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    ed[a].push_back(b);
    ed[b].push_back(a);
  }
  vector<int> v(n);
  for (int &i: v) cin >> i;

  bool bad = false;
  for (int i = 0; i < n; ++i) {
    set<int> smaller;
    for (int j: ed[i]) {
      if (v[j] == v[i]) bad = true;
      else if (v[j] > v[i]) continue;
      smaller.insert(v[j]);
    }
    if (sz(smaller) != v[i] - 1) bad = true;
  }

  if (bad) cout << "-1\n";
  else {
    vector<pii> pv(n);
    for (int i = 0; i < n; ++i) {
      pv[i] = pii(v[i], i);
    }
    sort(pv.begin(), pv.end());
    for (pii p: pv) {
      cout << p.se + 1 << " ";
    }
    cout << "\n";
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