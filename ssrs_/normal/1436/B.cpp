#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n){
  for (int i = 2; i * i <= n; i++){
    if (n % i == 0){
      return false;
    }
  }
  return true;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    int p = 3;
    while (1){
      if (is_prime(p + 4 * (n - 1)) && !is_prime(p)){
        break;
      }
      p += 2;
    }
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        if (j == k){
          cout << p;
        } else {
          cout << 4;
        }
        if (k < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}