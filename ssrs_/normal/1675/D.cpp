#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    int r;
    for (int j = 0; j < n; j++){
      if (p[j] == j){
        r = j;
      }
    }
    vector<int> leaf(n, true);
    for (int j = 0; j < n; j++){
      if (j != r){
        leaf[p[j]] = false;
      }
    }
    int m = 0;
    vector<vector<int>> ans;
    vector<bool> used(n, false);
    for (int j = 0; j < n; j++){
      if (leaf[j]){
        vector<int> path = {j};
        while (true){
          int v = path.back();
          if (v == r){
            break;
          }
          if (!used[p[v]]){
            used[p[v]] = true;
            path.push_back(p[v]);
          } else {
            break;
          }
        }
        m++;
        reverse(path.begin(), path.end());
        ans.push_back(path);
      }
    }
    cout << m << "\n";
    for (int j = 0; j < m; j++){
      int L = ans[j].size();
      cout << L << "\n";
      for (int k = 0; k < L; k++){
        cout << ans[j][k] + 1;
        if (k < L - 1){
          cout << ' ';
        }
      }
      cout << "\n";
    }
  }
}