#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cin >> a[j][k];
      }
    }
    if ((n + m) % 2 == 0){
      int N = (n + m) / 2 - 1;
      vector<map<int, int>> mp(N);
      vector<int> cnt(N, 0);
      for (int j = 0; j < n; j++){
        for (int k = 0; k < m; k++){
          int p = min(j + k, (n - 1 - j) + (m - 1 - k));
          if (p != N){
            mp[p][a[j][k]]++;
            cnt[p]++;
          }
        }
      }
      int ans = 0;
      for (int j = 0; j < N; j++){
        int mx = 0;
        for (auto P : mp[j]){
          mx = max(mx, P.second);
        }
        ans += cnt[j] - mx;
      }
      cout << ans << endl;
    } else {
      int N = (n + m) / 2;
      vector<map<int, int>> mp(N);
      vector<int> cnt(N, 0);
      for (int j = 0; j < n; j++){
        for (int k = 0; k < m; k++){
          int p = min(j + k, (n - 1 - j) + (m - 1 - k));
          mp[p][a[j][k]]++;
          cnt[p]++;
        }
      }
      int ans = 0;
      for (int j = 0; j < N; j++){
        int mx = 0;
        for (auto P : mp[j]){
          mx = max(mx, P.second);
        }
        ans += cnt[j] - mx;
      }
      cout << ans << endl;
    }
  }
}