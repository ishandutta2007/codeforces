#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  if (k % 2 == 0){
    int X = 0;
    for (int i = 0; i < n; i++){
      if (a[i] <= 2){
        X ^= a[i];
      } else if (a[i] % 2 == 0){
        X ^= 1;
      }
    }
    if (X == 0){
      cout << "Nicky" << endl;
    } else {
      cout << "Kevin" << endl;
    }
  } else {
    int X = 0;
    for (int i = 0; i < n; i++){
      if (a[i] < 4){
        X ^= a[i] % 2;
      } else if (a[i] % 2 == 0){
        int x = __builtin_ctz(a[i]);
        if ((a[i] >> x) == 3){
          if (x % 2 == 1){
            X ^= 2;
          } else {
            X ^= 1;
          }
        } else {
          if (x % 2 == 0){
            X ^= 2;
          } else {
            X ^= 1;
          }
        }
      }
    }
    if (X == 0){
      cout << "Nicky" << endl;
    } else {
      cout << "Kevin" << endl;
    }
  }
}