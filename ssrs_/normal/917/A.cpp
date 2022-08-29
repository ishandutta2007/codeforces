#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int N = s.size();
  vector<int> sum(N + 1);
  sum[0] = 0;
  for (int i = 0; i < N; i++){
    sum[i + 1] = sum[i];
    if (s[i] == '?'){
      sum[i + 1]++;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++){
    int sum = 0;
    for (int j = i; j < N; j++){
      if (s[j] == '?'){
        break;
      }
      if (s[j] == '('){
        sum++;
      }
      if (s[j] == ')'){
        sum--;
        if (sum < 0){
          break;
        }
        if (sum == 0){
          ans++;
        }
      }
    }
  }
  vector<vector<int>> pos1(N), pos2(N);
  vector<vector<bool>> p(N + 1, vector<bool>(N + 1, false));
  for (int i = 1; i < N; i++){
    if (s[i - 1] == '?' || s[i] == '?'){
      string s2 = s;
      for (int j = 0; j < N; j++){
        if (s2[j] == '?'){
          if (j < i){
            s2[j] ='(';
          } else {
            s2[j] = ')';
          }
        }
      }
      vector<int> L(i + 1);
      L[0] = 0;
      for (int j = 0; j < i; j++){
        L[j + 1] = L[j];
        if (s2[i - j - 1] == '('){
          L[j + 1]--;
        } else {
          L[j + 1]++;
        }
      }
      int mn1 = 0;
      vector<bool> ok1(i + 1, false);
      for (int j = 0; j <= i; j++){
        mn1 = min(mn1, L[j]);
        if (mn1 == L[j]){
          ok1[j] = true;
        }
      }
      for (int j = 0; j <= i; j++){
        if (L[j] <= 0 && ok1[j]){
          pos1[-L[j]].push_back(j);
        }
      }
      vector<int> R(N - i + 1);
      R[0] = 0;
      for (int j = 0; j < N - i; j++){
        R[j + 1] = R[j];
        if (s2[i + j] == ')'){
          R[j + 1]--;
        } else {
          R[j + 1]++;
        }
      }
      int mn2 = 0;
      vector<bool> ok2(N - i + 1, false);
      for (int j = 0; j <= N - i; j++){
        mn2 = min(mn2, R[j]);
        if (mn2 == R[j]){
          ok2[j] = true;
        }
      }
      for (int j = 0; j <= N - i; j++){
        if (R[j] <= 0 && ok2[j]){
          pos2[-R[j]].push_back(j);
        }
      }
      int mx = min(i, N - i);
      for (int j = 0; j <= mx; j++){
        int cnt1 = pos1[j].size();
        int cnt2 = pos2[j].size();
        for (int k = 0; k < cnt1; k++){
          for (int l = 0; l < cnt2; l++){
            int L = i - pos1[j][k];
            int R = i + pos2[j][l];
            if (sum[R] - sum[L] > 0){
              p[L][R] = true;
            }
          }
        }
      }
      for (int j = 0; j <= i; j++){
        pos1[j].clear();
      }
      for (int j = 0; j <= N - i; j++){
        pos2[j].clear();
      }
    }
  }
  for (int i = 0; i <= N; i++){
    for (int j = i; j <= N; j++){
      if (p[i][j]){
        ans++;
      }
    }
  }
  cout << ans << endl;
}