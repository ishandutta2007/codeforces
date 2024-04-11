#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    long long h;
    cin >> n >> h;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<long long> d(n);
    for (int j = 0; j < n - 1; j++){
      d[j] = a[j + 1] - a[j];
    }
    d[n - 1] = h;
    long long tv = h, fv = 0;
    while (tv - fv > 1){
      long long mid = (tv + fv) / 2;
      long long sum = 0;
      for (int j = 0; j < n; j++){
        sum += min(mid, d[j]);
      }
      if (sum >= h){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}