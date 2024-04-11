#include <bits/stdc++.h>
using namespace std;
int main(){
  string n;
  cin >> n;
  int d = n.size();
  vector<vector<int>> num(9, vector<int>(d, 0));
  int mx = 0;
  for (int i = 0; i < d; i++){
    mx = max(mx, n[i] - '0');
    for (int j = 0; j < n[i] - '0'; j++){
      num[j][i] = 1;
    }
  }
  cout << mx << endl;
  vector<string> ans(mx);
  for (int i = 0; i < mx; i++){
    for (int j = 0; j < d; j++){
      if (num[i][j] == 0){
        if (ans[i] != ""){
          ans[i] += '0';
        }
      } else {
        ans[i] += '1';
      }
    }
  }
  for (int i = 0; i < mx; i++){
    cout << ans[i];
    if (i < mx - 1){
      cout << ' ';
    }
  }
  cout << endl;
}