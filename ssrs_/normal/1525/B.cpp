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
      a[j]--;
    }
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (a[j] != j){
        ok = false;
      }
    }
    if (ok){
      cout << 0 << endl;
    } else if (a[0] == 0 || a[n - 1] == n - 1){
      cout << 1 << endl;
    } else if (a[0] == n - 1 && a[n - 1] == 0){
      cout << 3 << endl;
    } else {
      cout << 2 << endl;
    }
  }
}