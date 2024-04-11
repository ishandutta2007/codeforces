#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int win = 0;
    for (int j = 0; j < n; j++){
      if (s[j] == 'W'){
        win++;
      }
    }
    if (win + k >= n){
      cout << n * 2 - 1 << endl;
    } else if (win == 0){
      if (k == 0){
        cout << 0 << endl;
      } else {
        cout << k * 2 - 1 << endl;
      }
    } else {
      int cscore = 0;
      int con = 0;
      vector<int> l;
      for (int j = 0; j < n; j++){
        if (s[j] == 'W'){
          if (con > 0 && cscore > 0){
            l.push_back(con);
          }
          con = 0;
          cscore++;
          if (j > 0){
            if (s[j - 1] == 'W'){
              cscore++;
            }
          }
        } else {
          con++;
        }
      }
      l.push_back(n);
      sort(l.begin(), l.end());
      int ans = cscore + 2 * k;
      for (int j : l){
        if (k >= j){
          ans++;
          k -= j;
        }
      }
      cout << ans << endl;
    }
  }
}