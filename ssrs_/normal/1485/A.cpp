#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b;
    cin >> a >> b;
    int ans = 100;
    for (int j = 0; j < 40; j++){
      int c = b + j;
      if (c > 1){
        int a2 = a, cnt = 0;
        while (a2 > 0){
          a2 /= c;
          cnt++;
        }
        ans = min(ans, cnt + j);
      }
    }
    cout << ans << endl;
  }
}