#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> s(m, 0);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (a[i][j] == '1'){
        s[j]++;
      }
    }
  }
  bool ok = false;
  for (int i = 0; i < n; i++){
    bool ok2 = true;
    for (int j = 0; j < m; j++){
      if (a[i][j] == '1' && s[j] == 1){
        ok2 = false;
      }
    }
    if (ok2){
      ok = true;
    }
  }
  if (ok){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}