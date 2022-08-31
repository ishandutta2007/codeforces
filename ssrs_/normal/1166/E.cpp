#include <bits/stdc++.h>
using namespace std;
int main(){
  int m, n;
  cin >> m >> n;
  vector<int> s(m);
  vector<vector<bool>> a(m, vector<bool>(n, false));
  for (int i = 0; i < m; i++){
    cin >> s[i];
    for (int j = 0; j < s[i]; j++){
      int x;
      cin >> x;
      x--;
      a[i][x] = true;
    }
  }
  bool ok = true;
  for (int i = 0; i < m; i++){
    for (int j = i + 1; j < m; j++){
      bool ok2 = false;
      for (int k = 0; k < n; k++){
        if (a[i][k] && a[j][k]){
          ok2 = true;
        }
      }
      if (!ok2){
        ok = false;
      }
    }
  }
  if (ok){
    cout << "possible" << endl;
  } else {
    cout << "impossible" << endl;
  }
}