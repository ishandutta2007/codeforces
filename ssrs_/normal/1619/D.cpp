#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> p(m, vector<int>(n));
    for (int j = 0; j < m; j++){
      for (int k = 0; k < n; k++){
        cin >> p[j][k];
      }
    }
    int ans = 0;
    for (int j = 0; j < m; j++){
      vector<int> p2 = p[j];
      sort(p2.begin(), p2.end(), greater<int>());
      ans = max(ans, p2[1]);
    }
    for (int j = 0; j < n; j++){
      int mx = 0;
      for (int k = 0; k < m; k++){
        mx = max(mx, p[k][j]);
      }
      ans = min(ans, mx);
    }
    cout << ans << endl;
  }
}