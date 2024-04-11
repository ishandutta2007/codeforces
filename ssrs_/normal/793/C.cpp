#include <bits/stdc++.h>
using namespace std;
const double INF = 10000000;
const double EPS = 1e-12;
struct point{
  double x, y;
  point(){
  }
  point(double x, double y): x(x), y(y){
  };
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
double dot(point P, point Q){
  return P.x * Q.x + P.y * Q.y;
}
double cross(point P, point Q){
  return P.x * Q.y - P.y * Q.x;
}
struct line{
  point A, B;
  line(){
  }
  line(point A, point B): A(A), B(B){
  }
};
point vec(line L){
  return L.B - L.A;
}
bool is_parallel(line L1, line L2){
  return abs(cross(vec(L1), vec(L2))) <= EPS;
}
point line_intersection(line L1, line L2){
  return L1.A + vec(L1) * cross(L2.A - L1.A, vec(L2)) / cross(vec(L1), vec(L2));
}
bool on_segment(point P, line L){
  return dot(P - L.A, vec(L)) >= - EPS && dot(P - L.B, vec(L)) <= EPS;
}
int main(){
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  point A(x1, y1), B(x1, y2), C(x2, y2), D(x2, y1);
  vector<line> S(4);
  S[0] = line(A, B);
  S[1] = line(B, C);
  S[2] = line(C, D);
  S[3] = line(D, A);
  double mx = INF;
  double mn = 0;
  bool ok = true;
  for (int i = 0; i < n; i++){
    int rx, ry, vx, vy;
    cin >> rx >> ry >> vx >> vy;
    if ((rx == x1 || rx == x2) && vx == 0){
      ok = false;
      break;
    }
    if ((ry == y1 || ry == y2) && vy == 0){
      ok = false;
      break;
    }
    if (vx == 0 && vy == 0){
      if (rx <= x1 || x2 <= rx || ry <= y1 || y2 <= ry){
        ok = false;
        break;
      }
      continue;
    }
    point P(rx, ry);
    point Q(rx + vx, ry + vy);
    line L(P, Q);
    vector<double> T;
    for (int j = 0; j < 4; j++){
      if (!is_parallel(L, S[j])){
        point tmp = line_intersection(L, S[j]);
        if (on_segment(tmp, S[j])){
          if (dot(tmp - P, Q - P) > - EPS){
            double t = dist(P, tmp) / dist(P, Q);
            T.push_back(t);
          }
        }
      }
    }
    if (T.size() == 0){
      ok = false;
      break;
    }
    if (T.size() == 1){
      if (T[0] < EPS){
        ok = false;
        break;
      }
      mx = min(mx, T[0]);
    }
    sort(T.begin(), T.end());
    for (int i = 0; i < (int) T.size() - 1; i++){
      if (T[i + 1] - T[i] < EPS){
        T.erase(T.begin() + i);
        i--;
      }
    }
    if (T.size() == 1){
      if (!(x1 < rx && rx < x2 && y1 < ry && ry < y2)){
        ok = false;
        break;
      }
      mx = min(mx, T[0]);
    }
    if (T.size() == 2){
      mn = max(mn, T[0]);
      mx = min(mx, T[1]);
    }
    assert(T.size() <= 2);
  }
  if (ok && mx - mn >= EPS){
    cout << mn << endl;
  } else {
    cout << -1 << endl;
  }
}