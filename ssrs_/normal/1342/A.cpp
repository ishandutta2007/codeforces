#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long x, y;
    cin >> x >> y;
    long long a, b;
    cin >> a >> b;
    if (a * 2 <= b){
      cout << a * (x + y) << endl;
    } else {
      cout << b * min(x, y) + a * abs(x - y) << endl;
    }
  }
}