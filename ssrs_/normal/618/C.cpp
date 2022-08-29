#include <bits/stdc++.h>
using namespace std;
struct point{
  long long x, y;
  point(){
  }
  point(long long x, long long y): x(x), y(y){
  }
  point operator -(point P){
    return point(x - P.x, y - P.y);
  }
};
long long cross(point P, point Q){
  return P.x * Q.y - P.y * Q.x;
}
bool is_collinear(point A, point B, point C){
  return cross(B - A, C - A) == 0;
}
int main(){
  int n;
  cin >> n;
  vector<point> P(n);
  for (int i = 0; i < n; i++){
    cin >> P[i].x >> P[i].y;
  }
  vector<pair<double, int>> X(n);
  for (int i = 0; i < n; i++){
    X[i] = make_pair(P[i].x * cos(1) + P[i].y * sin(1), i);
  }
  sort(X.begin(), X.end());
  int a = X[0].second;
  int b = X[1].second;
  int c;
  for (int i = 2; i < n; i++){
    int p = X[i].second;
    if (!is_collinear(P[a], P[b], P[p])){
      c = p;
      break;
    }
  }
  cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
}