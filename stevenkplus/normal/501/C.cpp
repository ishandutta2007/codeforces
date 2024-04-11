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

// =========== Solution ============= //

int main()  {
  int n;
  cin >> n;
  vector<int> deg(n), s(n);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    cin >> deg[i] >> s[i];
    m += deg[i];
  }
  cout << m / 2 << "\n";
  for(int i = 0; i < n; ++i) {
    int cur = i;
    while (deg[cur] == 1) {
      int par = s[cur];
      --deg[par];
      --deg[cur];
      s[cur] ^= par;
      s[par] ^= cur;
      cout << cur << " " << par << "\n";
      cur = par;
    }
  }
}