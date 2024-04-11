#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for (int j = 0; j <= 50; j++){
      for (int k = 0; k <= 50; k++){
        if (j <= a && j * 2 + k <= b && k * 2 <= c){
          ans = max(ans, j * 3 + k * 3);
        }
      }
    }
    cout << ans << endl;
  }
}