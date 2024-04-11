#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    long long n;
    cin >> n;
    if (n % 2050 != 0){
      cout << -1 << endl;
    } else {
      n /= 2050;
      int ans = 0;
      while (n > 0){
        ans += n % 10;
        n /= 10;
      }
      cout << ans << endl;
    }
  }
}