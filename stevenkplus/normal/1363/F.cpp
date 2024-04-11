// AVX-enabled std::bitset Pragmas (before #includes!)
// - bitset<200000> takes ~ 1ms per 1000 operations on GNU C++14 & GNU C++17
// #pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
// #pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
// #pragma GCC target("avx2")  //Enable AVX

// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
// int __fastio = fastio();
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
// =========== Solution ============= //

#define mn(a,b) a=min(a,b)
int main() {
  int T;
  cin >> T;
  for (int _t = 1; _t <= T; ++_t) {
    int n;
    cin >> n;
    string sinp, tinp;
    cin >> sinp >> tinp;
    vector<int> s, t;
    for (int i = 0; i < n; ++i) {
      s.push_back(sinp[i] - 'a');
      t.push_back(tinp[i] - 'a');
    }
    vector<vector<int>> PS(30, vector<int>(n + 1)), PT(30, vector<int>(n + 1));
    vector<vector<int>> NXT(30, vector<int>(n + 1));
    for (int i = 0; i < 30; ++i) {
      NXT[i][n] = -1;
      for (int j = n - 1; j >= 0; --j) {
        NXT[i][j] = NXT[i][j + 1];
        if (t[j] == i) NXT[i][j] = j;
      }

      for (int j = 0; j < n; ++j) {
        PS[i][j + 1] = PS[i][j];
        if (s[j] == i) ++PS[i][j + 1];
        PT[i][j + 1] = PT[i][j];
        if (t[j] == i) ++PT[i][j + 1];
      }
    }
    bool bad = false;
    for (int i = 0; i < 30; ++i) {
      if (PS[i][n] != PT[i][n]) {
        bad = true;
      }
    }
    if (bad) {
      cout << "-1\n";
      continue;
    }

    vector<vector<int>> DP(n + 1, vector<int>(n + 1, inf));
    DP[0][0] = 0;
    for (int x = 0; x <= n; ++x) {
      for (int y = 0; y <= n; ++y) {
        // pp(x, y);
        if (y < n) mn(DP[x][y + 1], DP[x][y]);
        if (x == n) continue;
        int ch = s[x];
        int ny = NXT[ch][y];
        bool candelete = PT[ch][y] > PS[ch][x];
        // pp(x, y, ch, ny, candelete);
        if (candelete) {
          mn(DP[x + 1][y], DP[x][y] + 1);
        }
        if (ny != -1) {
          mn(DP[x + 1][ny + 1], DP[x][y]);
        }
      }
    }
    cout << DP[n][n] << "\n";
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