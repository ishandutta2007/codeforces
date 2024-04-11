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
      a[j]--;
    }
    vector<int> cnt(n, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j]]++;
    }
    vector<bool> used(n, false);
    int sum = 0;
    vector<bool> ok(n + 1, false);
    ok[0] = true;
    vector<int> op(n + 1, 0);
    for (int j = 0; j < n; j++){
      op[j + 1] = op[j];
      if (!used[a[j]]){
        sum += cnt[a[j]];
        used[a[j]] = true;
        op[j + 1]++;
      }
      if (sum == j + 1){
        ok[j + 1] = true;
      }
    }
    int ans = n;
    for (int j = n; j >= 0; j--){
      if (ok[j]){
        ans = min(ans, op[j]);
      }
      if (j < n && j > 0){
        if (a[j - 1] > a[j]){
          break;
        }
      }
    }
    cout << ans << endl;
  }
}