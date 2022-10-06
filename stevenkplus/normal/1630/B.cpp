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
// reforumlation:
// find [x, y] such that number of elements a_i in the array x <= a_i <= y is at least (n + k) / 2
// minimize y - x
// note that x = a_i and y = a_{i + kk - 1} if a is sorted, where kk = ceil((n + k) / 2)

const int inf = 1000 << 20;
int main() {
   int T;
   cin >> T;
   while (T--) {
      int n, k;
      cin >> n >> k;
      vector<int> v(n);
      for (int &i: v) cin >> i;
      vector<int> w = v;
      sort(v.begin(), v.end());
      int ans = inf, x = -1, y = -1;
      int kk = (n + k + 1) / 2;
      for (int i = 0; i + kk - 1 < n; ++i) {
         if (v[i + kk - 1] - v[i] < ans) {
            ans = v[i + kk - 1] - v[i];
            x = v[i];
            y = v[i + kk - 1];
         }
      }
      v = w;
      cout << x << " " << y << "\n";
      int cnt = 0;
      cout << "1 ";
      for (int i = 0; i < n; ++i) {
         if (v[i] >= x && v[i] <= y) ++cnt;
         else --cnt;
         if (cnt > 0 && k > 1) {
            cout << i + 1 << "\n" << i + 2 << " ";
            --k;
            cnt = 0;
         }
      }
      cout << n << "\n";
   }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases