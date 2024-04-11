#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int j = 0; j < min(m, n); j++){
      string t = s;
      for (int k = 0; k < n; k++){
        if (s[k] == '0'){
          int cnt = 0;
          if (k > 0){
            cnt += s[k - 1] - '0';
          }
          if (k < n - 1){
            cnt += s[k + 1] - '0';
          }
          if (cnt == 1){
            t[k] = '1';
          }
        }
      }
      swap(s, t);
    }
    cout << s << "\n";
  }
}