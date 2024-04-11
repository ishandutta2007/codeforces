#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> b(m);
    for (int j = 0; j < m; j++){
      cin >> b[j];
      b[j]--;
    }
    if ((n - m) % (k - 1) != 0){
      cout << "NO" << endl;
    } else {
      vector<bool> a(n, true);
      for (int j = 0; j < m; j++){
        a[b[j]] = false;
      }
      vector<int> c;
      for (int j = 0; j < n; j++){
        if (a[j]){
          c.push_back(j);
        }
      }
      int p = (k - 1) / 2;
      bool ok = false;
      for (int j = p; j <= n - m - p; j++){
        if (c[j] - c[j - 1] > 1){
          ok = true;
        }
      }
      if (ok){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}