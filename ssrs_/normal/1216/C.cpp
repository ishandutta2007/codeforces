#include <bits/stdc++.h>
using namespace std;
int main(){
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long x3, y3, x4, y4;
  cin >> x3 >> y3 >> x4 >> y4;
  long long x5, y5, x6, y6;
  cin >> x5 >> y5 >> x6 >> y6;
  x3 = clamp(x3, x1, x2);
  y3 = clamp(y3, y1, y2);
  x4 = clamp(x4, x1, x2);
  y4 = clamp(y4, y1, y2);
  x5 = clamp(x5, x1, x2);
  y5 = clamp(y5, y1, y2);
  x6 = clamp(x6, x1, x2);
  y6 = clamp(y6, y1, y2);
  long long S = 0;
  S += (x4 - x3) * (y4 - y3);
  S += (x6 - x5) * (y6 - y5);
  long long l = max(x3, x5);
  long long r = min(x4, x6);
  long long d = max(y3, y5);
  long long u = min(y4, y6);
  if (l <= r && d <= u){
    S -= (r - l) * (u - d);
  }
  if (S == (x2 - x1) * (y2 - y1)){
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}