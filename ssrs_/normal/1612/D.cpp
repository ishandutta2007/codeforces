#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long a, b, x;
    cin >> a >> b >> x;
    if (a > b){
      swap(a, b);
    }
    if (x > b){
      cout << "NO" << endl;
    } else {
      bool ok = false;
      while (a > 0){
        if (x <= b && x % a == b % a){
          ok = true;
        }
        b %= a;
        swap(a, b);
      }
      if (ok){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}