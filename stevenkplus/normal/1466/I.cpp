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

// ============= Solution ============= //
int main() {
   int N, B;
   cin >> N >> B;
   // state (n,b) -> 2^b...2^{b+n-1}
   // state: A(n, b) -> n numbers, smallest one is b, the rest are b+1...b+n-1
   // state: B(n, b) -> n numbers, smallest one is b-1, the rest are b+1...b+n-1
   // lo: binary string representing current ans
   // A(n, b) -> query lo + 2^(b-1)
   //   yes -> lo = lo + 2^(b-1), state = B(n, b)
   //   no -> state = A(n, b - 1)
   // B(n, b) -> query lo + 2^b
   //   yes -> lo = lo + 2^b, state = B(n - 1, b + 1)
   //   no -> state = A(n, b - 1)
   // the quantity isA + 3n + 2b decreases monotonically

   bool isA = true;
   int n = N, b = B;
   vector<int> v(n);
   for (int i = 0; i < n; ++i) {
      v[i] = i + 1;
   }
   string lo = "";
   for (int i = 0; i < b; ++i) {
      lo += "0";
   }

   auto add = [&](string s, int b) -> string {
      while (s[B - 1 - b] == '1') {
         s[B - 1 - b] = '0';
         ++b;
      }
      if (b < B) s[B - 1 - b] = '1';
      return s;
   };

   auto pred = [&](string s) -> string {
      for (int i = B - 1; i >= 0; --i) {
         if (s[i] == '0') ++s[i];
         else {
            --s[i];
            break;
         }
      }
      return s;
   };

   auto ask = [&](int x, int b) -> bool {
      pp(lo, x, b);
      bool ok = false;
      for (int i = 0; i < B - b; ++i) {
         if (lo[i] == '0') {
            ok = true;
            break;
         }
      }
      if (!ok) {
         return false;
      }
      if (b >= B) {
         return false;
      }
      if (b < 0) {
         return true;
      }
      cout << x << " " << pred(add(lo, b)) << endl;
      string r;
      cin >> r;
      return r[0] == 'y';
   };

   while (n) {
      int x = v[0];
      pp(lo, b, isA);
      if (isA) {
         if (ask(x, b - 1)) {
            lo = add(lo, b - 1);
            isA = false;
         } else {
            --b;
            v.erase(v.begin(), v.begin() + 1);
            v.push_back(x);
         }
      } else {
         if (ask(x, b)) {
            lo = add(lo, b);
            --n;
            ++b;
            v.pop_back();
         } else {
            isA = true;
            --b;
            v.erase(v.begin(), v.begin() + 1);
            v.push_back(x);
            swap(v.back(), v.end()[-2]);
         }
      }
      if (b <= 0) {
         --n;
         v.pop_back();
         ++b;
      }
      if (n == 1 && !isA) {
         isA = true;
         --b;
      }
   }

   cout << "0 " << lo << endl;

}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases