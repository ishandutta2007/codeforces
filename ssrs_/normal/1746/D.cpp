#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> &in, vector<vector<int>> &c, int v){
  in.push_back(v);
  for (int w : c[v]){
    dfs(in, c, w);
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int j = 1; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    vector<int> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    vector<vector<int>> c(n);
    for (int j = 1; j < n; j++){
      c[p[j]].push_back(j);
    }
    vector<int> in;
    dfs(in, c, 0);
    vector<long long> C(n);
    C[0] = k;
    for (int j = 1; j < n; j++){
      C[in[j]] = C[p[in[j]]] / c[p[in[j]]].size();
    }
    vector<long long> dp1(n, 0), dp2(n, 0);
    for (int j = n - 1; j >= 0; j--){
      int v = in[j];
      int cnt = c[v].size();
      if (cnt == 0){
        dp1[v] = (long long) C[v] * s[v];
        dp2[v] = (long long) (C[v] + 1) * s[v];
      } else {
        vector<long long> A(cnt), B(cnt);
        for (int l = 0; l < cnt; l++){
          A[l] = dp1[c[v][l]];
          B[l] = dp2[c[v][l]];
        }
        long long ans = (long long) C[v] * s[v];
        for (int l = 0; l < cnt; l++){
          ans += A[l];
        }
        vector<long long> D(cnt);
        for (int l = 0; l < cnt; l++){
          D[l] = B[l] - A[l];
        }
        sort(D.begin(), D.end(), greater<long long>());
        int r = C[v] % cnt;
        for (int l = 0; l < r; l++){
          ans += D[l];
        }
        dp1[v] = ans;
        dp2[v] = ans + s[v] + D[r];
      }
    }
    cout << dp1[0] << "\n";
  }
}