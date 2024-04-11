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
    if (a[n - 2] > a[n - 1]){
      cout << -1 << "\n";
    } else if (a[n - 1] < 0){
      bool ok = true;
      for (int j = 0; j < n - 1; j++){
        if (a[j] > a[j + 1]){
          ok = false;
        }
      }
      if (ok){
        cout << 0 << "\n";
      } else {
        cout << -1 << "\n";
      }
    } else {
      cout << n - 2 << "\n";
      for (int j = 0; j < n - 2; j++){
        cout << j + 1 << ' ' << n - 1 << ' ' << n << "\n";
      }
    }
  }
}