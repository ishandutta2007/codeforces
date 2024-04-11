#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int L = 1;
    int ans = 1;
    for (int j = 0; j < s.size(); j++){
      if (s[j] == 'L'){
        L++;
      } else {
        L = 1;
      }
      ans = max(ans, L);
    }
    cout << ans << endl;
  }
}