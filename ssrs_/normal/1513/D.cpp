#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> R(n + 1);
    for (int j = 0; j <= n; j++){
      R[j] = j;
    }
    for (int j = 1; j <= n; j++){
      R[j] = max(R[j], R[j - 1]);
      if (R[j] == j){
        while (R[j] < n){
          if (a[R[j]] % a[j - 1] == 0){
            R[j]++;
          } else {
            break;
          }
        }
      }
    }
    vector<int> L(n + 1);
    for (int j = 0; j <= n; j++){
      L[j] = j;
    }
    for (int j = n - 1; j >= 0; j--){
      L[j] = min(L[j], L[j + 1]);
      if (L[j] == j){
        while (L[j] >= 1){
          if (a[L[j] - 1] % a[j] == 0){
            L[j]--;
          } else {
            break;
          }
        }
      }
    }
    vector<int> c(n - 1, p);
    for (int j = 0; j < n; j++){
      for (int k = R[j]; k < R[j + 1] - 1; k++){
        c[k] = min(c[k], a[j]);
      }
    }
    for (int j = n - 1; j >= 0; j--){
      for (int k = L[j + 1] - 2; k >= L[j]; k--){
        c[k] = min(c[k], a[j]);
      }
    }
    long long ans = 0;
    for (int j = 0; j < n - 1; j++){
      ans += c[j];
    }
    cout << ans << endl;
  }
}