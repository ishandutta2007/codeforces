#include <bits/stdc++.h>
using namespace std;
long long solve(long long n){
  if (n == 0){
    return 0;
  } else {
    long long tv = 0, fv = 1000000001;
    while (fv - tv > 1){
      long long mid = (tv + fv) / 2;
      if (mid * mid <= n){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    long long ans = 0;
    ans += tv * 3 - 2;
    if (tv * (tv + 1) <= n){
      ans++;
    }
    if (tv * (tv + 2) <= n){
      ans++;
    }
    return ans;
  }
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << endl;
  }
}