#include <bits/stdc++.h>
using namespace std;
long long ap(long long a, long long b){
  return (b + a) * (abs(b - a) + 1) / 2;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long k, x;
    cin >> k >> x;
    long long tv = 0, fv = k * 2;
    while (fv - tv > 1){
      long long mid = (tv + fv) / 2;
      long long cnt;
      if (mid <= k){
        cnt = ap(1, mid);
      } else {
        cnt = ap(1, k) + ap(k - 1, k * 2 - mid);
      }
      if (cnt < x){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    if (tv < k * 2 - 1){
      tv++;
    }
    cout << tv << endl;
  }
}