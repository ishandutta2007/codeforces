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
    if (n == 2){
      if (a[0] == a[1]){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      vector<int> L(n - 1, -1);
      L[0] = a[0];
      if (a[0] <= a[1]){
        for (int j = 1; j < n - 1; j++){
          L[j] = a[j] - L[j - 1];
          if (a[j + 1] < L[j]){
            break;
          }
        }
      }
      vector<int> R(n - 1, -1);
      R[n - 2] = a[n - 1];
      if (a[n - 1] <= a[n - 2]){
        for (int j = n - 3; j >= 0; j--){
          R[j] = a[j + 1] - R[j + 1];
          if (a[j] < R[j]){
            break;
          }
        }
      }
      bool ok = false;
      if (L[n - 2] == a[n - 1]){
        ok = true;
      }
      if (a[0] >= a[1] && R[1] != -1){
        if (a[0] - a[1] == R[1]){
          ok = true;
        }
      }
      if (a[n - 1] >= a[n - 2] && L[n - 3] != -1){
        if (a[n - 1] - a[n - 2] == L[n - 3]){
          ok = true;
        }
      }
      for (int j = 1; j < n - 2; j++){
        if (L[j - 1] != -1 && R[j + 1] != -1){
          int x = a[j + 1] - L[j - 1];
          int y = a[j] - R[j + 1];
          if (x == y && x >= 0){
            ok = true;
          }
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