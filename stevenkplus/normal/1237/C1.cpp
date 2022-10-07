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

const int MAXN = 2222;
int X[MAXN], Y[MAXN], Z[MAXN];
bool vis[MAXN];

int main()  {
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> X[i] >> Y[i] >> Z[i];
  }
  for(int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    int mv = -1, mj = -1;
    for(int j = i + 1; j < n; ++j) {
      if (vis[j]) continue;
      int v = abs(X[i] - X[j]) + abs(Y[i] - Y[j]) + abs(Z[i] - Z[j]);
      if (mv == -1 || v < mv) {
        mv = v;
        mj = j;
      }
    }
    vis[i] = vis[mj] = true;
    cout << i + 1 << " " << mj + 1 << "\n";
  }
}