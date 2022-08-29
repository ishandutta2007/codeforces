#include <bits/stdc++.h>
using namespace std;
const int INF = 5000000;
int main(){
  int n;
  cin >> n;
  int tv = INF, fv = 0;
  while (tv - fv > 1){
    int mid = (tv + fv) / 2;
    cout << "? " << mid << endl;
    int res;
    cin >> res;
    if (res == 1){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  int ans = tv;
  for (int i = 2; i <= n; i++){
    cout << "? " << tv / i << endl;
    int res;
    cin >> res;
    if (res == i){
      ans = min(ans, tv / i * i);
    }
  }
  cout << "! " << ans << endl;
}