#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    string s;
    cin >> s;
    int N = s.size();
    map<char, int> mp;
    for (int j = 0; j < N; j++){
      mp[s[j]]++;
    }
    vector<pair<char, int>> f;
    for (auto P : mp){
      f.push_back(P);
    }
    int cnt = f.size();
    vector<string> t(cnt);
    for (int j = 0; j < cnt; j++){
      t[j] = string(f[j].second, f[j].first);
    }
    string ans;
    bool ok = true;
    if (cnt == 1){
      ans = t[0];
    } else if (cnt == 2){
      if (f[0].first + 1 == f[1].first){
        ok = false;
      } else {
        ans = t[0] + t[1];
      }
    } else if (cnt == 3){
      if (f[0].first + 1 == f[1].first){
        if (f[1].first + 1 == f[2].first){
          ok = false;
        } else {
          ans = t[1] + t[2] + t[0];
        }
      } else {
        ans = t[1] + t[0] + t[2];
      }
    } else {
      for (int j = 1; j < cnt; j += 2){
        ans += t[j];
      }
      for (int j = 0; j < cnt; j += 2){
        ans += t[j];
      }
    }
    if (ok){
      cout << ans << endl;
    } else {
      cout << "No answer" << endl;
    }
  }
}