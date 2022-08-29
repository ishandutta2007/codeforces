#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    int cnt1 = 0, cnt2 = 0;
    int ans = 0;
    for (int j = 0; j < n; j++){
      if (s[j] == '('){
        cnt1++;
      }
      if (s[j] == ')'){
        if (cnt1 > 0){
          cnt1--;
          ans++;
        }
      }
      if (s[j] == '['){
        cnt2++;
      }
      if (s[j] == ']'){
        if (cnt2 > 0){
          cnt2--;
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
}