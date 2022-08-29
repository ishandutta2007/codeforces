#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    vector<long long> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + a[j];
    }
    if (S[n] <= k){
      cout << 0 << endl;
    } else {
      long long tv = S[n] - k, fv = 0;
      while (tv - fv > 1){
        long long mid = (tv + fv) / 2;
        bool ok = false;
        for (int j = 0; j <= n - 1; j++){
          if (mid >= j){
            long long d = mid - j;
            long long sum = 0;
            sum += (a[0] - d) * (j + 1);
            sum += S[n - j] - S[1];
            if (sum <= k){
              ok = true;
            }
          }
        }
        if (ok){
          tv = mid;
        } else {
          fv = mid;
        }
      }
      cout << tv << endl;
    }
  }
}