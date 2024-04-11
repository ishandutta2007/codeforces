#include <bits/stdc++.h>

using namespace std;

const int maxn = 102;
int n, m, h;

int ans[maxn][maxn];
int col[maxn];
int row[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> h;
  for (int i = 1; i <= m; i++) {
    cin >> col[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> row[i];
  }
  for (int i= 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> ans[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (ans[j][i]) {
        ans[j][i] = col[i];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (ans[i][j]) {
        ans[i][j] = min(ans[i][j], row[i]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

}