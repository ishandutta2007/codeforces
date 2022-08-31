#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  string t = s.substr(5);
  int N = t.size();
  vector<bool> dp2(N + 1, false);
  vector<bool> dp3(N + 1, false);
  dp2[N] = true;
  dp3[N] = true;
  set<string> ans;
  for (int i = N - 1; i >= 0; i--){
    if (i + 2 <= N){
      string sf = t.substr(i, 2);
      if (dp3[i + 2]){
        dp2[i] = true;
        ans.insert(sf);
      } else if (dp2[i + 2]){
        string s2 = t.substr(i + 2, 2);
        if (sf != s2){
          dp2[i] = true;
          ans.insert(sf);
        }
      }
    }
    if (i + 3 <= N){
      string sf = t.substr(i, 3);
      if (dp2[i + 3]){
        dp3[i] = true;
        ans.insert(sf);
      } else if (dp3[i + 3]){
        string s2 = t.substr(i + 3, 3);
        if (sf != s2){
          dp3[i] = true;
          ans.insert(sf);
        }
      }
    }
  }
  int k = ans.size();
  cout << k << endl;
  for (string S : ans){
    cout << S << endl;
  }
}