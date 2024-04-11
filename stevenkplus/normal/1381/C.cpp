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
#define yc y_combinator;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

#define setmax(a, b) a = max(a, b)
// ============= Solution ============= //
int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(n);
    for (int &i: v) cin >> i;
    pp(v);
    vector<int> ans(n);

    // 1) compute FV = {freq, idx}[] // v[idx] is the freq-th occ of v[idx] in v
    vector<pii> FV(n);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      FV[i] = pii(++cnt[v[i]], i);
    }
    sort(FV.begin(), FV.end(), greater<>());
    pp(FV);

    // 2) for x idx's with largest freq to ans[idx] = v[idx]
    for (int i = 0; i < x; ++i) {
      int idx = FV[i].se;
      ans[idx] = v[idx];
    }

    // 3) compute CV where idx's are grouped by value
    int m = n - x;
    vector<pii> CV(m);
    for (int i = 0; i < m; ++i) {
      int idx = FV[i + x].se;
      CV[i] = (pii(v[idx], idx));
    }
    sort(CV.begin(), CV.end());
    pp(CV);

    // 4) compute RCV = CV rotated by sz(CV) / 2
    vector<int> RCV(m);
    for (int i = 0; i < m; ++i) {
      RCV[i] = CV[(i + m / 2) % m].fi;
    }
    pp(RCV);

    // 5) fill in n - y values of RCV with nocolor, prioritizing those i where CV[i].fi = RCV[i]
    int nocnt = 0;
    int nocolor = 1;
    while (cnt.count(nocolor)) ++nocolor;
    for (int i = 0; i < n - x; ++i) {
      if (CV[i].fi == RCV[i]) {
        RCV[i] = nocolor;
        ++nocnt;
      }
    }
    for (int i = 0; i < n - x; ++i) {
      if (RCV[i] != nocolor && nocnt < n - y) {
        RCV[i] = nocolor;
        ++nocnt;
      }
    }
    pp(RCV);

    // 6) set ans[CV[i].se] = RCV[i]
    for (int i = 0; i < m; ++i) {
      ans[CV[i].se] = RCV[i];
    }

    pp(v);
    pp(ans);
    int match = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i] == ans[i]) {
        ++match;
      }
    }
    if (nocnt != n - y || match != x) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i: ans) {
        cout << i << " ";
      }
      cout << "\n";
    }
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases