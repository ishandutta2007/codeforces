#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> x(n + 1);
    x[0] = 0;
    for (int j = 1; j <= n; j++){
      cin >> x[j];
    }
    long long sum = 0;
    for (int j = 0; j < n; j++){
      sum += (long long) (x[j + 1] - x[j]) * (a + b);
    }
    long long ans = sum;
    long long sum2 = 0;
    for (int j = n - 1; j >= 0; j--){
      sum -= (long long) (x[j + 1] - x[j]) * (a + b);
      sum2 += x[j + 1];
      long long res = sum + (sum2 - (long long) x[j] * (n - j)) * b;
      ans = min(ans, res);
    }
    cout << ans << endl;
  }
}