#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(n);
    for (int j = 0; j < n; j++){
      cin >> x[j];
    }
    vector<int> y(m);
    for (int j = 0; j < m; j++){
      cin >> y[j];
    }
    vector<int> x2(k), y2(k);
    for (int j = 0; j < k; j++){
      cin >> x2[j] >> y2[j];
    }
    vector<vector<int>> id1(n - 1);
    vector<vector<int>> id2(m - 1);
    for (int j = 0; j < k; j++){
      int p1 = lower_bound(x.begin(), x.end(), x2[j]) - x.begin();
      int p2 = lower_bound(y.begin(), y.end(), y2[j]) - y.begin();
      if (x[p1] != x2[j]){
        id1[p1 - 1].push_back(p2);
      }
      if (y[p2] != y2[j]){
        id2[p2 - 1].push_back(p1);
      }
    }
    long long ans = 0;
    for (int j = 0; j < n - 1; j++){
      int cnt = id1[j].size();
      sort(id1[j].begin(), id1[j].end());
      int c = 1;
      for (int l = 1; l < cnt; l++){
        if (id1[j][l] == id1[j][l - 1]){
          c++;
        } else {
          c = 1;
        }
        ans += l + 1 - c;
      }
    }
    for (int j = 0; j < m - 1; j++){
      int cnt = id2[j].size();
      sort(id2[j].begin(), id2[j].end());
      int c = 1;
      for (int l = 1; l < cnt; l++){
        if (id2[j][l] == id2[j][l - 1]){
          c++;
        } else {
          c = 1;
        }
        ans += l + 1 - c;
      }
    }
    cout << ans << endl;
  }
}