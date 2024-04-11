#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0 && m % 2 == 0){
      if (k % 2 == 0){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else if (n % 2 == 1){
      if (k % 2 == m / 2 % 2 && k >= m / 2){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      if (k % 2 == (n * m / 2 - n / 2) % 2 && k <= n * m / 2 - n / 2){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}