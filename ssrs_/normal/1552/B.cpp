#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<int>> r(n, vector<int>(5));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < 5; k++){
        cin >> r[j][k];
      }
    }
    int t = 0;
    for (int j = 1; j < n; j++){
      int cnt = 0;
      for (int k = 0; k < 5; k++){
        if (r[j][k] < r[t][k]){
          cnt++;
        }
      }
      if (cnt >= 3){
        t = j;
      }
    }
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (j != t){
        int cnt = 0;
        for (int k = 0; k < 5; k++){
          if (r[t][k] < r[j][k]){
            cnt++;
          }
        }
        if (cnt < 3){
          ok = false;
        }
      }
    }
    if (ok){
      cout << t + 1 << endl;
    } else {
      cout << -1 << endl;
    }
  }
}