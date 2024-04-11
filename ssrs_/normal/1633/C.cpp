#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long hC, dC;
    cin >> hC >> dC;
    long long hM, dM;
    cin >> hM >> dM;
    int k;
    long long w, a;
    cin >> k >> w >> a;
    bool ok = false;
    for (int j = 0; j <= k; j++){
      long long h = hC + a * j;
      long long d = dC + w * (k - j);
      long long c1 = (h + dM - 1) / dM;
      long long c2 = (hM + d - 1) / d;
      if (c1 >= c2){
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