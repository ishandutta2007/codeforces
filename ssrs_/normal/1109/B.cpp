#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int n = s.size();
  bool ok = false;
  for (int i = 1; i < n; i++){
    if (s[i] != s[0] && i * 2 + 1 != n){
      ok = true;
    }
  }
  if (!ok){
    cout << "Impossible" << endl;
  } else {
    int ans = 2;
    for (int i = 1; i < n - 1; i++){
      string t = s.substr(i) + s.substr(0, i);
      string t2 = t;
      reverse(t2.begin(), t2.end());
      if (t == t2 && t != s){
        ans = 1;
      }
    }
    cout << ans << endl;
  }
}