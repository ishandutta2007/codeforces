#include <bits/stdc++.h>
using namespace std;
const double eps = 0.00000001;
const double PI = acos(-1);
struct point{
  double x, y;
  point(){
  }
  point(double x, double y): x(x), y(y){
  }
};
double abs(point P){
  return sqrt(P.x * P.x + P.y * P.y);
}
double arg(point P){
  return atan2(P.y, -P.x);
}
int main(){
  cout << fixed << setprecision(20);
  int n, k;
  cin >> n >> k;
  vector<point> P(n);
  for (int i = 0; i < n; i++){
    cin >> P[i].x >> P[i].y;
  }
  double tv = 200000, fv = 0;
  for (int i = 0; i < 50; i++){
    double mid = (tv + fv) / 2;
    double r = mid;
    int C = 0;
    vector<double> L, R;
    int m = 0;
    for (int j = 0; j < n; j++){
      double d = abs(P[j]);
      if (d < eps){
        C++;
      } else if (d < r * 2){
        double t1 = arg(P[j]);
        double t2 = acos(d / (r * 2));
        double l = t1 - t2, r = t1 + t2;
        if (l < 0){
          l += PI * 2;
        }
        if (l > PI * 2){
          l -= PI * 2;
        }
        if (r < 0){
          r += PI * 2;
        }
        if (r > PI * 2){
          r -= PI * 2;
        }
        L.push_back(l);
        R.push_back(r);
        m++;
      }
    }
    vector<double> angle;
    for (int j = 0; j < m; j++){
      angle.push_back(L[j]);
      angle.push_back(R[j]);
    }
    sort(angle.begin(), angle.end());
    vector<int> imos(m * 2 + 1, 0);
    for (int j = 0; j < m; j++){
      int pl = lower_bound(angle.begin(), angle.end(), L[j]) - angle.begin();
      int pr = lower_bound(angle.begin(), angle.end(), R[j]) - angle.begin();
      if (pl < pr){
        imos[pl]++;
        imos[pr]--;
      } else {
        imos[pl]++;
        imos[m * 2]--;
        imos[0]++;
        imos[pr]--;
      }
    }
    for (int j = 0; j < m * 2; j++){
      imos[j + 1] += imos[j];
    }
    bool ok = false;
    if (C >= k){
      ok = true;
    }
    for (int j = 0; j < m * 2; j++){
      if (imos[j] + C >= k){
        ok = true;
      }
    }
    if (ok){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv << endl;
}