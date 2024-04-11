#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, l;
    cin >> n >> l;
    vector<int> x(n);
    for (int j = 0; j < n; j++){
      cin >> x[j];
    }
    int ans = 0;
    for (int j = 0; j < l; j++){
      int cnt = 0;
      for (int k = 0; k < n; k++){
        if ((x[k] >> j & 1) == 1){
          cnt++;
        }
      }
      if (cnt > n / 2){
        ans |= 1 << j;
      }
    }
    cout << ans << endl;
  }
}