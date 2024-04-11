#include <bits/stdc++.h>
using namespace std;
const int B = 15;
int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  int m;
  cin >> m;
  vector<string> pr(n + m), sf(n + m);
  for (int i = 0; i < n; i++){
    int L = s[i].size();
    if (L >= B){
      pr[i] = s[i].substr(0, B);
      sf[i] = s[i].substr(L - B);
    } else {
      pr[i] = s[i];
      sf[i] = s[i];
    }
  }
  vector<vector<vector<bool>>> c(n + m, vector<vector<bool>>(B));
  for (int i = 0; i < n + m; i++){
    for (int j = 0; j < B; j++){
      c[i][j] = vector<bool>(1 << (j + 1), false);
    }
  }
  for (int i = 0; i < n; i++){
    int L = s[i].size();
    for (int j = 0; j < L; j++){
      int sum = 0;
      for (int k = j; k < L; k++){
        if (k - j >= B){
          break;
        }
        if (s[i][k] == '1'){
          sum += 1 << (k - j);
        }
        c[i][k - j][sum] = true;
      }
    }
  }
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    pr[n + i] = pr[a] + pr[b];
    int L1 = pr[n + i].size();
    if (L1 >= B){
      pr[n + i] = pr[n + i].substr(0, B);
    }
    sf[n + i] = sf[a] + sf[b];
    int L2 = sf[n + i].size();
    if (L2 >= B){
      sf[n + i] = sf[n + i].substr(L2 - B);
    }
    for (int j = 0; j < B; j++){
      for (int k = 0; k < (1 << (j + 1)); k++){
        if (c[a][j][k] || c[b][j][k]){
          c[n + i][j][k] = true;
        }
      }
    }
    string t = sf[a] + pr[b];
    int L = t.size();
    for (int j = 0; j < L; j++){
      int sum = 0;
      for (int k = j; k < L; k++){
        if (k - j >= B){
          break;
        }
        if (t[k] == '1'){
          sum += 1 << (k - j);
        }
        c[n + i][k - j][sum] = true;
      }
    }
    int ans = -1;
    for (int j = 0; j < B; j++){
      for (int k = 0; k < (1 << (j + 1)); k++){
        if (!c[n + i][j][k]){
          ans = j;
          break;
        }
      }
      if (ans != -1){
        break;
      }
    }
    cout << ans << endl;
  }
}