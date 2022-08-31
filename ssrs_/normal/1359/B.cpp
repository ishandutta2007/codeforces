#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    y = min(y, x * 2);
    vector<string> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      vector<int> w(1, 0);
      for (int k = 0; k < m; k++){
        if (a[j][k] == '.'){
          w.back()++;
        } else {
          w.push_back(0);
        }
      }
      for (int k = 0; k < w.size(); k++){
        ans += w[k] / 2 * y + w[k] % 2 * x;
      }
    }
    cout << ans << endl;
  }
}