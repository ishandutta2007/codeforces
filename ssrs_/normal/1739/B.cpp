#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> d(n);
    for (int j = 0; j < n; j++){
      cin >> d[j];
    }
    vector<int> a(n);
    a[0] = d[0];
    bool ok = true;
    for (int j = 1; j < n; j++){
      if (d[j] == 0){
        a[j] = a[j - 1];
      } else if (a[j - 1] - d[j] >= 0){
        ok = false;
        break;
      } else {
        a[j] = a[j - 1] + d[j];
      }
    }
    if (ok){
      for (int j = 0; j < n; j++){
        cout << a[j];
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }
}