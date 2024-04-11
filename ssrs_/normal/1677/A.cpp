#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
    for (int j = 0; j < n; j++){
      for (int k = 0; k <= n; k++){
        sum[j + 1][k] = sum[j][k];
        if (k > p[j]){
          sum[j + 1][k]++;
        }
      }
    }
    long long ans = 0;
    for (int b = 0; b < n; b++){
      for (int c = b + 1; c < n; c++){
        int a = sum[b][p[c]];
        int d = sum[n][p[b]] - sum[c + 1][p[b]];
        ans += a * d;
      }
    }
    cout << ans << endl;
  }
}