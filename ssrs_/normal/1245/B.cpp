#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    string s;
    cin >> s;
    int cnt = 0;
    vector<char> ans(n, '?');
    for (int j = 0; j < n; j++){
      if (s[j] == 'R' && b > 0){
        ans[j] = 'P';
        b--;
        cnt++;
      }
      if (s[j] == 'P' && c > 0){
        ans[j] = 'S';
        c--;
        cnt++;
      }
      if (s[j] == 'S' && a > 0){
        ans[j] = 'R';
        a--;
        cnt++;
      }
    }
    if (cnt < (n + 1) / 2){
      cout << "NO" << endl;
    } else {
      for (int j = 0; j < n; j++){
        if (ans[j] == '?'){
          if (a > 0){
            ans[j] = 'R';
            a--;
          } else if (b > 0){
            ans[j] = 'P';
            b--;
          } else {
            ans[j] = 'S';
            c--;
          }
        }
      }
      cout << "YES" << endl;
      for (int j = 0; j < n; j++){
        cout << ans[j];
      }
      cout << endl;
    }
  }
}