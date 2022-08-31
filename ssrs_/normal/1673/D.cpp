#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long b, q, y;
    cin >> b >> q >> y;
    long long c, r, z;
    cin >> c >> r >> z;
    long long B = b + q * (y - 1);
    long long C = c + r * (z - 1);
    bool zero = false;
    if (r % q != 0){
      zero = true;
    }
    if ((c - b) % q != 0){
      zero = true;
    }
    long long p1 = (c - b) / q;
    if (p1 < 0 || y <= p1){
      zero = true;
    }
    if ((C - b) % q != 0){
      zero = true;
    }
    long long p2 = (C - b) / q;
    if (p2 < 0 || y <= p2){
      zero = true;
    }
    if (zero){
      cout << 0 << endl;
    } else {
      bool inf = false;
      if (p1 - r / q < 0){
        inf = true;
      }
      if (p2 + r / q >= y){
        inf = true;
      }
      if (inf){
        cout << -1 << endl;
      } else {
        vector<int> F;
        for (int j = 1; j * j <= r; j++){
          if (r % j == 0){
            F.push_back(j);
            if (j * j < r){
              F.push_back(r / j);
            }
          }
        }
        int cnt = F.size();
        long long ans = 0;
        for (int j = 0; j < cnt; j++){
          if (lcm(q, F[j]) == r){
            long long x = r / F[j];
            ans += x * x;
            ans %= MOD;
          }
        }
        cout << ans << endl;
      }
    }
  }
}