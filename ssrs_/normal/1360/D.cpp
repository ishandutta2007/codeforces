#include <bits/stdc++.h>
using namespace std;
long long INF = 1100000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n, k;
    cin >> n >> k;
    long long ans = INF;
    for (long long j = 1; j * j <= n; j++){
      if (n % j == 0){
        if (j <= k){
          ans = min(ans, n / j);
        }
        if (n / j <= k){
          ans = min(ans, j);
        }
      }
    }
    cout << ans << endl;
  }
}