#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
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
    vector<vector<int>> p(n);
    for (int j = 0; j < n; j++){
      p[a[j]].push_back(j);
    }
    vector<int> ans(n, INF);
    for (int j = 0; j < n; j++){
      if (!p[j].empty()){
        int cnt = p[j].size();
        int l = 0;
        l = max(l, p[j][0]);
        l = max(l, n - 1 - p[j][cnt - 1]);
        for (int k = 0; k < cnt - 1; k++){
          l = max(l, p[j][k + 1] - p[j][k] - 1);
        }
        ans[l] = min(ans[l], j + 1);
      }
    }
    for (int j = 0; j < n - 1; j++){
      ans[j + 1] = min(ans[j + 1], ans[j]);
    }
    for (int j = 0; j < n; j++){
      if (ans[j] == INF){
        cout << -1;
      } else {
        cout << ans[j];
      }
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}