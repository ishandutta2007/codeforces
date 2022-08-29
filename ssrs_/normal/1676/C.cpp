#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    int ans = INF;
    for (int j = 0; j < n; j++){
      for (int k = j + 1; k < n; k++){
        int sum = 0;
        for (int l = 0; l < m; l++){
          sum += abs(s[j][l] - s[k][l]);
        }
        ans = min(ans, sum);
      }
    }
    cout << ans << endl;
  }
}