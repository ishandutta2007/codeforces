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

const vector<int>digits({
  0b1110111,
  0b0010010,
  0b1011101,
  0b1011011,
  0b0111010,
  0b1101011,
  0b1101111,
  0b1010010,
  0b1111111,
  0b1111011
});

int main() {
  pp(digits);
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int &i: v) {
    string s;
    cin >> s;
    for (char c: s) {
      i = 2 * i + c - '0';
    }
  }
  pp(v);

  vector<vector<bool>> can(n + 1, vector<bool>(k + 1, false));
  can[n][0] = true;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j <= k; ++j) {
      for (int x = 0; x <= 9; ++x) {
        if ((digits[x] & v[i]) == v[i]) {
          int diff = __builtin_popcount(digits[x] ^ v[i]);
          if (j < diff) continue;
          can[i][j] = can[i][j] || can[i + 1][j - diff];
        }
      }
    }
  }
  pp(can);

  if (!can[0][k]) cout << -1 << "\n";
  else {
    for (int i = 0; i < n; ++i) {
      for (int x = 9; x >= 0; --x) {
        if ((digits[x] & v[i]) == v[i]) {
          int diff = __builtin_popcount(digits[x] ^ v[i]);
          if (diff <= k && can[i + 1][k - diff]) {
            k -= diff;
            cout << x;
            break;
          }
        }
      }
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