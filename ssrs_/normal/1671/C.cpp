#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    long long sum = 0;
    for (int j = 0; j < n; j++){
      sum += a[j];
    }
    long long ans = 0;
    long long C = -1;
    for (int j = n - 1; j >= 0; j--){
      if (sum <= x){
        long long C2 = (x - sum) / (j + 1);
        if (C < C2){
          ans += (C2 - C) * (j + 1);
          C = C2;
        }
      }
      sum -= a[j];
    }
    cout << ans << endl;
  }
}