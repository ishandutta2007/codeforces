#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> h(n);
    for (int j = 0; j < n; j++){
      cin >> h[j];
    }
    vector<int> c(n - 2);
    for (int j = 0; j < n - 2; j++){
      c[j] = max(max(h[j], h[j + 2]) - h[j + 1] + 1, 0);
    }
    if ((n - 2) % 2 == 1){
      long long ans = 0;
      for (int j = 0; j < n - 2; j += 2){
        ans += c[j];
      }
      cout << ans << endl;
    } else {
      long long sum = 0;
      for (int j = 1; j < n - 2; j += 2){
        sum += c[j];
      }
      long long ans = sum;
      for (int j = 0; j < n - 2; j += 2){
        sum += c[j] - c[j + 1];
        ans = min(ans, sum);
      }
      cout << ans << endl;
    }
  }
}