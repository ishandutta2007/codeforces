#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
      b[j]--;
    }
    vector<int> c(m);
    for (int j = 0; j < m; j++){
      cin >> c[j];
      c[j]--;
    }
    vector<vector<int>> id(n);
    int sum = 0;
    for (int j = 0; j < n; j++){
      if (a[j] != b[j]){
        id[b[j]].push_back(j);
        sum++;
      }
    }
    bool ok = true;
    vector<int> x(m, -1);
    for (int j = 0; j < n; j++){
      if (b[j] == c[m - 1]){
        x[m - 1] = j;
      }
    }
    if (x[m - 1] == -1){
      ok = false;
    } else {
      for (int j = m - 1; j >= 0; j--){
        if (id[c[j]].empty()){
          x[j] = x[m - 1];
        } else {
          x[j] = id[c[j]].back();
          id[c[j]].pop_back();
        }
      }
      for (int j = 0; j < n; j++){
        if (!id[j].empty()){
          ok = false;
        }
      }
    }
    if (!ok){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int j = 0; j < m; j++){
        cout << x[j] + 1;
        if (j < m - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}