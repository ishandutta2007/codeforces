#include <bits/stdc++.h>
using namespace std;
const double EPS = 0.000000001;
double dfs(double c, double m, double p, double v, double curr, int cnt){
  double ans = 0;
  ans += curr * p * cnt;
  for (int i = 0; i < 2; i++){
    if (c > EPS){
      double x = min(c, v);
      double c2 = c - x;
      double m2, p2;
      if (m > EPS){
        m2 = m + x / 2;
        p2 = p + x / 2;
      } else {
        m2 = 0;
        p2 = p + x;
      }
      ans += dfs(c2, m2, p2, v, curr * c, cnt + 1);
    }
    swap(c, m);
  }
  return ans;
}
int main(){
  cout << fixed << setprecision(20);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    double c, m, p, v;
    cin >> c >> m >> p >> v;
    cout << dfs(c, m, p, v, 1, 1) << endl;
  }
}