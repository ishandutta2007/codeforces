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

int _gcd(int a, int b) {
   if (!a) return b;
   return _gcd(b % a, a);
}
typedef pair<int, pii> plii;
const int inf = 1000 << 20;

// ============= Solution ============= //
int main() { // dobby is a free elf
   int T;
   cin >> T;
   while (T--) {
      ll M = T * 1E13;
      // pp(M);

   vector<double> P = {1};
   for (int i = 0; i < 1000; ++i) {
      P.push_back(1 - .25 / P.back());
   }
   auto Pfn = [&](double d) -> double {
      return 0.5 + 1. / (2 * d + 2);
   };

   // pp(P);
   ll money = 1;
   ll lo = 0, hi = 1E14 + 1;
   int guesses = 0;
   auto guess = [&](ll x) {
      ++guesses;
      cout << "? " << x << endl;
      string s;
      if (x > M) s = "F";
      else s = "L";
      pp(x, s);
      cin >> s;
      if (s[0] == 'L') {
         lo = x;
         money += x;
      } else {
         hi = x;
         money -= x;
      }
   };

   while (hi > 1E14 && lo * 2 < hi) {
      // guess(max(1LL, money - 1));
      guess(min(ll(1E14), max(1LL, money)));
   }

   while (lo + 1 < hi) {
      ll idx = money / lo;
      if (idx) {
         // pp(money, lo, hi);
         long double p = Pfn(idx);
         ll k = min(money, max(lo + 1, ll(hi - (hi - lo) * p)));
         // pp(p, k);
         guess(k);
      } else {
         guess(lo); // too poor to learn anything
      }
   }

   cout << "! " << lo << endl;
   pp(guesses);
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases