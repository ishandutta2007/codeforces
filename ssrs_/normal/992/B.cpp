#include <bits/stdc++.h>
using namespace std;
int main(){
  long long l, r, x, y;
  cin >> l >> r >> x >> y;
  if (y % x != 0){
    cout << 0 << endl;
  } else {
    long long Y = y / x;
    vector<int> F;
    for (long long i = 2; i * i <= Y; i++){
      if (Y % i == 0){
        F.push_back(i);
        Y /= i;
        while (Y % i == 0){
          F[F.size() - 1] *= i;
          Y /= i;
        }
      }
    }
    if (Y != 1){
      F.push_back(Y);
    }
    int C = F.size();
    int count = 0;
    for (int i = 0; i < (1 << C); i++){
      long long a = 1, b = 1;
      for (int j = 0; j < C; j++){
        if ((i >> j) & 1){
          a *= F[j];
        } else {
          b *= F[j];
        }
      }
      a *= x;
      b *= x;
      if (l <= a && a <= r && l <= b && b <= r){
        count++;
      }
    }
    cout << count << endl;
  }
}