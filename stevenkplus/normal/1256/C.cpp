// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second

// =========== Book ============ //

// =========== Solution ============= //

int main()  {
  int n, m, d;
  cin >> n >> m >> d;
  --d;
  vector<int> ar(m);
  int space = n;
  for (int i = 0; i < m; ++i) {
    cin >> ar[i];
    space -= ar[i];
  }
  if (space > (m + 1) * d) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  for (int i = 0; i <= m; ++i) {
    int jump = min(space, d);
    space -= jump;
    for (int j = 0; j < jump; ++j) {
      cout << "0 ";
    }
    if (i < m) {
      for (int j = 0; j < ar[i]; ++j) {
        cout << i + 1 << " ";
      }
    }
  }
  cout << "\n";
}