#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<int>> S(6, vector<int>(n + 1));
  for (int i = 0; i < 6; i++){
    S[i][0] = 0;
    for (int j = 0; j < n; j++){
      S[i][j + 1] = S[i][j];
      if (i < 3){
        if (s[j] - 'a' != (i + j) % 3){
          S[i][j + 1]++;
        }
      } else {
        if (s[j] - 'a' != (i - j % 3 + 3) % 3){
          S[i][j + 1]++;
        }
      }
    }
  }
  for (int i = 0; i < m; i++){
    int l, r;
    cin >> l >> r;
    l--;
    int ans = INF;
    for (int j = 0; j < 6; j++){
      ans = min(ans, S[j][r] - S[j][l]);
    }
    cout << ans << "\n";
  }
}