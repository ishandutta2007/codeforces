#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<string> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    vector<vector<vector<int>>> h(10, vector<vector<int>>(n));
    vector<vector<vector<int>>> v(10, vector<vector<int>>(n));
    vector<int> l(10, n), r(10, -1), u(10, n), d(10, -1);
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        h[s[j][k] - '0'][j].push_back(k);
        v[s[j][k] - '0'][k].push_back(j);
        l[s[j][k] - '0'] = min(l[s[j][k] - '0'], k);
        r[s[j][k] - '0'] = max(r[s[j][k] - '0'], k);
        u[s[j][k] - '0'] = min(u[s[j][k] - '0'], j);
        d[s[j][k] - '0'] = max(d[s[j][k] - '0'], j);
      }
    }
    for (int j = 0; j < 10; j++){
      int ans = 0;
      for (int k = 0; k < n; k++){
        if (!h[j][k].empty()){
          int L = h[j][k].front();
          int R = h[j][k].back();
          ans = max(ans, (R - L) * max(k, n - 1 - k));
          ans = max(ans, max(R, n - 1 - L) * max(d[j] - k, k - u[j]));
        }
      }
      for (int k = 0; k < n; k++){
        if (!v[j][k].empty()){
          int U = v[j][k].front();
          int D = v[j][k].back();
          ans = max(ans, (D - U) * max(k, n - 1 - k));
          ans = max(ans, max(D, n - 1 - U) * max(r[j] - k, k - l[j]));
        }
      }
      cout << ans;
      if (j < 9){
        cout << ' ';
      }
    }
    cout << endl;
  }
}