#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    vector<int> c(n, 0);
    for (int j = 0; j < n; j++){
      c[(j - p[j] + n) % n]++;
    }
    vector<int> ans;
    for (int j = 0; j < n; j++){
      if (c[j] >= n - m * 2){
        vector<int> p2(n);
        for (int k = 0; k < n; k++){
          p2[k] = p[(k + j) % n];
        }
        int cnt = 0;
        vector<bool> used(n, false);
        for (int k = 0; k < n; k++){
          if (!used[k]){
            used[k] = true;
            int v = k;
            while (p2[v] != k){
              v = p2[v];
              cnt++;
              used[v] = true;
            }
          }
        }
        if (cnt <= m){
          ans.push_back(j);
        }
      }
    }
    int r = ans.size();
    cout << r;
    for (int j = 0; j < r; j++){
      cout << ' ' << ans[j];
    }
    cout << "\n";
  }
}