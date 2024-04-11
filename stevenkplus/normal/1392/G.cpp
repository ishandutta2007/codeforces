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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// ============= Solution ============= //
const int inf = 1000 << 20;
int main() {
   int n, m, k;
   cin >> n >> m >> k;
   string sinp, tinp;
   cin >> sinp >> tinp;
   int s = 0, t = 0;
   for (int i = 0; i < k; ++i) {
      if (sinp[i] == '1') {
         s += 1 << i;
      }
      if (tinp[i] == '1') {
         t += 1 << i;
      }
   }

   vector<pii> v(n);
   for (pii &p: v) cin >> p.fi >> p.se, --p.fi, --p.se;

   auto get = [&](int x) -> vector<int> {
      vector<int> res(n + 1);
      vector<int> to(k);
      for (int i = 0; i < k; ++i) to[i] = i;
      for (int i = 0; i <= n; ++i) {
         int msk = 0;
         for (int j = 0; j < k; ++j) {
            if ((x >> j) & 1) {
               msk |= 1 << to[j];
            }
         }
         res[i] = msk;
         if (i < n) {
            pii p = v[i];
            swap(to[p.fi], to[p.se]);
         }
      }
      return res;
   };

   pp(n, m, k);
   pp(s, t);
   vector<int> a = get(s), b = get(t);
   vector<int> minStart(1 << k, inf);
   for (int i = n; i >= 0; --i) {
      minStart[a[i]] = i;
   }
   pp(a, b);
   for (int ans = 0; ans <= k; ++ans) {
      for (int i = 0; i <= n; ++i) {
         if (minStart[b[i]] + m <= i) {
            cout << k - ans << "\n";
            cout << minStart[b[i]] + 1 << " " << i << "\n";
            return 0;
         }
      }
      vector<int> nminStart = minStart;
      for (int j = 0; j < (1 << k); ++j) {
         for (int i = 0; i < k; ++i) {
            nminStart[j] = min(nminStart[j], minStart[j ^ (1 << i)]);
         }
      }
      minStart = nminStart;
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases