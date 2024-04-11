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

// ============= Solution ============= //
int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &i: a) cin >> i, --i;
    for (int &i: b) cin >> i, --i;
    vector<int> r(n);
    vector<int> cnts(n);
    for (int i = 0; i < n; ++i) {
      ++cnts[a[i]];
      ++cnts[b[i]];
      r[a[i]] += i;
      r[b[i]] += i;
    }
    bool good = true;
    for (int i = 0; i < n; ++i) {
      if (cnts[i] != 2) good = false;
    }
    if (!good) {
      cout << "-1\n";
      continue;
    }

    vector<bool> vis(n);
    vector<bool> ansv(n);
    for (int i = 0; i < n; ++i) {
      if (vis[i]) continue;
      int cur = i;
      int cnt = 0;
      vector<int> v;
      do {
        pp(cur);
        pp(vis);
        vis[cur] = true;
        int prv = cur;
        pp(b);
        pp(b[cur]);
        pp(r[b[cur]]);
        cur = r[b[cur]] - cur;
        pp(cur);
        if (a[cur] != b[prv]) {
          swap(a[cur], b[cur]);
          ansv[cur] = true;
          ++cnt;
        }
        v.push_back(cur);
      } while (cur != i);
      pp(vis);
      if (sz(v) - cnt < cnt) {
        for (int i: v) {
          ansv[i] = !ansv[i];
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += ansv[i];
    cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
      if (ansv[i]) cout << i + 1 << " ";
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