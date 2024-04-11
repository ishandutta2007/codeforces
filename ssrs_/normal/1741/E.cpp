#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    vector<bool> ok(n + 1, false);
    ok[0] = true;
    for (int j = 0; j <= n; j++){
      if (j > 0){
        if (j - b[j - 1] >= 1){
          if (ok[j - b[j - 1] - 1]){
            ok[j] = true;
          }
        }
      }
      if (j < n && ok[j]){
        if (j + b[j] + 1 <= n){
          ok[j + b[j] + 1] = true;
        }
      }
    }
    if (ok[n]){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}