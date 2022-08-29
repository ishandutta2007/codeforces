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
    if (a[0] == 1){
      cout << n + 1;
      for (int j = 1; j <= n; j++){
        cout << ' ' << j;
      }
      cout << endl;
    } else if (a[n - 1] == 0){
      for (int j = 1; j <= n + 1; j++){
        cout << j;
        if (j <= n){
          cout << ' ';
        }
      }
      cout << endl;
    } else {
      int p = -1;
      for (int j = 0; j < n - 1; j++){
        if (a[j] == 0 && a[j + 1] == 1){
          p = j;
        }
      }
      if (p == -1){
        cout << -1 << endl;
      } else {
        for (int j = 0; j <= p; j++){
          cout << j + 1 << ' ';
        }
        cout << n + 1;
        for (int j = p + 1; j < n; j++){
          cout << ' ' << j + 1;
        }
        cout << endl;
      }
    }
  }
}