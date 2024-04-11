#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> C(n);
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    int t = b - a;
    if (t < 0){
      t += n;
    }
    C[a].push_back(make_pair(t, b));
  }
  for (int i = 0; i < n; i++){
    sort(C[i].begin(), C[i].end());
  }
  vector<int> ans(n, 0);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (!C[j].empty()){
        int t = j - i;
        if (t < 0){
          t += n;
        }
        int t2 = (C[j].size() - 1) * n + C[j][0].first;
        ans[i] = max(ans[i], t + t2);
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << ans[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}