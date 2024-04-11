#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    bool sorted = true;
    for (int j = 0; j < n - 1; j++){
      if (a[j] != j + 1){
        sorted = false;
      }
    }
    if (sorted){
      cout << 0 << endl;
    } else {
      vector<bool> ok(n + 2, true);
      for (int j = 0; j < n; j++){
        if (a[j] != j + 1){
          ok[j + 1] = false;
        }
      }
      int cnt = 0;
      for (int j = 0; j < n + 1; j++){
        if (ok[j] != ok[j + 1]){
          cnt++;
        }
      }
      if (cnt == 2){
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
}