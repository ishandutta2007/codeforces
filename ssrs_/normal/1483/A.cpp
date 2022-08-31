#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> k(m);
    vector<vector<int>> f(m);
    for (int j = 0; j < m; j++){
      cin >> k[j];
      f[j] = vector<int>(k[j]);
      for (int l = 0; l < k[j]; l++){
        cin >> f[j][l];
        f[j][l]--;
      }
    }
    vector<int> c(m);
    vector<int> cnt(n, 0);
    for (int j = 0; j < m; j++){
      if (k[j] == 1){
        c[j] = f[j][0];
        cnt[c[j]]++;
      }
    }
    for (int j = 0; j < m; j++){
      if (k[j] > 1){
        int id = 0;
        for (int l = 1; l < k[j]; l++){
          if (cnt[f[j][l]] < cnt[f[j][id]]){
            id = l;
          }
        }
        c[j] = f[j][id];
        cnt[c[j]]++;
      }
    }
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (cnt[j] > (m + 1) / 2){
        ok = false;
      }
    }
    if (!ok){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int j = 0; j < m; j++){
        cout << c[j] + 1;
        if (j < m - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}