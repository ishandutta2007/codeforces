#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n, k, M, D;
  cin >> n >> k >> M >> D;
  long long ans = 0;
  for (int i = 0; i < D; i++){
    long long x = n / (i * k + 1);
    ans = max(ans, min(M, x) * (i + 1));
    if (x == 0){
      break;
    }
  }
  ans = max(ans, min(D, (n + k - 1) / k));
  cout << ans << endl;
}