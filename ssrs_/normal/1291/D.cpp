#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int N = s.size();
  vector<vector<int>> S(26, vector<int>(N + 1));
  for (int i = 0; i < 26; i++){
    S[i][0] = 0;
    for (int j = 0; j < N; j++){
      S[i][j + 1] = S[i][j];
      if (s[j] == 'a' + i){
        S[i][j + 1]++;
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    l--;
    if (r - l == 1){
      cout << "Yes" << endl;
    } else if (s[l] != s[r - 1]){
      cout << "Yes" << endl;
    } else {
      int cnt = 0;
      for (int j = 0; j < 26; j++){
        if (S[j][r] - S[j][l] > 0){
          cnt++;
        }
      }
      if (cnt > 2){
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}