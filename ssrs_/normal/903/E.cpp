#include <bits/stdc++.h>
using namespace std;
int main(){
  int k, n;
  cin >> k >> n;
  vector<string> s(k);
  for (int i = 0; i < k; i++){
    cin >> s[i];
  }
  if (s == vector<string>(k, s[0])){
    swap(s[0][0], s[0][1]);
    cout << s[0] << endl;
  } else {
    vector<string> s2 = s;
    for (int i = 0; i < k; i++){
      sort(s2[i].begin(), s2[i].end());
    }
    bool ok = true;
    for (int i = 1; i < k; i++){
      if (s2[i] != s2[0]){
        ok = false;
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      int x = -1;
      for (int i = 1; i < k; i++){
        if (s[i] != s[0]){
          x = i;
        }
      }
      vector<int> d;
      for (int i = 0; i < n; i++){
        if (s[0][i] != s[x][i]){
          d.push_back(i);
        }
      }
      if (d.size() > 4){
        cout << -1 << endl;
      } else {
        vector<int> f(26, 0);
        for (int i = 0; i < n; i++){
          f[s[0][i] - 'a']++;
        }
        int mx = 0;
        for (int i = 0; i < 26; i++){
          mx = max(mx, f[i]);
        }
        vector<string> t;
        t.push_back(s[0]);
        t.push_back(s[x]);
        if (d.size() == 2){
          for (int i = 0; i < n; i++){
            if (i != d[0] && i != d[1]){
              if (s[0][i] == s[0][d[0]]){
                string tmp = s[0];
                swap(tmp[i], tmp[d[1]]);
                t.push_back(tmp);
              }
              if (s[0][i] == s[0][d[1]]){
                string tmp = s[0];
                swap(tmp[i], tmp[d[0]]);
                t.push_back(tmp);
              }
            }
          }
        } else {
          int cnt = d.size();
          for (int i = 0; i < cnt; i++){
            for (int j = i + 1; j < cnt; j++){
              string tmp = s[0];
              swap(tmp[d[i]], tmp[d[j]]);
              t.push_back(tmp);
            }
          }
        }
        int cnt = t.size();
        string ans = "-1";
        for (int i = 0; i < cnt; i++){
          bool ok2 = true;
          for (int j = 0; j < k; j++){
            vector<int> p;
            for (int l = 0; l < n; l++){
              if (s[j][l] != t[i][l]){
                p.push_back(l);
              }
            }
            if (p.size() > 2 || p.empty() && mx == 1){
              ok2 = false;
            }
          }
          if (ok2){
            ans = t[i];
          }
        }
        cout << ans << endl;
      }
    }
  }
}