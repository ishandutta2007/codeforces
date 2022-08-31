#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> w(n);
    for (int j = 0; j < n; j++){
      cin >> w[j];
    }
    vector<vector<int>> E(n);
    for (int j = 0; j < n - 1; j++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      E[u].push_back(v);
      E[v].push_back(u);
    }
    long long sum = 0;
    for (int j = 0; j < n; j++){
      sum += w[j];
    }
    vector<int> b;
    for (int j = 0; j < n; j++){
      int r = E[j].size() - 1;
      for (int k = 0; k < r; k++){
        b.push_back(w[j]);
      }
    }
    sort(b.begin(), b.end(), greater<int>());
    vector<long long> ans(n - 1);
    ans[0] = sum;
    for (int j = 0; j < n - 2; j++){
      ans[j + 1] = ans[j] + b[j];
    }
    for (int j = 0; j < n - 1; j++){
      cout << ans[j];
      if (j < n - 2){
        cout << ' ';
      }
    }
    cout << endl;
  }
}