#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> x(n);
    for (int j = 0; j < n; j++){
      cin >> x[j];
    }
    vector<int> y(n);
    for (int j = 0; j < n; j++){
      cin >> y[j];
    }
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      a[j] = y[j] - x[j];
    }
    sort(a.begin(), a.end(), greater<int>());
    int tv = 0, fv = n / 2 + 1;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      bool ok = true;
      for (int j = 0; j < mid; j++){
        if (a[j] + a[mid * 2 - 1 - j] < 0){
          ok = false;
        }
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