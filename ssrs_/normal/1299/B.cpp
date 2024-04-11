#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
  if (n % 2 == 1){
    cout << "NO" << endl;
  } else {
    bool ok = true;
    for (int i = 1; i < n / 2; i++){
      if (x[i] + x[n / 2 + i] != x[0] + x[n / 2]){
        ok = false;
      }
      if (y[i] + y[n / 2 + i] != y[0] + y[n / 2]){
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