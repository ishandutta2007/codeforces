#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (int j = 0; j < k; j++){
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    bool ok = false;
    for (int j = 0; j < 2; j++){
      vector<int> b(k, 0);
      for (int l = 0; l < k; l++){
        if (a[l] >= n * 2){
          b[l] = a[l] / n;
        }
      }
      long long mn = 0, mx = 0;
      for (int l = k - 1; l >= 0; l--){
        if (b[l] >= 2){
          mn += 2;
          mx += b[l];
          if (mn <= m && m <= mx){
            ok = true;
          }
        }
      }
      swap(n, m);
    }
    if (ok){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}