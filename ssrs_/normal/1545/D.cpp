#include <bits/stdc++.h>
using namespace std;
int main(){
  int m, k;
  cin >> m >> k;
  vector<vector<int>> A(k, vector<int>(m));
  for (int i = 0; i < k; i++){
    for (int j = 0; j < m; j++){
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < k; i++){
    sort(A[i].begin(), A[i].end());
  }
  vector<int> sum1(k, 0);
  for (int i = 0; i < k; i++){
    for (int j = 0; j < m; j++){
      sum1[i] += A[i][j];
    }
  }
  vector<long long> sum2(k, 0);
  for (int i = 0; i < k; i++){
    long long tmp = 0;
    for (int j = m - 1; j >= 0; j--){
      sum2[i] += tmp * A[i][j];
      tmp += A[i][j];
    }
  }
  vector<int> d(k - 1, 0);
  for (int i = 0; i < k - 1; i++){
    d[i] = sum1[i + 1] - sum1[i];
  }
  map<int, int> mp;
  for (int i = 0; i < k - 1; i++){
    mp[d[i]]++;
  }
  int mx = 0, mode = -1;
  for (auto P : mp){
    if (P.second > mx){
      mx = P.second;
      mode = P.first;
    }
  }
  int y;
  int D;
  if (d[0] != mode && d[1] == mode){
    y = 0;
    D = mode - d[0];
  } else if (d[k - 2] != mode && d[k - 3] == mode){
    y = k - 1;
    D = d[k - 2] - mode;
  } else {
    for (int i = 0; i < k - 1; i++){
      if (d[i] != mode){
        y = i + 1;
        D = d[i] - mode;
        break;
      }
    }
  }
  long long c;
  if (y >= 3){
    c = sum2[y - 1] * 3 - sum2[y - 2] * 3 + sum2[y - 3];
  } else {
    c = sum2[y + 1] * 3 - sum2[y + 2] * 3 + sum2[y + 3];
  }
  cout << y << ' ' << sum1[y] - (sum2[y] - c) / D - D << endl;
}