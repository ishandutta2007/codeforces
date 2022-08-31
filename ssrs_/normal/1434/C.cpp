#include <bits/stdc++.h>
using namespace std;
long long f(long long x, long long a, long long b, long long c, long long d){
  //used ability x times. total damage?
  long long t = d * (x - 1);
  long long ans = x * a;
  if (c <= t){
    ans -= (b * c) * ((t - c + d - 1) / d);
    t = c / d * d;
    t++;
  }
  //0+bd+2bd+...+(t/d)bd
  ans -= (t / d) * (t / d + 1) / 2 * b * d;
  //cout << "x = " << x << ", ans = " << ans << endl;
  return ans;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b * c < a){
      cout << -1 << endl;
    } else if (d > c){
      cout << a << endl;
    } else if (a <= b * (d - 1)){
      cout << a << endl;
    } else {
      long long L = 0;
      long long R = 1500000;
      long long ans = 0;
      while (R - L > 2){
        long long mid1 = (L * 2 + R) / 3;
        long long mid2 = (L + R * 2) / 3;
        long long a1 = f(mid1, a, b, c, d);
        long long a2 = f(mid2, a, b, c, d);
        ans = max(ans, max(a1, a2));
        if (a1 < a2){
          L = mid1;
        } else {
          R = mid2;
        }
      }
      for (int j = L + 1; j < R; j++){
        ans = max(ans, f(j, a, b, c, d));
      }
      cout << ans << endl;
    }
  }
}