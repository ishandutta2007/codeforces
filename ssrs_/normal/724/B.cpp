#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> A(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> A[i][j];
      A[i][j]--;
    }
  }
  vector<int> p(m);
  for (int i = 0; i < m; i++){
    p[i] = i;
  }
  vector<vector<int>> p2;
  p2.push_back(p);
  for (int i = 0; i < m; i++){
    for (int j = i + 1; j < m; j++){
      swap(p[i], p[j]);
      p2.push_back(p);
      swap(p[i], p[j]);
    }
  }
  int cnt = p2.size();
  bool ok = false;
  for (int i = 0; i < cnt; i++){
    bool ok2 = true;
    for (int j = 0; j < n; j++){
      int cnt = 0;
      for (int k = 0; k < m; k++){
        if (A[j][k] != p2[i][k]){
          cnt++;
        }
      }
      if (cnt > 2){
        ok2 = false;
      }
    }
    if (ok2){
      ok = true;
    }
  }
  if (ok){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}