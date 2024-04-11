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
    bool one = false;
    for (int j = 0; j < n; j++){
      if (a[j] == 1){
        one = true;
      }
    }
    if (!one){
      cout << "YES" << endl;
    } else {
      sort(a.begin(), a.end());
      bool ok = true;
      for (int j = 0; j < n - 1; j++){
        if (a[j + 1] - a[j] == 1){
          ok = false;
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