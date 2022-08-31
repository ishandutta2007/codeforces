#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x, y;
    cin >> n >> x >> y;
    int D = y - x;
    int d = D;
    for (int j = 1; j * j <= D; j++){
      if (D % j == 0){
        if (j < n){
          d = min(d, D / j);
        }
        if (j * j < D && D / j < n){
          d = min(d, j);
        }
      }
    }
    vector<int> a(n);
    if (y <= d * (n - 1)){
      int r = (y - 1) % d + 1;
      for (int j = 0; j < n; j++){
        a[j] = r + d * j;
      }
    } else {
      a[n - 1] = y;
      for (int j = n - 2; j >= 0; j--){
        a[j] = a[j + 1] - d;
      }
    }
    for (int j = 0; j < n; j++){
      cout << a[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}