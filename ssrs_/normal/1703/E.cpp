#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        char c;
        cin >> c;
        a[j][k] = c - '0';
      }
    }
    int ans = 0;
    for (int j = 0; j < (n + 1) / 2; j++){
      for (int k = 0; k < n / 2; k++){
        int s = a[j][k] + a[k][n - 1 - j] + a[n - 1 - j][n - 1 - k] + a[n - 1 - k][j];
        ans += min(s, 4 - s);
      }
    }
    cout << ans << endl;
  }
}