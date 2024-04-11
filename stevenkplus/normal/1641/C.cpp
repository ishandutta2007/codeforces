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

// ============= Solution ============= //
// t=0 x=0 -> erase from s
// t=0 x=1 -> ar[(l, r)] += 1
// t=1, j not in s -> "NO"
// t=1, j in s -> "YES" if ask((l, l), (r, r)) > 0 else "N/A", where s = {..., l, j, r}

int main() {
   int n, q;
   cin >> n >> q;
   int size = 1;
   while (size <= n + 1) size *= 2;
   vector<int> seg(size * 2, {n + 1});
   pp(seg);
   set<int> s;
   for (int i = 1; i <= n; ++i) {
      s.insert(i);
   }
   s.insert(0);
   s.insert(n + 1);
   while (q--) {
      int t;
      cin >> t;
      if (t == 0) {
         int l, r, x;
         cin >> l >> r >> x;
         if (x == 0) {
            auto it = s.lower_bound(l);
            while (*it <= r) {
               s.erase(it++);
            }
         } else {
            for (int i = l + size; i; i /= 2) {
               seg[i] = min(seg[i], r);
               pp(i, seg[i], r);
            }
         }
      } else {
         int j;
         cin >> j;
         auto it = s.find(j);
         if (it == s.end()) {
            cout << "NO\n";
            continue;
         }
         int l = *--it;
         ++l;
         ++it;
         int r = *++it;
         pp(j, l, r);
         bool found = false;
         auto check = [&](int x) {
            if (seg[x] < r) {
               found = true;
            }
         };
         for (int a = l + size, b = r + size; a < b; a /= 2, b /= 2) {
            if (a & 1) {
               check(a++);
            }
            if (b & 1) {
               check(--b);
            }
         }
         if (found) {
            cout << "YES\n";
         } else {
            cout << "N/A\n";
         }
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