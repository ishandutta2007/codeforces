// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
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


// ========== Solution ========== //

int main() {
  int n, k;
  cin >> n >> k;
  string sinp; cin >> sinp;
  vector<int> inp(n);
  for (int i = 0; i < n; ++i) inp[i] = sinp[i] == 'R';
  vector<vector<int>> ans;
  int tot = 0;
  for (int i = 0; i <= n; ++i) {
    pp(inp);
    vector<int> v;
    for (int j = 0; j + 1 < n; ++j) {
      if (inp[j] > inp[j + 1]) {
        v.push_back(j);
        swap(inp[j], inp[j + 1]);
        ++j;
      }
    }
    if (!sz(v)) break;
    ans.push_back(v);
    tot += sz(v);
  }
  pp(ans);
  if (sz(ans) > k) cout << "-1\n";
  else if (tot < k) cout << "-1\n";
  else {
    int rem = sz(ans);
    for(auto v: ans) {
      int i = 0;
      while (i < sz(v)) {
        int take = 1;
        if (rem == k) take = sz(v) - i;
        cout << take;
        for (int j = 0; j < take; ++j) {
          cout << " " << v[i] + 1;
          ++i;
        }
        cout << "\n";
        --k;
      }
      --rem;
    }
  }
}