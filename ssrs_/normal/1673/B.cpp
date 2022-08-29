#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    vector<bool> used(26, false);
    for (int j = 0; j < n; j++){
      used[s[j] - 'a'] = true;
    }
    int cnt = 0;
    for (int j = 0; j < 26; j++){
      if (used[j]){
        cnt++;
      }
    }
    bool ok = true;
    for (int j = 0; j < cnt; j++){
      for (int k = j + 1; k < cnt; k++){
        if (s[j] == s[k]){
          ok = false;
        }
      }
    }
    for (int j = cnt; j < n; j++){
      if (s[j] != s[j - cnt]){
        ok = false;
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}