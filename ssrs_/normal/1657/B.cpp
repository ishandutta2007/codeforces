#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, B, x, y;
    cin >> n >> B >> x >> y;
    int a = 0;
    long long ans = 0;
    for (int j = 0; j < n; j++){
      if (a + x <= B){
        a += x;
      } else {
        a -= y;
      }
      ans += a;
    }
    cout << ans << endl;
  }
}