#include <bits/stdc++.h>
using namespace std;
int main(){ 
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long m, d, w;
    cin >> m >> d >> w;
    if (d == 1){
      cout << 0 << endl;
    } else {
      w /= gcd(w, d - 1);
      long long A = min(m, d);
      long long x = A / w;
      cout << A * x - w * (x * (x + 1) / 2) << endl;
    }
  }
}