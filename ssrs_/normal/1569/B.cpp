#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p;
    vector<int> q;
    for (int j = 0; j < n; j++){
      if (s[j] == '1'){
        p.push_back(j);
      }
      if (s[j] == '2'){
        q.push_back(j);
      }
    }
    int cnt1 = p.size();
    int cnt2 = q.size();
    if (cnt2 == 1 || cnt2 == 2){
      cout << "NO" << endl;
    } else {
      vector<vector<char>> ans(n, vector<char>(n, '='));
      for (int j = 0; j < n; j++){
        ans[j][j] = 'X';
      }
      for (int j = 0; j < cnt1; j++){
        for (int k = 0; k < n; k++){
          if (s[k] == '2'){
            ans[p[j]][k] = '+';
            ans[k][p[j]] = '-';
          }
        }
      }
      for (int j = 0; j < cnt2; j++){
        int a = q[j];
        int b = q[(j + 1) % cnt2];
        ans[a][b] = '+';
        ans[b][a] = '-';
      }
      cout << "YES" << endl;
      for (int j = 0; j < n; j++){
        for (int k = 0; k < n; k++){
          cout << ans[j][k];
        }
        cout << endl;
      }
    }
  }
}