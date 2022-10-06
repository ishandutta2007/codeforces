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
  int h, q;
  cin >> h >> q;
  int n = 1 << h;
  vector<ll> v(n);
  for (ll &i: v) cin >> i;
  vector<ll> seg(2 * n);
  for (int i = 0; i < n; ++i) {
    seg[i + n] = v[i];
  }
  for (int i = n - 1; i > 0; --i) {
    seg[i] = seg[i * 2] + seg[i * 2 + 1];
  }

  auto set = [&](int x, int k) -> void {
    x += n;
    seg[x] = k;
    for (x /= 2; x > 0; x /= 2) {
      seg[x] = seg[x * 2] + seg[x * 2 + 1];
    }
  };
  pp(seg);
  int msk = 0;
  for (int i = 0; i < q; ++i) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, k;
      cin >> x >> k;
      --x;
      set(x ^ msk, k);
    } else if (type == 2) {
      int k;
      cin >> k;
      msk ^= (1 << k) - 1;
    } else if (type == 3) {
      int k;
      cin >> k;
      msk ^= 1 << k;
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      ll sum = 0;
      int m = msk;
      for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) sum += seg[m ^ (l++)];
        if (r & 1) sum += seg[m ^ (--r)];
        m /= 2;
      }
      cout << sum << "\n";
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