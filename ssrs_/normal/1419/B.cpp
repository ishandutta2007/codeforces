#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long x;
    cin >> x;
    long long a = 1;
    int ans = 0;
    while (1){
      long long c = a * (a + 1) / 2;
      if (c <= x){
        ans++;
        x -= c;
      } else {
        break;
      }
      a = a * 2 + 1;
    }
    cout << ans << endl;
  }
}