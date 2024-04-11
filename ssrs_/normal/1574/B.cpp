#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    if (m > (a - 1) + (b - 1) + (c - 1)){
      cout << "NO" << endl;
    } else {
      int mx = max({a, b, c});
      int sum = a + b + c;
      if (m < mx - 1 - (sum - mx)){
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
}