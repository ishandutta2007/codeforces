#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<char>> c(n, vector<char>(n));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        cin >> c[j][k];
      }
    }
    int cnt = 0;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        if (c[j][k] == '1'){
          cnt++;
        }
      }
    }
    vector<int> cnt2(n, 0);
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        if (c[j][k] == '1'){
          int p = (j - k + n) % n;
          cnt2[p]++;
        }
      }
    }
    int ans = INF;
    for (int j = 0; j < n; j++){
      ans = min(ans, cnt - cnt2[j] * 2 + n);
    }
    cout << ans << endl;
  }
}