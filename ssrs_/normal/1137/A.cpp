#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  vector<vector<int>> h1(n, vector<int>(m));
  vector<vector<int>> h2(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    vector<int> b = a[i];
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int cnt = b.size();
    for (int j = 0; j < m; j++){
      h1[i][j] = lower_bound(b.begin(), b.end(), a[i][j]) - b.begin();
      h2[i][j] = cnt - 1 - h1[i][j];
    }
  }
  vector<vector<int>> v1(n, vector<int>(m));
  vector<vector<int>> v2(n, vector<int>(m));
  for (int i = 0; i < m; i++){
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      b[j] = a[j][i];
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int cnt = b.size();
    for (int j = 0; j < n; j++){
      v1[j][i] = lower_bound(b.begin(), b.end(), a[j][i]) - b.begin();
      v2[j][i] = cnt - 1 - v1[j][i];
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cout << max(h1[i][j], v1[i][j]) + max(h2[i][j], v2[i][j]) + 1;
      if (j < m - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}