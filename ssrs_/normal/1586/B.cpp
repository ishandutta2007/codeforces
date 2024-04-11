#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m), c(m);
    for (int j = 0; j < m; j++){
      cin >> a[j] >> b[j] >> c[j];
      a[j]--;
      b[j]--;
      c[j]--;
    }
    vector<bool> used(n, false);
    for (int j = 0; j < m; j++){
      used[b[j]] = true;
    }
    int r = 0;
    for (int j = 0; j < n; j++){
      if (!used[j]){
        r = j;
      }
    }
    for (int j = 0; j < n; j++){
      if (j != r){
        cout << j + 1 << ' ' << r + 1 << "\n";
      }
    }
  }
}