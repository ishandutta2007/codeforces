#include <bits/stdc++.h>
using namespace std;
struct point{
  double x, y;
  point(){
  }
  point(double x, double y): x(x), y(y){
  }
  point operator +(point P){
    return point(x + P.x, y + P.y);
  }
  point operator -(point P){
    return point(x - P.x, y - P.y);
  }
  point operator *(double k){
    return point(x * k, y * k);
  }
};
double abs(point P){
  return sqrt(pow(P.x, 2) + pow(P.y, 2));
}
double dist(point P, point Q){
  return abs(Q - P);
}
int main(){
  cout << fixed << setprecision(20);
  point A, B;
  cin >> A.x >> A.y >> B.x >> B.y;
  double vmax, t;
  cin >> vmax >> t;
  point v, w;
  cin >> v.x >> v.y >> w.x >> w.y;
  double tv = 100000000;
  double fv = 0;
  for (int i = 0; i < 100; i++){
    double mid = (tv + fv) / 2;
    bool ok;
    if (mid < t){
      point C = A + v * mid;
      if (dist(C, B) <= mid * vmax){
        ok = true;
      } else {
        ok = false;
      }
    } else {
      point C1 = A + v * t;
      point C2 = B - w * (mid - t);
      if (dist(C1, C2) <= mid * vmax){
        ok = true;
      } else {
        ok = false;
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