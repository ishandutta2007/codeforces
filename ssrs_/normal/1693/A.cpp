#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<long long> b(n - 1);
    for (int j = 0; j < n - 1; j++){
      b[j] = a[j];
      a[j + 1] += b[j];
    }
    if (a[n - 1] != 0){
      cout << "No" << endl;
    } else {
      bool ok = true;
      for (int j = 0; j < n - 1; j++){
        if (b[j] < 0){
          ok = false;
        }
      }
      for (int j = 0; j < n - 2; j++){
        if (b[j] == 0 && b[j + 1] != 0){
          ok = false;
        }
      }
      if (ok){
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}