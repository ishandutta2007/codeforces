#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, z;
  cin >> n >> z;
  vector<int> x(n);
  for (int i = 0; i < n; i++){
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  int tv = 0, fv = n / 2 + 1;
  while (fv - tv > 1){
    int mid = (tv + fv) / 2;
    bool ok = true;
    for (int i = 0; i < mid; i++){
      if (x[n - mid + i] - x[i] < z){
        ok = false;
      }
    }
    if (ok){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv << endl;
}