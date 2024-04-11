// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { string sep = "{"; for (auto e: v) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define pp(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

// =========== Book ============ //

// =========== Solution ============= //

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> a;
  vector<int> nxt(n);
  for(int i = 0; i < n; ++i) {
    if (s[i] == '0') a.push_back(i);
    else {
      if (a.size() == 0) {
        cout << "-1\n";
        return 0;
      }
      int j = a.back();
      a.pop_back();
      nxt[j] = i;
    }
  }
  a.clear();
  for(int i = n - 1; i >= 0; --i) {
    if (s[i] == '0') a.push_back(i);
    else {
      if (a.size() == 0) {
        cout << "-1\n";
        return 0;
      }
      int j = a.back();
      a.pop_back();
      nxt[i] = j;
    }
  }

  vector<vector<int>> ans;
  vector<bool> vis(n);
  for(int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    vector<int> v;
    int cur = i;
    do {
      vis[cur] = true;
      v.push_back(cur);
      cur = nxt[cur];
    } while (cur);
    ans.push_back(v);
  }
  cout << ans.size() << "\n";
  for (auto v: ans) {
    cout << v.size() << " ";
    for (auto i: v) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN? different MAXN vs MAXM?)
// - special cases (n=1? graph not connected?)
// - initialize & re-initialize efficiently between test cases
//
// history of bugs
// - 3/28/20 forgot to initialize set with dummy node (n) [cf 1136e]
// - 3/28/20 array bounds (map was size MAXN instead of MAXK) [cf 1210b]