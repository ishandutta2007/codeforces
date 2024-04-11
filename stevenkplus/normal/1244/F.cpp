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
const ll infl = 1LL << 60;

void main2(int n, int k, string s) {
  for (int rep = 0; rep < k; ++rep) {
    string t;
    for (int j = 0; j < n; ++j) {
      vector<char> v;
      for (int d = -1; d <= 1; ++d) {
        v.push_back(s[(j + n + d) % n]);
      }
      sort(v.begin(), v.end());
      t += v[1];
    }
    s = t;
  }
  cout << s << "\n";
}

// ============= Solution ============= //
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  // main2(n, k, s);
  // return 0;
  vector<int> v(2 * n);
  for (int i = 0; i < n; ++i) {
    v[i] = s[i] == 'W';
    v[i + n] = v[i];
  }
  vector<int> prv(2 * n), nxt(2 * n);
  prv[0] = -1;
  for (int i = 1; i < 2 * n; ++i) {
    prv[i] = prv[i - 1];
    if (v[i] == v[i - 1]) {
      prv[i] = i;
    }
  }
  nxt[2 * n - 1] = -1;
  for (int i = 2 * n - 2; i >= 0; --i) {
    nxt[i] = nxt[i + 1];
    if (v[i] == v[i + 1]) {
      nxt[i] = i;
    }
  }
  pp(prv);
  pp(nxt);
  bool alternating = prv[2 * n - 1] == -1;
  for (int i = 0; i < n; ++i) {
    int ans;
    if (alternating) {
      ans = v[i] ^ (k & 1);
    } else {
      int distLeft = i + n - prv[i + n];
      int distRight = nxt[i] - i;
      if (min(distLeft, distRight) > k) ans = v[i] ^ (k & 1);
      else if (distLeft < distRight) ans = v[prv[i + n]];
      else ans = v[nxt[i]];
    }
    if (ans == 0) cout << 'B';
    else cout << 'W';
  }
  cout << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases

// - initialize & re-initialize efficiently between test cases