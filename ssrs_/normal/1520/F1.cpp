#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, t;
  cin >> n >> t;
  int k;
  cin >> k;
  int tv = 0, fv = n;
  while (fv - tv > 1){
    int mid = (tv + fv) / 2;
    cout << "? 1 " << mid << endl;
    int res;
    cin >> res;
    if (mid - res < k){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << "! " << fv << endl;
}