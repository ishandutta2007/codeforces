#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int ans = INF;
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < 3; k++){
        int mx = 0;
        for (int l = 0; l < n; l++){
          int mn = INF;
          for (int o = 0; o <= j; o++){
            for (int p = 0; p <= k; p++){
              int x = a[l] - o - p * 2;
              if (x % 3 == 0 && x >= 0){
                mn = min(mn, x / 3);
              }
            }
          }
          mx = max(mx, mn);
        }
        ans = min(ans, mx + j + k);
      }
    }
    cout << ans << endl;
  }
}