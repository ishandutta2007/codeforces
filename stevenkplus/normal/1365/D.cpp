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
const ll infl = 1LL << 60;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// ============= Solution ============= //

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n, m;
    cin >> n >> m;
    vector<string> inp(n);
    for (auto &s: inp) cin >> s;
    int exit = n * m - 1;
    int size = n * m;
    vector<int> par(size);
    for (int i = 0; i < size; ++i) {
      par[i] = i;
    }
    auto find = y_combinator([&](auto find, int x) -> int {
      if (par[x] == x) return x;
      return par[x] = find(par[x]);
    });
    auto join = [&](int a, int b) -> void {
      a = find(a); b = find(b);
      par[a] = b;
    };
    int di[] = {0, 0, 1, -1};
    int dj[] = {1, -1, 0, 0};
    vector<vector<bool>> good(n, vector<bool>(m, true));
    string ans = "Yes";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (inp[i][j] == '#') good[i][j] = false;
        else if (inp[i][j] == 'B') {
          good[i][j] = false;
          for (int k = 0; k < 4; ++k) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            good[ni][nj] = false;
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int x = i * m + j;
        if (good[i][j]) {
          for (int k = 0; k < 4; ++k) {
            int ni = i + di[k], nj = j + dj[k];
            int nx = ni * m + nj;
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            if (good[ni][nj]) join(x, nx);
          }
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int x = i * m + j;
        if (inp[i][j] == 'G') {
          if (find(x) != find(exit)) {
            ans = "No";
          }
        }
      }
    }
    cout << ans << "\n";
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases