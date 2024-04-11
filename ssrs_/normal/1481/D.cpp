#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<string> S(n);
    for (int j = 0; j < n; j++){
      cin >> S[j];
    }
    vector<int> ans(m + 1, -1);
    if (m % 2 == 1){
      for (int j = 0; j <= m; j++){
        ans[j] = j % 2;
      }
    } else {
      int A = -1, B = -1;
      for (int j = 0; j < n; j++){
        for (int k = j + 1; k < n; k++){
          if (S[j][k] == S[k][j]){
            A = j;
            B = k;
          }
        }
      }
      if (!(A == -1 && B == -1)){
        for (int j = 0; j <= m; j++){
          if (j % 2 == 0){
            ans[j] = A;
          } else {
            ans[j] = B;
          }
        }
      } else {
        if (n >= 3){
          int A, B, C;
          for (int j = 0; j < n; j++){
            int a = -1, b = -1;
            for (int k = 0; k < n; k++){
              if (S[k][j] == 'a'){
                a = k;
              }
              if (S[k][j] == 'b'){
                b = k;
              }
            }
            if (a != -1 && b != -1){
              A = a;
              B = b;
              C = j;
              break;
            }
          }
          if (m % 4 == 2){
            for (int j = 0; j <= m; j++){
              if (j % 4 == 0){
                ans[j] = A;
              } else if (j % 4 == 2){
                ans[j] = B;
              } else {
                ans[j] = C;
              }
            }
          } else {
            for (int j = 0; j <= m; j++){
              if (j % 4 == 3){
                ans[j] = A;
              } else if (j % 4 == 1){
                ans[j] = B;
              } else {
                ans[j] = C;
              }
            }
          }
        }
      }
    }
    if (ans[0] == -1){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int j = 0; j <= m; j++){
        cout << ans[j] + 1;
        if (j < m){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}