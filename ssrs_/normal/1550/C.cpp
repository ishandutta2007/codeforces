#include <bits/stdc++.h>
using namespace std;
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
    int ans = 0;
    for (int j = 0; j < n; j++){
      for (int k = j + 1; k <= n; k++){
        if (j - k >= 5){
          break;
        }
        bool ok = true;
        for (int x = j; x < k; x++){
          for (int y = x + 1; y < k; y++){
            for (int z = y + 1; z < k; z++){
              if (a[x] <= a[y] && a[y] <= a[z]){
                ok = false;
              }
              if (a[x] >= a[y] && a[y] >= a[z]){
                ok = false;
              }
            }
          }
        }
        if (ok){
          ans++;
        } else {
          break;
        }
      }
    }
    cout << ans << endl;
  }
}