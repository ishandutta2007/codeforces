#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 20;
    for (long long j = 1; j < ((long long) 1 << 60); j *= 2){
      string t = to_string(j);
      int m = t.size();
      int pos = 0;
      for (int k = 0; k < n; k++){
        if (s[k] == t[pos]){
          pos++;
          if (pos == m){
            break;
          }
        }
      }
      ans = min(ans, (n - pos) + (m - pos));
    }
    cout << ans << endl;
  }
}