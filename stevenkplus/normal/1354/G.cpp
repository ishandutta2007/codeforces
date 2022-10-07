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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

const int inf = 1000 << 20;
const ll infl = 1LL << 60;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// ============= Solution ============= //

int query(vector<int> left, vector<int> right) {
  cout << "? " << sz(left) << " " << sz(right) << "\n";
  for (int i: left) cout << i << " ";
  cout << "\n";
  for (int i: right) cout << i <<  " ";
  cout << endl;
  string s;
  cin >> s;
  if (s == "FIRST") return 1;
  else if (s == "EQUAL") return 0;
  else if (s == "SECOND") return -1;
  else throw "";
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n, k;
    cin >> n >> k;
    // pick 20 random
    int rand = 20;
    vector<int> cands(rand);
    for (int i = 0; i < rand; ++i) {
      cands[i] = rng() % n + 1;
    }
    pp(cands);
    int c = cands[0];
    for (int i = 1; i < rand; ++i) {
      if (c == cands[i]) continue;
      if (query({c}, {cands[i]}) == -1) {
        c = cands[i];
      }
    }

    int q = c == 1 ? 0 : query({c}, {1});
    if (q == 1) {
      cout << "! 1" << endl;
      continue;
    }

    int lo, hi;
    for (int i = 0; i < 10; ++i) {
      int size = 1 << i;
      lo = size + 1;
      hi = size * 2;
      if (size * 2 > n) {
        hi = n;
        break;
      }
      vector<int> v1(size), v2(size);
      for (int i = 0; i < size; ++i) {
        v1[i] = 1 + i;
      }
      for (int i = 0; i < size; ++i) {
        v2[i] = 1 + size + i;
      }
      int q = query(v1, v2);
      if (q == 1) {
        break;
      }
    }

    while (lo < hi) {
      int mid = (lo + hi) / 2;
      int size = mid - lo + 1;
      vector<int> v1(size), v2(size);
      for (int j = 0; j < size; ++j) {
        v1[j] = j + 1;
        v2[j] = lo + j;
      }
      int q = query(v1, v2);
      if (q == 1) hi = mid;
      else lo = mid + 1;
    }
    cout << "! " << lo << endl;
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases