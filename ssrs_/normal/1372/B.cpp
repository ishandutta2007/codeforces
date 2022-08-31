#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    int p = -1;
    for (int j = 2; j * j <= n; j++){
      if (n % j == 0){
        p = j;
        break;
      }
    }
    if (p == 2){
      cout << n / 2 << ' ' << n / 2 << endl;
    } else if (p == -1){
      cout << 1 << ' ' << n - 1 << endl;
    } else {
      cout << n / p << ' ' << n - n / p << endl;
    }
  }
}