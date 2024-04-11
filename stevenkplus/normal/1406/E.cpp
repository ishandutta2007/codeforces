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
int main() {
   auto queryA = [&](int x) -> int {
      cout << "A " << x << endl;
      int res;
      cin >> res;
      return res;
   };

   auto queryB = [&](int x) {
      cout << "B " << x << endl;
      int res;
      cin >> res;
   };
   auto queryC = [&](int x) {
      cout << "C " << x << endl;
   };

   int n;
   cin >> n;
   vector<int> smallPrimes, largePrimes, allPrimes;
   vector<bool> sieve(n + 1);
   for (ll i = 2; i <= n; ++i) {
      if (sieve[i]) continue;
      if (i * i > n) {
         largePrimes.push_back(i);
      } else {
         smallPrimes.push_back(i);
      }
      allPrimes.push_back(i);

      for (ll j = i * i; j <= n; j += i) {
         sieve[j] = true;
      }
   }
   pp(smallPrimes);
   pp(largePrimes);

   auto phase1 = [&]() -> bool {
      for (int p: smallPrimes) {
         queryB(p);
      }
      int cnt = queryA(1);
      return cnt == 1 + sz(largePrimes);
   };

   auto phase2 = [&]() -> int {
      ll ans = 1;
      for (ll i: allPrimes) {
         ll j = i;
         int expected = 0;
         if (i * i > n) ++expected;
         while (j <= n) {
            if (queryA(j) == expected + 1) {
               ans *= i;
            }
            j *= i;
         }
      }
      return ans;
   };

   auto phase3 = [&]() -> int {
      vector<int> recent;
      int remaining = sz(largePrimes);
      for (int i: largePrimes) {
         queryB(i);
         --remaining;
         recent.push_back(i);
         if (sz(recent) >= 100 || remaining == 0) {
            if (queryA(1) > 1 + remaining) {
               for (int j: recent) {
                  if (queryA(j) == 1) {
                     return j;
                  }
               }
            }
            recent.clear();
         }
      }
      return 1;
   };


   int ans;
   if (phase1()) {
      ans = phase3();
   } else {
      ans = phase2();
   }

   pp(ans);
   queryC(ans);

}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases