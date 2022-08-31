#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> h(n);
    for (int j = 0; j < n; j++){
      cin >> h[j];
    }
    int tv = 0, fv = 1000000000;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      vector<long long> h2(n);
      for (int j = 0; j < n; j++){
        h2[j] = h[j];
      }
      bool ok = true;
      for (int j = n - 1; j >= 2; j--){
        if (h2[j] < mid){
          ok = false;
        } else {
          long long d = (h2[j] - mid) / 3;
          d = min(d, (long long) h[j] / 3);
          h2[j - 1] += d;
          h2[j - 2] += d * 2;
        }
      }
      if (h2[0] < mid || h2[1] < mid){
        ok = false;
      }
      if (ok){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}