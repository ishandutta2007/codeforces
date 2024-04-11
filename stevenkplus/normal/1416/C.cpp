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

#define mx(a, b) a = max(a, b)
#define sub_to_errichto main
const int inf = 1000 << 20;

// ============= Solution ============= //
int sub_to_errichto() {
   int n;
   cin >> n;
   vector<int> v(n);
   for (int &i: v) cin >> i;
   vector<ll> cnt1(30);
   vector<ll> cnt2(30);
   vector<int> vec(1 << 24);
   for (int j = 0; j < 30; ++j) {
      map<int, int> mp;
      for (int i = 0; i < n; ++i) {
         int msk = v[i] >> j;
         int omsk = msk ^ 1;
         int val;
         if (j < 6) {
            val = mp[omsk];
            ++mp[msk];
         } else {
            val = vec[omsk];
            ++vec[msk];
         }
         if (msk > omsk) {
            cnt1[j] += val;
         } else {
            cnt2[j] += val;
         }
      }
      if (j >= 6) {
         for (int i = 0; i < n; ++i) {
            int msk = v[i] >> j;
            vec[msk] = 0;
         }
      }
   }
   pp(cnt1, cnt2);
   int x = 0;
   ll ans = 0;
   for (int i = 0; i < 30; ++i) {
      if (cnt1[i] < cnt2[i]) {
         ans += cnt1[i];
         x += 1 << i;
      } else {
         ans += cnt2[i];
      }
   }

   cout << ans << " " << x << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases