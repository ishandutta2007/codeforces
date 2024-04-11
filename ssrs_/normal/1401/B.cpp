#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int x1, y1, z1;
    cin >> x1 >> y1 >> z1;
    int x2, y2, z2;
    cin >> x2 >> y2 >> z2;
    int tmp = min(y2, z1);
    int ans = tmp * 2;
    y2 -= tmp;
    z1 -= tmp;
    if (z2 + y1 > x1 + y1 + z1){
      ans -= (z2 + y1 - x1 - y1 - z1) * 2;
    }
    cout << ans << endl;
  }
}