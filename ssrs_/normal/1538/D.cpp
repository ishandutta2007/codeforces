#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b, k;
    cin >> a >> b >> k;
    if (k == 1){
      int g = __gcd(a, b);
      if ((a == g || b == g) && a != b){
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    } else {
      int cnt = 0;
      for (int j = 2; j * j <= a; j++){
        while (a % j == 0){
          a /= j;
          cnt++;
        }
      }
      if (a > 1){
        cnt++;
      }
      for (int j = 2; j * j <= b; j++){
        while (b % j == 0){
          b /= j;
          cnt++;
        }
      }
      if (b > 1){
        cnt++;
      }
      if (k <= cnt){
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}