#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b(n), c(n);
    for (int j = 0; j < n; j++){
      b[j] = __builtin_ctz(a[j]);
      c[j] = __builtin_ctz(j + 1);
    }
    int cnt = 0;
    for (int j = 0; j < n; j++){
      cnt += b[j];
    }
    sort(c.begin(), c.end(), greater<int>());
    int ans = 0;
    for (int j = 0; j < n; j++){
      if (cnt < n){
        cnt += c[j];
        ans++;
      }
    }
    if (cnt < n){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}