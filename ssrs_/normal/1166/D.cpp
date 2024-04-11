#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    long long a, b, m;
    cin >> a >> b >> m;
    if (a == b){
      cout << 1 << ' ' << a << endl;
    } else {
      bool ok = false;
      for (int j = 2; j <= 50; j++){
        long long A = (a + 1) << (j - 2);
        if (!ok){
          long long B = (a + m) << (j - 2);
          if (b <= B){
            ok = true;
          }
        }
        if (b < A){
          cout << -1 << endl;
          break;
        }
        if (A <= b && ok){
          vector<long long> add(j - 1, 1);
          long long r = b - A;
          for (int k = 0; k < j - 1; k++){
            long long s;
            if (k == j - 2){
              s = 1;
            } else {
              s = (long long) 1 << (j - 3 - k);
            }
            long long q = r / s;
            if (q >= m){
              q = m - 1;
            }
            add[k] += q;
            r -= q * s;
          }
          vector<long long> x(j, 0);
          x[0] = a;
          for (int k = 1; k < j; k++){
            for (int l = 0; l < k; l++){
              x[k] += x[l];
            }
            x[k] += add[k - 1];
          }
          cout << j;
          for (int k = 0; k < j; k++){
            cout << ' ' << x[k];
          }
          cout << endl;
          break;
        }
      }
    }
  }
}