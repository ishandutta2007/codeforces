#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> E(n);
    for (int j = 0; j < m; j++){
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      E[x].push_back(y);
    }
    vector<bool> closed(n, false);
    vector<int> cnt(n, 0);
    for (int j = 0; j < n; j++){
      if (cnt[j] == 2){
        closed[j] = true;
      } else {
        for (int k : E[j]){
          cnt[k] = max(cnt[k], cnt[j] + 1);
        }
      }
    }
    vector<int> ans;
    for (int j = 0; j < n; j++){
      if (closed[j]){
        ans.push_back(j + 1);
      }
    }
    int k = ans.size();
    cout << k << endl;
    for (int j = 0; j < k; j++){
      cout << ans[j];
      if (j < k - 1){
        cout << ' ';
      }
    }
    cout << "\n";
  }
}