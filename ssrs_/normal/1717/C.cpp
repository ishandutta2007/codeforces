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
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    bool ok = true;
    for (int j = 0; j < n; j++){
      int k = (j + 1) % n;
      if (a[j] > b[j]){
        ok = false;
      }
      if (a[j] < b[j]){
        if (b[j] > b[k] + 1){
          ok = false;
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