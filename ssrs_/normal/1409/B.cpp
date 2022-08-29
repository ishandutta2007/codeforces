#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    if ((a - x) + (b - y) <= n){
      cout << x * y << endl;
    } else {
      long long L = max((long long) 0, n - (b - y));
      long long R = min(n, a - x);
      while (R - L > 2){
        long long mid1 = (L * 2 + R) / 3;
        long long mid2 = (L + R * 2) / 3;
        long long p1 = (a - mid1) * (b - (n - mid1));
        long long p2 = (a - mid2) * (b - (n - mid2));
        if (p1 >= p2){
          L = mid1;
        } else {
          R = mid2;
        }
      }
      long long ans = INF;
      for (int i = L; i <= R; i++){
        ans = min(ans, (a - i) * (b - (n - i)));
      }
      cout << ans << endl;
    }
  }
}