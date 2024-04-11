// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

// =========== Book ============ //

int fastio() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cin.tie(0);
  return 0;
}
int __fastio = fastio();

namespace debugprint {
  template<typename T> void pp(T el, string end) { cerr << el << end; }
  template<typename T> void pp(vector<T> &v, string end) {
    cerr << "[";
    string sep = "";
    for (auto e: v) {
      cerr << sep;
      pp(e, "");
      sep = ", ";
    }
    cerr << "]" << end;
  }
  template<typename T> void pp(T el) { pp(el, "\n"); }
}
using namespace debugprint;

// =========== Solution ============= //

// given a len n, returns v s.t.
// v[i] -> min len prefix of b that contains a[:i] as subseq
vector<int> f(string a, string b) {
  int n = a.size();
  vector<int> ret(n + 1);
  int j = 0;
  for (int i = 0; i < n; ++i) {
    while (b[j] != a[i]) ++j;
    ret[i + 1] = j + 1;
    ++j;
  }
  return ret;
}

int main() {
  string s, t;
  cin >> s >> t;
  vector<int> forward = f(t, s);
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  vector<int> backward = f(t, s);
  // pp(vector<vector<int>>({forward, backward}));
  int n = t.size();
  int m = s.size();
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    int cand = m - (forward[i] + backward[n - i]);
    ans = max(ans, cand);
  }
  cout << ans << "\n";
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