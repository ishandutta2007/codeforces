#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> x(k);
    for (int j = 0; j < k; j++){
      cin >> x[j];
    }
    sort(x.begin(), x.end());
    int tv = 0, fv = k + 1;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      vector<int> x2(mid);
      for (int j = 0; j < mid; j++){
        x2[j] = x[k - mid + j];
      }
      long long S = 0;
      for (int j = 0; j < mid; j++){
        S += n - x2[j];
      }
      if (S <= n - 1){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}