#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    int ans = 0;
    while (n > 0){
      ans = max(ans, n % 10);
      n /= 10;
    }
    cout << ans << endl;
  }
}