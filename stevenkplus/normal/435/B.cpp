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

typedef priority_queue<pll, vector<pll>, greater<pll> > PQ;

// =========== Solution ============= //

int main() {
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    char mx = s[i];
    int mxj = i;
    for (int j = i; j <= i + k && j < n; ++j) {
      if (s[j] > mx) {
        mx = s[j];
        mxj = j;
      }
    }
    k -= mxj - i;
    s = s.substr(0, i) + s[mxj] + s.substr(i, mxj - i) + s.substr(mxj + 1);
  }
  cout << s << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases