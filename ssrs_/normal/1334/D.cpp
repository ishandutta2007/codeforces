#include <bits/stdc++.h>
using namespace std;
long long ap_sum(long long a, long long n){
  //arithmetic progression sum
  //start = a, length = n, diff = -2
  return n * (a - n + 1);
}
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    long long n;
    long long l, r;
    cin >> n >> l >> r;
    int a = 2 * (n - 1);
    vector<long long> E(n + 1);
    E[0] = 0;
    for (int j = 1; j < n; j++){
      E[j] = ap_sum(a, j);
    }
    E[n] = n * (n - 1) + 1;
    for (int j = 0; j < n - 1; j++){
      long long L = E[j] + 1;
      long long R = E[j + 1];
      for (long long k = max(l, L); k <= min(r, R); k++){
        long long k2 = k - L;
        if (k2 % 2 == 0){
          cout << j + 1;
        } else {
          cout << j + 1 + k2 / 2 + 1;
        }
        if (k < r){
          cout << ' ';
        }
      }
    }
    if (r == E[n]){
      cout << 1;
    }
    cout << endl;
  }
}