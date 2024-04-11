#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double INF = 1000000000;
struct point{
  double x, y;
  point(){
  }
  point(double x, double y): x(x), y(y){
  }
  point operator -(point P){
    return point(x - P.x, y - P.y);
  }
};
double abs(point P){
  return hypot(P.x, P.y);
}
double dist(point P, point Q){
  return abs(Q - P);
}
double dot(point P, point Q){
  return P.x * Q.x + P.y * Q.y;
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
double point_line_distance(point P, line L){
  return abs(cross(P - L.A, vec(L))) / abs(vec(L));
}
double point_segment_distance(point P, line L){
  if (dot(P - L.A, vec(L)) < 0){
    return dist(P, L.A);
  } else if (dot(P - L.B, vec(L)) > 0){
    return dist(P, L.B);
  } else {
    return point_line_distance(P, L);
  }
}
int main(){
  cout << fixed << setprecision(20);
  int n;
  point P;
  cin >> n >> P.x >> P.y;
  vector<point> Q(n + 1);
  for (int i = 0; i < n; i++){
    cin >> Q[i].x >> Q[i].y;
  }
  Q[n] = Q[0];
  double mx = 0;
  for (int i = 0; i < n; i++){
    mx = max(mx, dist(P, Q[i]));
  }
  double mn = INF;
  for (int i = 0; i < n; i++){
    mn = min(mn, point_segment_distance(P, line(Q[i], Q[i + 1])));
  }
  cout << PI * (mx * mx - mn * mn) << endl;
}