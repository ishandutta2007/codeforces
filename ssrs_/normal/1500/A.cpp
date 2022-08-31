#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  bool ok = false;
  int x, y, z, w;
  vector<int> X(5000001, -1), Y(5000001, -1);
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      if (X[a[i] + a[j]] != -1){
        int k = X[a[i] + a[j]];
        int l = Y[a[i] + a[j]];
        if (i != k && i != l && j != k && j != l){
          x = i;
          y = j;
          z = X[a[i] + a[j]];
          w = Y[a[i] + a[j]];
          ok = true;
          break;
        }
      } else {
        X[a[i] + a[j]] = i;
        Y[a[i] + a[j]] = j;
      }
    }
    if (ok){
      break;
    }
  }
  if (!ok){
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << ' ' << w + 1 << endl;
  }
}