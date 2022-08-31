#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long p;
    int q;
    cin >> p >> q;
    if (p % q != 0){
      cout << p << endl;
    } else {
      int q2 = q;
      vector<long long> pf;
      for (int j = 2; j * j <= q2; j++){
        if (q2 % j == 0){
          pf.push_back(j);
          while (q2 % j == 0){
            q2 /= j;
          }
        }
      }
      if (q2 > 1){
        pf.push_back(q2);
      }
      long long ans = 0;
      for (long long x : pf){
        long long tmp = p;
        while (tmp % q == 0){
          tmp /= x;
        }
        ans = max(ans, tmp);
      }
      cout << ans << endl;
    }
  }
}