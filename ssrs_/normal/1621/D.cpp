#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<int>> c(n * 2, vector<int>(n * 2));
    for (int j = 0; j < n * 2; j++){
      for (int k = 0; k < n * 2; k++){
        cin >> c[j][k];
      }
    }
    long long ans = INF;
    ans = min(ans, (long long) c[0][n]);
    ans = min(ans, (long long) c[0][n * 2 - 1]);
    ans = min(ans, (long long) c[n - 1][n]);
    ans = min(ans, (long long) c[n - 1][n * 2 - 1]);
    ans = min(ans, (long long) c[0][n]);
    ans = min(ans, (long long) c[0][n * 2 - 1]);
    ans = min(ans, (long long) c[n][0]);
    ans = min(ans, (long long) c[n][n - 1]);
    ans = min(ans, (long long) c[n * 2 - 1][0]);
    ans = min(ans, (long long) c[n * 2 - 1][n - 1]);
    for (int j = n; j < n * 2; j++){
      for (int k = n; k < n * 2; k++){
        ans += c[j][k];
      }
    }
    cout << ans << endl;
  }
}