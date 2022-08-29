#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    long long S = 0;
    for (int j = 0; j < n; j += 2){
      S += a[j];
    }
    vector<long long> sum(n + 1, 0);
    for (int j = 0; j < n; j++){
      if (j % 2 == 0){
        sum[j + 1] = sum[j] - a[j];
      } else {
        sum[j + 1] = sum[j] + a[j];
      }
    }
    long long odd_min = INF;
    long long even_min = 0;
    long long mx = 0;
    for (int j = 1; j <= n; j++){
      if (j % 2 == 1){
        mx = max(mx, sum[j] - odd_min);
        odd_min = min(odd_min, sum[j]);
      } else {
        mx = max(mx, sum[j] - even_min);
        even_min = min(even_min, sum[j]);
      }
    }
    cout << S + mx << endl;
  }
}