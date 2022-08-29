#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<long long> c(n);
    for (int j = 0; j < n; j++){
      cin >> c[j];
    }
    vector<long long> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<long long> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    long long ans = 0;
    long long sum = abs(a[1] - b[1]) * 2;
    for (int j = 1; j < n; j++){
      if (a[j] == b[j]){
        sum = c[j] + 1;
      } else {
        sum += c[j] + 1;
        sum -= abs(a[j] - b[j]);
        sum = max(sum, c[j] + 1 + abs(a[j] - b[j]));
      }
      ans = max(ans, sum);
    }
    cout << ans << endl;
  }
}