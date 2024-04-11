#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n, p, w, d;
  cin >> n >> p >> w >> d;
  for (long long y = 0; y <= 1000000; y++){
    if ((p - y * d) % w == 0){
      long long x = (p - y * d) / w;
      if (0 <= x && x + y <= n){
        long long z = n - x - y;
        cout << x << ' ' << y << ' ' << z << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}