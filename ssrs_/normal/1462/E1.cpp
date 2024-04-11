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
      a[j]--;
    }
    vector<long long> c(n, 0);
    for (int j = 0; j < n; j++){
      c[a[j]]++;
    }
    long long ans = 0;
    for (int j = 0; j < n; j++){
      if (c[j] >= 3){
        ans += c[j] * (c[j] - 1) * (c[j] - 2) / 6;
      }
    }
    for (int j = 0; j < n - 1; j++){
      if (c[j] >= 2 && c[j + 1] >= 1){
        ans += c[j] * (c[j] - 1) * c[j + 1] / 2;
      }
      if (c[j] >= 1 && c[j + 1] >= 2){
        ans += c[j] * c[j + 1] * (c[j + 1] - 1) / 2;
      }
    }
    for (int j = 0; j < n - 2; j++){
      if (c[j] >= 2 && c[j + 2] >= 1){
        ans += c[j] * (c[j] - 1) * c[j + 2] / 2;
      }
      if (c[j] >= 1 && c[j + 2] >= 2){
        ans += c[j] * c[j + 2] * (c[j + 2] - 1) / 2;
      }
    }
    for (int j = 0; j < n - 2; j++){
      ans += c[j] * c[j + 1] * c[j + 2];
    }
    cout << ans << endl;
  }
}