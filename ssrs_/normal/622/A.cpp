#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin >> n;
  long long tv = 0, fv = 20000000;
  while (fv - tv > 1){
    long long mid = (tv + fv) / 2;
    if (mid * (mid + 1) / 2 < n){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << n - tv * (tv + 1) / 2 << endl;
}