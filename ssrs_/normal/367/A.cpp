#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int N = s.size();
  vector<vector<int>> S(3, vector<int>(N + 1, 0));
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < N; j++){
      S[i][j + 1] = S[i][j];
      if (s[j] - 'x' == i){
        S[i][j + 1]++;
      }
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++){
    int l, r;
    cin >> l >> r;
    l--;
    if (r - l < 3){
      cout << "YES" << "\n";
    } else {
      int mx = 0, mn = N;
      for (int j = 0; j < 3; j++){
        mx = max(mx, S[j][r] - S[j][l]);
        mn = min(mn, S[j][r] - S[j][l]);
      }
      if (mx - mn <= 1){
        cout << "YES" << "\n";
      } else {
        cout << "NO" << "\n";
      }
    }
  }
}