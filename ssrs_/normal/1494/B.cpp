#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, U, R, D, L;
    cin >> n >> U >> R >> D >> L;
    bool ok = false;
    for (int j = 0; j < (1 << 4); j++){
      int U2 = U, R2 = R, D2 = D, L2 = L;
      if ((j >> 0 & 1) == 1){
        U2--;
        R2--;
      }
      if ((j >> 1 & 1) == 1){
        U2--;
        L2--;
      }
      if ((j >> 2 & 1) == 1){
        D2--;
        R2--;
      }
      if ((j >> 3 & 1) == 1){
        D2--;
        L2--;
      }
      if (0 <= U2 && U2 <= n - 2 && 0 <= R2 && R2 <= n - 2 && 0 <= D2 && D2 <= n - 2 && 0 <= L2 && L2 <= n - 2){
        ok = true;
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}