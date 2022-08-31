#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long x, y, p, q;
    cin >> x >> y >> p >> q;
    if (x != y && p == q || x != 0 && p == 0){
      cout << -1 << endl;
    } else {
      long long tv = 1010000000;
      long long fv = 0;
      while (tv - fv > 1){
        long long mid = (tv + fv) / 2;
        long long ac = p * mid;
        long long wa = (q - p) * mid;
        if (ac >= x && wa >= y - x){
          tv = mid;
        } else {
          fv = mid;
        }
      }
      long long sub = q * tv - y;
      cout << sub << endl;
    }
  }
}