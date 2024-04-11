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
#define sub_to_errichto main
// =========== Book ============ //

// ============= Solution ============= //
int sub_to_errichto() {
   // one of the two are guaranteed to exist:
   // x_i = 0
   // x_i = x_j
   //
   // start by computing xor between every pair (in n - 1) queries.
   // if x_i = x_j, then x_i | x_j tells you the value, and you're done (in only n queries)
   // if no values are equal, then guaranteed that array is a permutation of 0...n-1... two more queries
   // find a, b, c s.t. a^b = 1, a^c=n-1
   // then, a & b = min(a, b)
   // b&c&1 = 1 iff a = min(a, b)

   int n;
   cin >> n;
   vector<int> xors(n);
   auto ask = [&](string s, int a, int b) -> int {
      cout << s << " " << a + 1 << " " << b + 1 << endl;
      int res;
      cin >> res;
      return res;
   };

   vector<int> v(n);
   map<int, int> mp;
   pii zero;
   pii p = zero;
   mp[0] = 0;
   for (int i = 1; i < n; ++i) {
      xors[i] = ask("XOR", 0, i);
      if (mp.count(xors[i])) {
         p = pii(i, mp[xors[i]]);
      }
      mp[xors[i]] = i;
   }

   int found;
   if (p != zero) {
      v[p.fi] = ask("OR", p.fi, p.se);
      found = p.fi;
   } else {
      int a = 0;
      int b = mp[1];
      int c = mp[n - 1];
      v[a] = ask("AND", a, b);
      v[b] = v[a] + 1;
      if ((ask("AND", b, c) & 1) == 0) {
         swap(v[a], v[b]);
      }
      found = a;
   }
   for (int i = 0; i < n; ++i) {
      v[i] = v[found] ^ xors[found] ^ xors[i];
   }

   cout << "!";
   for (int i: v) {
      cout << " " << i;
   }
   cout << endl;
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases