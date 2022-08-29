#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    int a = -1, b = -1, c = 1;
    for (int j = 2; j * j < n; j++){
      if (n % j == 0){
        a = j;
        n /= j;
        break;
      }
    }
    if (a == -1){
      cout << "NO" << endl;
    } else {
      for (int j = a + 1; j * j < n; j++){
        if (n % j == 0){
          b = j;
          c = n / j;
          break;
        }
      }
      if (b == -1){
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
        cout << a << ' ' << b << ' ' << c << endl;
      }
    }
  }
}