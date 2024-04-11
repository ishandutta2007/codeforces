#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int p, k;
  cin >> p >> k;
  if (k == 0){
    long long ans = 1;
    for (int i = 0; i < p - 1; i++){
      ans *= p;
      ans %= MOD;
    }
    cout << ans << endl;
  } else if (k == 1){
    long long ans = 1;
    for (int i = 0; i < p; i++){
      ans *= p;
      ans %= MOD;
    }
    cout << ans << endl;
  } else {
    long long ans = 1;
    vector<bool> used(p, false);
    for (int i = 1; i < p; i++){
      if (!used[i]){
        ans *= p;
        ans %= MOD;
        int v = i;
        while (1){
          v = (long long) v * k % p;
          if (used[v]){
            break;
          }
          used[v] = true;
        }
      }
    }
    cout << ans << endl;
  }
}