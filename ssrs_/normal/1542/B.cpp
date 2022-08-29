#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, a, b;
    cin >> n >> a >> b;
    long long X = 1;
    bool ok = false;
    while (X <= n){
      if ((n - X) % b == 0){
        ok = true;
      }
      if (a == 1){
        break;
      }
      X *= a;
    }
    if (ok){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}