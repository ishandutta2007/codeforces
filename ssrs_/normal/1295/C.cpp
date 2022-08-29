#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    string s;
    cin >> s;
    string t;
    cin >> t;
    int n = s.size();
    int m = t.size();
    vector<set<int>> st(26);
    for (int j = 0; j < n; j++){
      st[s[j] - 'a'].insert(j);
    }
    int ans = 1;
    bool ok = true;
    int p = -1;
    for (int j = 0; j < m; j++){
      int id = t[j] - 'a';
      if (st[id].empty()){
        ok = false;
        break;
      } else {
        auto itr = st[id].upper_bound(p);
        if (itr == st[id].end()){
          ans++;
          p = *st[id].begin();
        } else {
          p = *itr;
        }
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}