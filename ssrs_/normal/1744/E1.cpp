#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long P = (long long) a * b;
    int x = -1, y = -1;
    for (int j = a + 1; j <= c; j++){
      long long m = P / gcd(P, j);
      int p = d / m * m;
      if (p > b){
        x = j;
        y = p;
      }
    }
    cout << x << ' ' << y << endl;
  }
}