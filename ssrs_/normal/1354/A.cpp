#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a <= b){
      cout << b << endl;
    } else {
      long long x = a - b;
      if (c <= d){
        cout << -1 << endl;
      } else {
        long long r = (x + (c - d) - 1) / (c - d);
        cout << b + r * c << endl;
      }
    }
  }
}