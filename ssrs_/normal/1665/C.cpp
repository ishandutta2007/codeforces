#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(n, -1);
    for (int j = 1; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    vector<vector<int>> c(n);
    for (int j = 1; j < n; j++){
      c[p[j]].push_back(j);
    }
    vector<int> cnt;
    for (int j = 0; j < n; j++){
      if (!c[j].empty()){
        cnt.push_back(c[j].size());
      }
    }
    sort(cnt.begin(), cnt.end(), greater<int>());
    int m = cnt.size();
    int ans = m;
    for (int j = 0; j < m; j++){
      cnt[j] -= m - j;
    }
    ans++;
    for (int j = 0; j < m; j++){
      cnt[j]--;
    }
    int tv = n, fv = -1;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      int sum = 0;
      for (int j = 0; j < m; j++){
        sum += max(cnt[j] - mid, 0);
      }
      if (sum <= mid){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    ans += tv;
    cout << ans << endl;
  }
}