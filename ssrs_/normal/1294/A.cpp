#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if ((a + b + c + n) % 3 == 0 && n >= max({a, b, c}) * 3 - (a + b + c)){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}