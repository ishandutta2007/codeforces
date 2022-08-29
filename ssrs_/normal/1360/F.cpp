#include <bits/stdc++.h>
using namespace std;
int dist(string &s, string &t){
  int m = s.size();
  int ans = 0;
  for (int i = 0; i < m; i++){
    if (s[i] != t[i]){
      ans++;
    }
  }
  return ans;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<string> p;
    p.push_back(a[0]);
    for (int j = 0; j < m; j++){
      for (int k = 0; k < 26; k++){
        if (a[0][j] != 'a' + k){
          string tmp = a[0];
          tmp[j] = 'a' + k;
          p.push_back(tmp);
        }
      }
    }
    string ans = "-1";
    for (string s : p){
      bool ok = true;
      for (int j = 0; j < n; j++){
        if (dist(s, a[j]) >= 2){
          ok = false;
          break;
        }
      }
      if (ok){
        ans = s;
        break;
      }
    }
    cout << ans << endl;
  }
}