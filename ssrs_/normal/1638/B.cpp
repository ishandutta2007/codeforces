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
    int m0 = -1, m1 = -1;
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (a[j] % 2 == 0){
        if (m0 > a[j]){
          ok = false;
        }
        m0 = a[j];
      }
      if (a[j] % 2 == 1){
        if (m1 > a[j]){
          ok = false;
        }
        m1 = a[j];
      }
    }
    if (ok){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}