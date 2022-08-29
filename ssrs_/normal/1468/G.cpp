#include <bits/stdc++.h>
using namespace std;
const double EPS = 0.000000001;
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
  point operator /(double k){
    return point(x / k, y / k);
  }
};
double abs(point P){
  return sqrt(P.x * P.x + P.y * P.y);
}
double dist(point P, point Q){
  return abs(Q - P);
}
double cross(point P, point Q){
  return P.x * Q.y - P.y * Q.x;
}
struct line{
  point A, B;
  line(point A, point B): A(A), B(B){
  }
};
point vec(line L){
  return L.B - L.A;
}
point line_intersection(line L1, line L2){
  return L1.A + vec(L1) * cross(L2.A - L1.A, vec(L2)) / cross(vec(L1), vec(L2));
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int n, H;
  cin >> n >> H;
  vector<point> P(n);
  for (int i = 0; i < n; i++){
    int X, Y;
    cin >> X >> Y;
    P[i] = point(X, Y);
  }
  point Q = P[n - 1] + point(0, H);
  point M = P[n - 1];
  double ans = 0;
  for (int i = n - 2; i >= 0; i--){
    if (abs(cross(Q - P[i], Q - P[i + 1])) < EPS){
      if (cross(Q - P[i], Q - M) > -EPS){
        ans += dist(P[i], P[i + 1]);
      }
    } else if (cross(Q - P[i], Q - M) > -EPS){
      line L1(Q, M);
      line L2(P[i], P[i + 1]);
      point R = line_intersection(L1, L2);
      ans += dist(P[i], R);
      M = P[i];
    }
  }
  cout << ans << "\n";
}