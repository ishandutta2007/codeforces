#include <bits/stdc++.h>
using namespace std;
const double EPS = 0.000001;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n % 2 == 1){
      cout << "NO" << endl;
    } else {
      int x = sqrt(n) + EPS;
      int y = sqrt(n / 2) + EPS;
      if (x * x == n){
        cout << "YES" << endl;
      } else if (y * y == n / 2){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}