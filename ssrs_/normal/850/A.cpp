#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<int>> X(n, vector<int>(5));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 5; j++){
      cin >> X[i][j];
    }
  }
  if (n > 100){
    cout << 0 << endl;
  } else {
    vector<bool> good(n, true);
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        for (int k = 0; k < n; k++){
          if (i != j && j != k && k != i){
            int dot = 0;
            for (int l = 0; l < 5; l++){
              dot += (X[j][l] - X[i][l]) * (X[k][l] - X[i][l]);
            }
            if (dot > 0){
              good[i] = false;
            }
          }
        }
      }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++){
      if (good[i]){
        ans.push_back(i);
      }
    }
    int k = ans.size();
    cout << k << endl;
    for (int i = 0; i < k; i++){
      cout << ans[i] + 1 << endl;
    }
  }
}