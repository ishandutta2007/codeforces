#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n / 2, 0), b(n / 2, 0);
    for (int j = 0; j < n / 2; j++){
      a[j] = j;
      b[j] = n - 1 - j;
    }
    bool ok = true;
    if (0 < k && k < n / 2){
      swap(b[0], b[k]);
    } else if (n / 2 <= k && k < n - 1){
      swap(b[0], a[n - 1 - k]);
    } else if (k == n - 1){
      if (n == 4){
        ok = false;
      } else {
        swap(a[1], b[0]);
        swap(b[2], b[3]);
      }
    }
    if (!ok){
      cout << -1 << "\n";
    } else {
      for (int j = 0; j < n / 2; j++){
        cout << a[j] << ' ' << b[j] << "\n";
      }
    }
  }
}