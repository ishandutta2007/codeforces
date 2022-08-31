#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int cnt = 0;
    for (int j = 0; j < n; j++){
      while (a[j] % 2 == 0){
        a[j] /= 2;
        cnt++;
      }
    }
    sort(a.begin(), a.end());
    for (int j = 0; j < cnt; j++){
      a[n - 1] *= 2;
    }
    long long ans = 0;
    for (int j = 0; j < n; j++){
      ans += a[j];
    }
    cout << ans << "\n";
  }
}