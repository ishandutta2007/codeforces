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
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
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
#define yc y_combinator
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

struct node {
   int sum, min, max;
};

node operator+(node a, node b) {
   return { a.sum + b.sum, min(a.min, a.sum + b.min), max(a.max, a.sum + b.max) };
}

node ZERO = { 0, 0, 0 };
// ============= Solution ============= //
int main() { // dobby is a free elf
   int T;
   cin >> T;
   while (T--) {
      int n, m;
      cin >> n >> m;
      string s;
      cin >> s;
      int size = 1;
      while (size < n) size *= 2;
      pp(size);
      vector<node> seg(size * 2, ZERO); // init to zero
      for (int i = 0; i < n; ++i) {
         int x = s[i] == '-' ? -1 : 1;
         seg[size + i] = seg[size + i] + node({ x, x, x });
      }
      for (int i = size - 1; i > 0; --i) {
         seg[i] = seg[i * 2] + seg[i * 2 + 1];
      }

      int HEIGHT = 20;
      pp(HEIGHT);
      auto ask = [&](int l, int r) -> node {
         pp(l, r);
         vector<node> left, right;
         left.reserve(HEIGHT);
         right.reserve(HEIGHT);
         // https://codeforces.com/blog/entry/18051 efficient and easy segtree
         for (l += size, r += size; l < r; l /= 2, r /= 2) {
            if (l & 1) left.push_back(seg[l++]);
            if (r & 1) right.push_back(seg[--r]);
         }
         reverse(right.begin(), right.end());
         node res = ZERO;
         for (node cur: left) res = res + cur; // non-commutative op, maintain order
         for (node cur: right) res = res + cur;
         pp(res.sum, res.min, res.max);
         return res;
      };

      for (int i = 0; i < m; ++i) {
         int l, r;
         cin >> l >> r; --l;
         pp(l, r);
         node ans = ask(0, l) + ask(r, n);
         cout << ans.max - ans.min + 1 << "\n";
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