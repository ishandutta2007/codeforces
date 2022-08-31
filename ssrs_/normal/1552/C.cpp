#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> x(k), y(k);
    for (int j = 0; j < k; j++){
      cin >> x[j] >> y[j];
      x[j]--;
      y[j]--;
      if (x[j] > y[j]){
        swap(x[j], y[j]);
      }
    }
    vector<bool> used(n * 2, false);
    for (int j = 0; j < k; j++){
      used[x[j]] = true;
      used[y[j]] = true;
    }
    int ans = (n - k) * (n - k - 1) / 2;
    for (int j = 0; j < k; j++){
      for (int l = j + 1; l < k; l++){
        if (x[l] < x[j] && x[j] < y[l] && y[l] < y[j] || x[j] < x[l] && x[l] < y[j] && y[j] < y[l]){
          ans++;
        }
      }
    }
    for (int j = 0; j < k; j++){
      int cnt = 0;
      for (int l = x[j] + 1; l < y[j]; l++){
        if (!used[l]){
          cnt++;
        }
      }
      ans += min(cnt, n * 2 - k * 2 - cnt);
    }
    cout << ans << endl;
  }
}