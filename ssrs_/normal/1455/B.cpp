#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int x;
    cin >> x;
    int sum = 0;
    int ans = 0;
    while (1){
      sum += ans + 1;
      ans++;
      if (sum >= x){
        if (sum == x + 1){
          ans++;
        }
        break;
      }
    }
    cout << ans << endl;
  }
}