#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int m;
    cin >> m;
    vector<vector<int>> a(2, vector<int>(m));
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < m; k++){
        cin >> a[j][k];
      }
    }
    vector<int> S1(m + 1);
    S1[m] = 0;
    for (int j = m - 1; j >= 0; j--){
      S1[j] = S1[j + 1] + a[0][j];
    }
    vector<int> S2(m + 1);
    S2[0] = 0;
    for (int j = 0; j < m; j++){
      S2[j + 1] = S2[j] + a[1][j];
    }
    int ans = INF;
    for (int j = 0; j < m; j++){
      ans = min(ans, max(S1[j + 1], S2[j]));
    }
    cout << ans << endl;
  }
}