#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    vector<vector<int>> p(26);
    for (int j = 0; j < N; j++){
      p[s[j] - 'a'].push_back(j);
    }
    vector<bool> used(26, false);
    string ans;
    for (int j = 0; j < N; j++){
      string ans2 = ans;
      vector<bool> used2 = used;
      bool ok = true;
      while (!ans.empty()){
        if (j <= p[ans.back() - 'a'].back() && ans.back() <= s[j]){
          ok = ans.back() != s[j];
          used[ans.back() - 'a'] = false;
          ans.pop_back();
        } else {
          break;
        }
      }
      if (!ok || used2[s[j] - 'a']){
        ans = ans2;
        used = used2;
      } 
      if (!used[s[j] - 'a']){
        used[s[j] - 'a'] = true;
        ans.push_back(s[j]);
      }
    }
    cout << ans << endl;
  }
}