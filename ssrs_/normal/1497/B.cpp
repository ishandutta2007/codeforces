#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> cnt(m, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j] % m]++;
    }
    int ans = n;
    if (cnt[0] > 0){
      ans -= cnt[0] - 1;
    }
    for (int j = 1; j < (m + 1) / 2; j++){
      if (cnt[j] == cnt[m - j] && cnt[j] > 0){
        ans -= cnt[j] * 2 - 1;
      } else {
        ans -= min(cnt[j], cnt[m - j]) * 2;
      }
    }
    if (m % 2 == 0){
      if (cnt[m / 2] > 0){
        ans -= cnt[m / 2] - 1;
      }
    }
    cout << ans << endl;
  }
}