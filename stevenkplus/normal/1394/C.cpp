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

// ============= Solution ============= //
int main() {
  int n;
  cin >> n;
  vector<string> v(n);
  for (string &s: v) cin >> s;
  vector<int> L(n), X(n), Y(n);
  int mx = inf, Mx = -inf, my = inf, My = -inf, mxy = inf, Mxy = -inf;
  for (int i = 0; i < n; ++i) {
    L[i] = sz(v[i]);
    for (char c: v[i]) {
      if (c == 'B') ++X[i];
      else ++Y[i];
    }
    mx = min(mx, X[i]);
    Mx = max(Mx, X[i]);
    my = min(my, Y[i]);
    My = max(My, Y[i]);
    mxy = min(mxy, X[i] - Y[i]);
    Mxy = max(Mxy, X[i] - Y[i]);
  }

  pp(mx, Mx, my, My, mxy, Mxy);
  for (int k = 0; k <= 5E5; ++k) {
    int x1 = Mx - k, x2 = mx + k, y1 = My - k, y2 = my + k;
    if (x1 > x2 || y1 > y2) continue;
    int xy1 = Mxy - k, xy2 = mxy + k;
    vector<int> v({xy1, xy2, x1 - y2, x2 - y1});
    pp(v);
    sort(v.begin(), v.end());
    int x, y;
    bool good = false;
    pp(x1, x2, y1, y2, xy1, xy2);
    for (int xy = v[1]; xy <= v[1] + 1; ++xy) {
      if (xy < x1 - y2 || xy < xy1 || xy > x2 - y1 || xy > xy2) continue;
      pp(xy);
      for (x = x1; x <= x2; ++x) {
        y = x - xy;
        if (x == 0 && y == 0) continue;
        if (y >= y1 && y <= y2) {
          pp(x, y, good);
          good = true;
          break;
        }
      }
      if (good) break;
    }
    if (!good) continue;
    string ans;
    for (int i = 0; i < x; ++i) {
      ans += 'B';
    }
    for (int i = 0; i < y; ++i) {
      ans += 'N';
    }
    cout << k << "\n";
    cout << ans << "\n";
    break;
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases