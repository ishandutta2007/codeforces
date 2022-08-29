#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> matmul(vector<vector<int>> A, vector<vector<int>> B){
  int N = A.size();
  vector<vector<int>> ans(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++){
    for (int j = i; j < N; j++){
      for (int k = j; k < N; k++){
        ans[i][k] = max(ans[i][k], A[i][j] + B[j][k]);
      }
    }
  }
  return ans;
}
vector<vector<int>> matexp(vector<vector<int>> A, long long b){
  int N = A.size();
  vector<vector<int>> ans(N, vector<int>(N, 0));
  while (b > 0){
    if (b % 2 == 1){
      ans = matmul(ans, A);
    }
    A = matmul(A, A);
    b /= 2;
  }
  return ans;
}
int main(){
  int n, T;
  cin >> n >> T;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> x;
  for (int i = 0; i < n; i++){
    x.push_back(a[i]);
  }
  sort(x.begin(), x.end());
  x.erase(unique(x.begin(), x.end()), x.end());
  int cnt = x.size();
  map<int, int> mp;
  for (int i = 0; i < cnt; i++){
    mp[x[i]] = i;
  }
  for (int i = 0; i < n; i++){
    a[i] = mp[a[i]];
  }
  vector<vector<int>> M(cnt, vector<int>(cnt, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= a[i]; j++){
      for (int k = a[i]; k >= j; k--){
        M[j][a[i]] = max(M[j][a[i]], M[j][k] + 1);
      }
    }
  }
  M = matexp(M, T);
  int ans = 0;
  for (int i = 0; i < cnt; i++){
    for (int j = 0; j < cnt; j++){
      ans = max(ans, M[i][j]);
    }
  }
  cout << ans << endl;
}