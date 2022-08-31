#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    for (int j = 0; j < n; j++){
      cin >> x[j] >> y[j];
    }
    bool ok = false;
    for (int j = 0; j < n; j++){
      bool ok2 = true;
      for (int l = 0; l < n; l++){
        if (abs(x[l] - x[j]) + abs(y[l] - y[j]) > k){
          ok2 = false;
        }
      }
      if (ok2){
        ok = true;
      }
    }
    if (ok){
      cout << 1 << endl;
    } else {
      cout << -1 << endl;
    }
  }
}