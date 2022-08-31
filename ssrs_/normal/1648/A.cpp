#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> c(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> c[i][j];
      c[i][j]--;
    }
  }
  vector<vector<int>> x(100000), y(100000);
  vector<int> cnt(100000, 0);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cnt[c[i][j]]++;
      x[c[i][j]].push_back(i);
      y[c[i][j]].push_back(j);
    }
  }
  long long ans = 0;
  for (int i = 0; i < 100000; i++){
    sort(x[i].begin(), x[i].end());
    sort(y[i].begin(), y[i].end());
    for (int j = 0; j < cnt[i]; j++){
      ans += (long long) x[i][j] * (j - (cnt[i] - 1 - j));
      ans += (long long) y[i][j] * (j - (cnt[i] - 1 - j));
    }
  }
  cout << ans << endl;
}