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

const ll infl = 1LL << 60;
// ============= Solution ============= //
int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n;
    ll l, r;
    cin >> n >> l >> r;
    --l;

    ll sum = 0;
    for (int row = 1; row <= n; ++row) {
      int val = 2 * (n - row);
      if (row == n) val = 1;
      if (l < sum + val && sum < r) {
        for (int i = 0; i < val; ++i) {
          if (l <= sum + i && sum + i < r) {
            int x = i % 2 == 0 ? row : (i / 2) + row + 1;
            if (row == n) x = 1;
            cout << x << " ";
          }
        }
      }
      sum += val;
    }
    cout << "\n";
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases