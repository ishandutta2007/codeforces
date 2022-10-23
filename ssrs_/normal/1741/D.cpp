#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0;  i < t; i++){
    int m;
    cin >> m;
    vector<int> p(m);
    for (int j = 0; j < m; j++){
      cin >> p[j];
    }
    vector<int> mn(m * 2 - 1), mx(m * 2 - 1);
    for (int j = 0; j < m; j++){
      mn[m - 1 + j] = p[j];
      mx[m - 1 + j] = p[j];
    }
    for (int j = m - 2; j >= 0; j--){
      mn[j] = min(mn[j * 2 + 1], mn[j * 2 + 2]);
      mx[j] = max(mx[j * 2 + 1], mx[j * 2 + 2]);
    }
    bool ok = true;
    int ans = 0;
    for (int j = 0; j < m - 1; j++){
      if (mx[j * 2 + 1] < mn[j * 2 + 2]){
      } else if (mx[j * 2 + 2] < mn[j * 2 + 1]){
        ans++;
      } else {
        ok = false;
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}