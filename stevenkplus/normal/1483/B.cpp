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

// ============= Solution ============= //
int main() { // dobby is a free elf
   int T;
   cin >> T;
   while (T--) {
      int n;
      cin >> n;

      vector<int> nxt(n), nxtlive(n);
      vector<bool> alive(n, 1), live(n, 1);

      vector<int> v(n);
      for (int &i: v) cin >> i;

      vector<int> ans;
      for (int i = 0; i < n; ++i) {
         nxt[i] = (i + 1) % n;
         nxtlive[i] = nxt[i];
      }
      int cur = 0;
      while (true) {
         pp(cur, live, alive);
         if (!live[cur]) break;

         if (_gcd(v[cur], v[nxt[cur]]) == 1) {
            ans.push_back(nxt[cur]);
            alive[nxt[cur]] = live[nxt[cur]] = false;
         } else {
            live[cur] = false;
         }

         while (nxt[cur] != cur && !alive[nxt[cur]]) {
            nxt[cur] = nxt[nxt[cur]];
         }
         while (nxtlive[cur] != cur && (!live[nxtlive[cur]] || !alive[nxtlive[cur]])) {
            nxtlive[cur] = nxtlive[nxtlive[cur]];
         }

         cur = nxtlive[cur];
      }

      cout << sz(ans);
      for (int i: ans) cout << " " << i + 1;
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