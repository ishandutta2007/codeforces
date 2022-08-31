#include <bits/stdc++.h>
using namespace std;
int main(){
  long long d, k, a, b, t;
  cin >> d >> k >> a >> b >> t;
  if (d <= k){
    cout << d * a << endl;
  } else if (k * a + t - k * b > 0){
    cout << k * a + (d - k) * b << endl;
  } else {
    if (d % k == 0){
      cout << d * a + (d / k - 1) * t << endl;
    } else {
      long long ans1 = d * a + (d / k) * t;
      long long ans2 = (d / k * k) * a + (d % k) * b + (d / k - 1) * t;
      cout << min(ans1, ans2) << endl;
    }
  }
}