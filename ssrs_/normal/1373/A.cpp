#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long a, b, c;
    cin >> a >> b >> c;
    if (a < c){
      if (a * b > c){
      cout << 1 << ' ' << b << endl;
      } else {
        cout << 1 << ' ' << -1 << endl;
      }
    } else {
      cout << -1 << ' ' << b << endl;
    }
  }
}