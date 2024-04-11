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
long long dot(point P, point Q){
  return P.x * Q.x + P.y * Q.y;
}
bool is_acute(point P, point Q, point R){
  return dot(P - Q, R - Q) > 0;
}
int main(){
  int n;
  cin >> n;
  vector<point> A(n);
  for (int i = 0; i < n; i++){
    cin >> A[i].x >> A[i].y;
  }
  vector<int> p = {0, 1};
  for (int i = 2; i < n; i++){
    if (is_acute(A[i], A[p[0]], A[p[1]])){
      p.insert(p.begin(), i);
    } else if (is_acute(A[p[i - 2]], A[p[i - 1]], A[i])){
      p.push_back(i);
    } else {
      for (int j = 0; j < i - 1; j++){
        bool ok = true;
        if (!is_acute(A[p[j]], A[i], A[p[j + 1]])){
          ok = false;
        }
        if (j > 0){
          if (!is_acute(A[p[j - 1]], A[p[j]], A[i])){
            ok = false;
          }
        }
        if (j < i - 1){
          if (!is_acute(A[i], A[p[j + 1]], A[p[j + 2]])){
            ok = false;
          }
        }
        if (ok){
          p.insert(p.begin() + j + 1, i);
          break;
        }
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << p[i] + 1;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}