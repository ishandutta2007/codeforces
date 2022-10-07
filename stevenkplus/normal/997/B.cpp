#include <bits/stdc++.h>
using namespace std;

const int MOD = 49;
typedef long long ll;

bool can[55];
int low[55];
int hi[55];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  for(int i = 0; i < 49; ++i) {
    for(int j = 0; j < 49; ++j) {
      int extra = n - i - j;
      if (extra < 0) continue;
      int idx = (4 * i + 9 * j) % 49;
      int l = (4 * i + 9 * j) / 49;
      int h = l + extra;

      if (!can[idx]) {
        can[idx] = true;
        low[idx] = l;
        hi[idx] = h;
      } else {
        low[idx] = min(low[idx], l);
        hi[idx] = max(hi[idx], h);
      }
    }
  }

  ll ans = 0;
  for(int i = 0; i < 49; ++i) {
    if (can[i]) {
      ans += hi[i] - low[i] + 1;
    }
  }
  cout << ans << "\n";
}