#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n, k;
  cin >> n >> k;
  if (k >= 1000000){
    cout << -1 << endl;
  } else {
    vector<long long> f;
    for (long long i = 1; i * i <= n; i++){
      if (n % i == 0){
        f.push_back(i);
        if (i * i < n){
          f.push_back(n / i);
        }
      }
    }
    long long g = -1;
    for (long long x : f){
      if (n / x >= (long long) k * (k + 1) / 2){
        g = max(g, x);
      }
    }
    if (g == -1){
      cout << -1 << endl;
    } else {
      vector<long long> ans(k);
      for (int i = 0; i < k; i++){
        ans[i] = (i + 1) * g;
      }
      long long sum = (long long) k * (k + 1) / 2 * g;
      ans[k - 1] += n - sum;
      for (int i = 0; i < k; i++){
        cout << ans[i];
        if (i < k - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}