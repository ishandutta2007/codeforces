#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    vector<string> g(p);
    for (int j = 0; j < n; j++){
      g[j % p] += s[j];
    }
    vector<int> A(p, 0);
    for (int j = 0; j < p; j++){
      for (char c : g[j]){
        if (c == '1'){
          A[j]++;
        }
      }
    }
    vector<int> B(p, 0);
    for (int j = 0; j < p; j++){
      int m = g[j].size();
      vector<int> sum(m + 1, 0);
      for (int k = 0; k < m; k++){
        if (g[j][k] == '1'){
          sum[k + 1] = sum[k] - 1;
        } else {
          sum[k + 1] = sum[k] + 1;
        }
      }
      int M = 0;
      int cmax = sum[0];
      for (int k = 1; k <= m; k++){
        M = max(M, cmax - sum[k]);
        cmax = max(cmax, sum[k]);
      }
      B[j] = A[j] - M;
    }
    long long sum = 0;
    for (int j = 0; j < p; j++){
      sum += A[j];
    }
    long long ans = sum;
    for (int j = 0; j < p; j++){
      ans = min(ans, sum - A[j] + B[j]);
    }
    cout << ans << endl;
  }
}