#include <bits/stdc++.h>

using namespace std;

int a[505][505];
int b[505][505];

int n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
    }
  }
  bool res = true;

  for (int i = 0; i < n; i++) {
    int asum = 0, bsum = 0;

    for (int j = 0; j < m; j++) {
      asum += a[i][j];
      bsum += b[i][j];
    }
    asum %= 2;
    bsum %= 2;
    res = res && (asum == bsum);
  }
  for (int j = 0; j < m; j++) {
    int asum = 0, bsum = 0;
    for (int i = 0; i < n; i++) {
      asum += a[i][j];
      bsum += b[i][j];
    }
    asum %= 2;
    bsum %= 2;
    res = res && (asum == bsum);
  }
  if (res) cout << "Yes" << endl;
  else cout << "No" << endl;
}