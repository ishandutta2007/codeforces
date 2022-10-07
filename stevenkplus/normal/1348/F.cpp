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

// ============= Solution ============= //
int main() {
  int n;
  cin >> n;
  vector<pii> v(n);
  for (auto &p: v) cin >> p.fi >> p.se;
  vector<pii> v_ord(n);
  for (int i = 0; i < n; ++i) {
    v_ord[i] = pii(v[i].fi, i);
  }
  sort(v_ord.begin(), v_ord.end());

  vector<int> ans(n); // ans[i] -> who sits in seat i
  set<pii> s; // contains "seats" -- pii(b_i, i)
  int j = 0;
  for (int i = 1; i <= n; ++i) {
    while (j < n && v_ord[j].fi <= i) {
      int idx = v_ord[j].se;
      s.insert(pii(v[idx].se, idx));
      ++j;
    }
    pii p = *s.begin();
    s.erase(s.begin());
    ans[p.se] = i;
  }
  vector<int> ans_inv(n + 1); // ans_inv[i] -> seat of person i
  vector<int> ans2;
  bool found = false;
  for (int i = 0; i < n; ++i) ans_inv[ans[i]] = i;

  int size = 1;
  while (size <= n) size *= 2;
  vector<int> seg(2 * size);
  pp(v);

  for (int i = 1; i <= n; ++i) {
    int s = ans_inv[i];
    // ask(v[s].fi, i)
    int y = 0;
    for (int l = size + v[s].fi, r = size + i; l < r; l /= 2, r /= 2) {
      if (l & 1) y = max(y, seg[l++]);
      if (r & 1) y = max(y, seg[--r]);
    }
    pp(s, v[s].fi, i, y);
    if (y >= i) {
      for (int j = v[s].fi; j < i; ++j) {
        int t = ans_inv[j];
        if (v[t].se >= i) {
          ans2 = ans;
          swap(ans2[s], ans2[t]);
          break;
        }
      }
      found = true;
      break;
    }
    // insert(i, v[s].se)
    for (int x = size + i; x > 0; x /= 2) seg[x] = max(seg[x], v[s].se);
  }

  if (found) cout << "NO\n";
  else cout << "YES\n";
  for (int i: ans) cout << i << " ";
  cout << "\n";
  if (found) {
    for (int i: ans2) cout << i << " ";
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