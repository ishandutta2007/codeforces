#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n, k, A, B;
  cin >> n >> k >> A >> B;
  if (k == 1){
    cout << (n - 1) * A << endl;
  } else {
    long long curr = 0;
    long long ans = (n - 1) * A;
    while (1){
      ans = min(ans, (n - 1) * A + curr);
      if (n >= k){
        if (n % k != 0){
          curr += (n % k) * A;
          n = n / k * k;
        } else {
          curr += B;
          n /= k;
        }
      } else {
        curr += (n - 1) * A;
        break;
      }
    }
    cout << ans << endl;
  }
}