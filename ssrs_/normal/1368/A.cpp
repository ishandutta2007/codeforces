#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    long long a, b, n;
    cin >> a >> b >> n;
    int ans = 0;
    while (a <= n && b <= n){
      if (a < b){
        a += b;
      } else {
        b += a;
      }
      ans++;
    }
    cout << ans << endl;
  }
}