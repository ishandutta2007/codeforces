// AVX-enabled std::bitset Pragmas (before #includes!)
// - bitset<200000> takes ~ 1ms per 1000 operations on GNU C++14 & GNU C++17
// #pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
// #pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
// #pragma GCC target("avx2")  //Enable AVX

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
// =========== Solution ============= //
const int MAXN = 1001000;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (ll &i: a) cin >> i;
  for (ll &i: b) cin >> i;
  vector<char> s;
  ll op2 = 0;
  while (true) {
    int match1 = 0, match2 = 0;
    int up = 0, down = 0;
    for (int i = 0; i < n; ++i) {
      if (b[i] <= 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
      }
      if (a[i] == b[i]) ++match1;
      if (a[n - i - 1] == b[i]) ++match2;
      if (i + 1 < n && b[i] < b[i + 1]) ++up;
      if (i + 1 < n && b[i] > b[i + 1]) ++down;
    }
    if (match1 == n) {
      break;
    }
    if (match2 == n) {
      s.push_back('R');
      break;
    }
    if (n == 1) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    if (down == n - 1) {
      s.push_back('R');
      reverse(b.begin(), b.end());
      continue;
    }

    if (up == n - 1) {
      if (n == 2 && sz(s) > 2E5) {
        ll target = b[0]; // get < this number
        if (b[0] == a[0]) target = a[1] + 1;
        else if (b[0] == a[n - 1]) target = a[n - 2] + 1;
        if (b[1] < target) {
          cout << "IMPOSSIBLE\n";
          return 0;
        }
        ll take = (b[1] - target) / b[0] + 1;
        op2 += take;
        b[1] -= b[0] * take;
      } else {
        if (sz(s) <= 2E5)
          s.push_back('P');
        ++op2;
        for (int i = n - 1; i > 0; --i) {
          b[i] -= b[i - 1];
        }
      }
    } else {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }
  reverse(s.begin(), s.end());
  if (sz(s) > 2E5) {
    cout << "BIG\n";
    cout << op2 << "\n";
  } else {
    cout << "SMALL\n";
    cout << sz(s) << "\n";
    cout << string(s.begin(), s.end()) << "\n";
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN? different MAXN vs MAXM?)
// - special cases (n=1? graph not connected?)
// - sorting (input or ouput must be in particular order?)
// - initialize & re-initialize efficiently between test cases