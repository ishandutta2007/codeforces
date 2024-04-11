#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
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
    int n2 = 1;
    int c = 0;
    while (n2 <= n){
      n2 *= 2;
      c++;
    }
    vector<int> mx(n2, 0);
    vector<int> mx2(n2, 0);
    for (int j = n - 1; j >= 0; j--){
      if (mx[a[j]] == 0){
        mx[a[j]] = j + 1;
      } else if (mx2[a[j]] == 0){
        mx2[a[j]] = j + 1;
      }
    }
    for (int j = 0; j < c; j++){
      for (int l = 0; l < n2; l++){
        if ((l >> j & 1) == 1){
          int l2 = l - (1 << j);
          int t1 = max(mx[l], mx[l2]);
          int t2;
          if (mx[l] > mx[l2]){
            t2 = max(mx2[l], mx[l2]);
          } else if (mx[l] < mx[l2]){
            t2 = max(mx[l], mx2[l2]);
          } else {
            t2 = max(mx2[l], mx2[l2]);
          }
          mx[l] = t1;
          mx2[l] = t2;
        }
      }
    }
    long long ans = -INF;
    for (int j = 0; j < n2; j++){
      if (mx2[j] != 0){
        ans = max(ans, (long long) mx[j] * mx2[j] - k * j);
      }
    }
    cout << ans << endl;
  }
}