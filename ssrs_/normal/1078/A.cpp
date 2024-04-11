#include <bits/stdc++.h>
using namespace std;
int main(){
  cout << fixed << setprecision(20);
  long double a, b, c;
  cin >> a >> b >> c;
  long double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long double ans = abs(x2 - x1) + abs(y2 - y1);
  if (a != 0){
    ans = min(ans, abs(x1 - (- c - b * y1) / a) + abs(x2 - (- c - b * y2) / a) + abs(y2 - y1) * sqrt(pow(b / a, 2) + 1));
  }
  if (b != 0){
    ans = min(ans, abs(y1 - (- c - a * x1) / b) + abs(y2 - (- c - a * x2) / b) + abs(x2 - x1) * sqrt(pow(a / b, 2) + 1));
  }
  if (a != 0 && b != 0){
    ans = min(ans, abs(x1 - (- c - b * y1) / a) + abs(y2 - (- c - a * x2) / b) + sqrt(pow((- c - b * y1) / a - x2, 2) + pow((- c - a * x2) / b - y1, 2)));
    ans = min(ans, abs(y1 - (- c - a * x1) / b) + abs(x2 - (- c - b * y2) / a) + sqrt(pow((- c - a * x1) / b - y2, 2) + pow((- c - b * y2) / a - x1, 2)));
  }
  cout << ans << endl;
}