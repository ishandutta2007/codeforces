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
    bool ok = true;
    for (int j = n - 2; j >= 0; j--){
      while (a[j] >= a[j + 1]){
        if (a[j] == 0){
          ok = false;
          break;
        } else {
          a[j] /= 2;
          ans++;
        }
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}