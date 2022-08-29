#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b(k, 0);
    for (int j = 0; j < n; j++){
      b[a[j] % k]++;
    }
    long long ans = 0;
    for (int j = 0; j < n; j++){
      ans += a[j] / k;
    }
    int p = 1;
    for (int j = k - 1; j >= 0; j--){
      p = max(p, k - j);
      while (p < k && b[j] > 0){
        while (b[p] == 0){
          p++;
          if (p == k){
            break;
          }
        }
        if (p == k){
          break;
        }
        if (b[p] >= 2 || p != j && b[p] >= 1){
          ans++;
          b[p]--;
          b[j]--;
        } else {
          break;
        }
      }
    }
    cout << ans << endl;
  }
}