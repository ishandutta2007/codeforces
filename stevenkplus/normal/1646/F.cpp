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
// phase 1: make it so everyone has 1...n
// - start from some person i that is not done, then go to the right
// - pass any card that is a dup
// - if done, then pass the card that you are receiving from left
// claim: phase 1 will take at most n*(n-1)/2 turns
// - person i, card j, let k(j) be the farthest distance that any card j that eventually made it into i's hands had to travel before getting there
// - for each i, {k(1)...k(n)} >= {0...n-1}
// - person i will pass card j at most n-1-k times before he is done (he and the k to left will each save at least one copy of card j, so there are only n-k-1 passable copies of the card)
// - so number of rounds is bounded by 0+...+n-1 = n*(n-1)/2
// phase 2: make it so i has {i} x n
// - for r = 1...n-1 incl:
// - - for k = r...1 incl:
// - - - person i passes card i + k to the right
// claim: phase 2 will take exactly 1+...+(n-1) = n*(n-1)/2 rounds
//
// in total, n(n-1) = n^2-n rounds -- just barely small eough
int main() {
   int n;
   cin >> n;
   vector<vector<int>> v(n, vector<int>(n));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         int x; cin >> x; --x;
         ++v[i][x];
      }
   }

   auto ok = [&](int cur) -> bool {
      for (int i = 0; i < n; ++i) if (v[cur][i] != 1) return false;
      return true;
   };

   vector<vector<int>> moves;
   // phase 1
   while (true) {
      int cur = 0;
      while (cur < n && ok(cur)) ++cur;
      if (cur == n) break;

      moves.push_back(vector<int>(n));
      for (int _i = 0; _i < n; ++_i) {
         int i = (cur + _i) % n;
         int j;
         for (j = 0; j < n; ++j) {
            if (v[i][j] > 1) break;
         }

         moves.back()[i] = j;
         v[i][j] -= 1;
         v[(i + 1) % n][j] += 1;
      }
   }

   // phase 2
   for (int r = 1; r < n; ++r) {
      for (int k = r; k >= 1; --k) {
         moves.push_back(vector<int>(n));
         for (int i = 0; i < n; ++i) {
            moves.back()[i] = (i + k) % n;
         }
      }
   }

   cout << sz(moves) << "\n";
   for (auto p: moves) {
      for (int i: p) {
         cout << i + 1 << " ";
      }
      cout << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases