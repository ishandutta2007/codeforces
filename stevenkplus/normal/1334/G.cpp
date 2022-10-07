#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX
// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#else
#define pp(...)
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

// ============= Solution ============= //



const int MAXN = 200100;
typedef bitset<MAXN> BS;

int main() {
  vector<int> mp(26);
  for (int &i: mp) cin >> i, --i;
  vector<int> imp(26);
  for (int i = 0; i < 26; ++i) imp[mp[i]] = i;
  string sinp, tinp;
  cin >> sinp >> tinp;
  int n = sz(sinp), m = sz(tinp);
  vector<int> s(n), t(m);
  for (int i = 0; i < n; ++i) s[i] = sinp[i] - 'a';
  for (int i = 0; i < m; ++i) t[i] = tinp[i] - 'a';
  vector<BS> v(26);
  for (int i = 0; i < m; ++i) {
    v[t[i]][i] = 1;
    v[imp[t[i]]][i] = 1;
  }
  for (char c = 'a'; c <= 'c'; ++c) {
    vector<int> b(m);
    for (int i = 0; i < m; ++i) b[i] = v[c - 'a'][i];
    pp(c, b);
  }
  BS ans;
  for (int i = 0; i <= m - n; ++i) ans[i] = 1;
  for (int i = 0; i < n; ++i) {
    ans &= v[s[i]] >> i;
  }
  for (int i = 0; i <= m - n; ++i) {
    cout << ans[i];
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