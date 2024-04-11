#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b(n - 1);
    for (int j = 0; j < n - 1; j++){
      cin >> b[j];
    }
    long long ans = c;
    long long day = 0, tur = 0;
    for (int j = 0; j < n; j++){
      ans = min(ans, day + (c - tur + a[j] - 1) / a[j]);
      if (j < n - 1){
        if (tur < b[j]){
          int add = (b[j] - tur + a[j] - 1) / a[j];
          day += add;
          tur += (long long) add * a[j];
        }
        day++;
        tur -= b[j];
      }
    }
    cout << ans << endl;
  }
}