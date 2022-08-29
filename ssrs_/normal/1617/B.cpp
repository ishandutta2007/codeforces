#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    for (int j = 2; j <= n; j++){
      if (__gcd(j, n - 1 - j) == 1){
        cout << j << ' ' << n - 1 - j << ' ' << 1 << "\n";
        break;
      }
    }
  }
}