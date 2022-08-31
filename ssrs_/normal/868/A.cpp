#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<string> t(n);
  for (int i = 0; i < n; i++){
    cin >> t[i];
  }
  bool ok = false;
  for (int i = 0; i < n; i++){
    if (s == t[i]){
      ok = true;
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      string tt = t[i] + t[j];
      if (s == tt.substr(1, 2)){
        ok = true;
      }
    }
  }
  if (ok){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}