#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    vector<long long> x(4), y(4);
    for (int j = 0; j < 4; j++){
      cin >> x[j] >> y[j];
    }
    long long ans = INF;
    vector<int> p = {0, 1, 2, 3};
    for (int j = 0; j < 24; j++){
      map<long long, long long> da, db;
      long long ay = min(y[p[0]], y[p[1]]);
      long long by = max(y[p[0]], y[p[1]]);
      long long cy = min(y[p[2]], y[p[3]]);
      long long dy = max(y[p[2]], y[p[3]]);
      long long sy = (by - ay) + (dy - cy);
      if (by < cy){
        long long d1 = cy - by;
        long long d2 = dy - ay;
        da[0] -= 2;
        db[0] += sy + 2 * d1;
        da[d1] += 2;
        db[d1] -= sy + 2 * d1;
        db[d1] += sy;
        db[d2] -= sy;
        da[d2] += 2;
        db[d2] += sy - 2 * d2;
      } else if (dy < ay){
        long long d1 = ay - dy;
        long long d2 = by - cy;
        da[0] -= 2;
        db[0] += sy + 2 * d1;
        da[d1] += 2;
        db[d1] -= sy + 2 * d1;
        db[d1] += sy;
        db[d2] -= sy;
        da[d2] += 2;
        db[d2] += sy - 2 * d2;
      } else if (ay <= cy && dy <= by){
        long long d = max(dy - ay, by - cy);
        db[0] += sy;
        db[d] -= sy;
        da[d] += 2;
        db[d] += sy - 2 * d;
      } else if (cy <= ay && by <= dy){
        long long d = max(dy - ay, by - cy);
        db[0] += sy;
        db[d] -= sy;
        da[d] += 2;
        db[d] += sy - 2 * d;
      } else if (by >= cy){
        long long d = dy - ay;
        db[0] += sy;
        db[d] -= sy;
        da[d] += 2;
        db[d] += sy - 2 * d;
      } else {
        long long d = by - cy;
        db[d] -= sy;
        da[d] += 2;
        db[d] += sy - 2 * d;
      }
      long long ax = min(x[p[1]], x[p[2]]);
      long long bx = max(x[p[1]], x[p[2]]);
      long long cx = min(x[p[3]], x[p[0]]);
      long long dx = max(x[p[3]], x[p[0]]);
      long long sx = (bx - ax) + (dx - cx);
      if (bx < cx){
        long long d1 = cx - bx;
        long long d2 = dx - ax;
        da[0] -= 2;
        db[0] += sx + 2 * d1;
        da[d1] += 2;
        db[d1] -= sx + 2 * d1;
        db[d1] += sx;
        db[d2] -= sx;
        da[d2] += 2;
        db[d2] += sx - 2 * d2;
      } else if (dx < ax){
        long long d1 = ax - dx;
        long long d2 = bx - cx;
        da[0] -= 2;
        db[0] += sx + 2 * d1;
        da[d1] += 2;
        db[d1] -= sx + 2 * d1;
        db[d1] += sx;
        db[d2] -= sx;
        da[d2] += 2;
        db[d2] += sx - 2 * d2;
      } else if (ax <= cx && dx <= bx){
        long long d = max(dx - ax, bx - cx);
        db[0] += sx;
        db[d] -= sx;
        da[d] += 2;
        db[d] += sx - 2 * d;
      } else if (cx <= ax && bx <= dx){
        long long d = max(dx - ax, bx - cx);
        db[0] += sx;
        db[d] -= sx;
        da[d] += 2;
        db[d] += sx - 2 * d;
      } else if (bx >= cx){
        long long d = dx - ax;
        db[0] += sx;
        db[d] -= sx;
        da[d] += 2;
        db[d] += sx - 2 * d;
      } else {
        long long d = bx - cx;
        db[d] -= sx;
        da[d] += 2;
        db[d] += sx - 2 * d;
      }
      next_permutation(p.begin(), p.end());
      set<int> st;
      for (auto P : da){
        st.insert(P.first);
      }
      for (auto P : db){
        st.insert(P.first);
      }
      long long A = 0, B = 0;
      long long sum = INF;
      for (long long x : st){
        A += da[x];
        B += db[x];
        sum = min(sum, A * x + B);
      }
      ans = min(ans, sum);
    }
    cout << ans << endl;
  }
}