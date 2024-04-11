#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> transpose(vector<vector<int>> &a){
  int n = a.size();
  int m = a[0].size();
  vector<vector<int>> res(m, vector<int>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      res[j][i] = a[i][j];
    }
  }
  return res;
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  string S = "AGCT";
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      for (int k = 0; k < 4; k++){
        if (s[i][j] == S[k]){
          a[i][j] = k;
        }
      }
    }
  }
  int mn = n * m + 1;
  vector<vector<int>> ans;
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 4; j++){
      for (int k = j + 1; k < 4; k++){
        vector<vector<int>> A(2);
        for (int l = 0; l < 4; l++){
          if (l == j || l == k){
            A[0].push_back(l);
          } else {
            A[1].push_back(l);
          }
        }
        int sum = 0;
        vector<vector<int>> tmp = a;
        for (int y = 0; y < n; y++){
          int t1 = m, t2 = m;
          for (int x = 0; x < m; x++){
            if (a[y][x] == A[y % 2][x % 2]){
              t1--;
            }
            if (a[y][x] == A[y % 2][(x + 1) % 2]){
              t2--;
            }
          }
          sum += min(t1, t2);
          if (t1 <= t2){
            for (int x = 0; x < m; x++){
              tmp[y][x] = A[y % 2][x % 2];
            }
          } else {
            for (int x = 0; x < m; x++){
              tmp[y][x] = A[y % 2][(x + 1) % 2];
            }
          }
        }
        if (sum < mn){
          mn = sum;
          if (i == 0){
            ans = tmp;
          } else {
            ans = transpose(tmp);
          }
        }
      }
    }
    a = transpose(a);
    swap(n, m);
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cout << S[ans[i][j]];
    }
    cout << endl;
  }
}