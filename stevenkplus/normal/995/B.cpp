#include <bits/stdc++.h>
using namespace std;

const int MAXN = 210;
int ar[MAXN];
bool vis[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < 2 * n; ++i) {
    cin >> ar[i];
  }
  int ans = 0;
  for(int i = 0; i < 2 * n; ++i) {
    int v = ar[i];
    if (vis[v]) continue;
    vis[v] = true;
    for(int j = i + 1; j < 2 * n; ++j) {
      if (ar[j] == v) {
        break;
      }
      if (!vis[ar[j]]) ++ans;
    }
  }
  cout << ans << "\n";
}