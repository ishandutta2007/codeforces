#include <bits/stdc++.h>
using namespace std;
const double INF = 1000000000;
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
double abs(point P){
  return sqrt(P.x * P.x + P.y * P.y);
}
double dist(point P, point Q){
  return abs(Q - P);
}
long long dot(point P, point Q){
  return P.x * Q.x + P.y * Q.y;
}
long long cross(point P, point Q){
  return P.x * Q.y - P.y * Q.x;
}
int main(){
  cout << fixed << setprecision(20);
  int N, K;
  cin >> N >> K;
  K--;
  vector<point> P(N);
  for (int i = 0; i < N; i++){
    cin >> P[i].x >> P[i].y;
  }
  if (N == 3){
    int a = (K + 1) % 3;
    int b = (K + 2) % 3;
    cout << min(dist(P[K], P[a]), dist(P[K], P[b])) + dist(P[a], P[b]) << endl;
  } else {
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    int p;
    int x;
    point D;
    while (true){
      int a = mt() % N;
      int b = mt() % N;
      int c = mt() % N;
      if (a != b && b != c && c != a){
        if (cross(P[b] - P[a], P[c] - P[a]) == 0){
          x = a;
          D = P[b] - P[a];
          for (int i = 0; i < N; i++){
            if (cross(P[i] - P[a], D) != 0){
              p = i;
            }
          }
          break;
        }
      }
    }
    vector<pair<long long, int>> L;
    for (int i = 0; i < N; i++){
      if (i != p){
        L.push_back(make_pair(dot(P[i] - P[x], D), i));
      }
    }
    sort(L.begin(), L.end());
    vector<point> Q(N - 1);
    for (int i = 0; i < N - 1; i++){
      Q[i] = P[L[i].second];
    }
    if (p == K){
      cout << min(dist(P[K], Q[0]), dist(P[K], Q[N - 2])) + dist(Q[0], Q[N - 2]) << endl;
    } else {
      int s;
      for (int i = 0; i < N - 1; i++){
        if (L[i].second == K){
          s = i;
        }
      }
      double ans = INF;
      ans = min(ans, dist(Q[s], Q[0]) + dist(Q[0], Q[N - 2]) + dist(Q[N - 2], P[p]));
      ans = min(ans, dist(Q[s], Q[N - 2]) + dist(Q[N - 2], Q[0]) + dist(Q[0], P[p]));
      for (int i = s; i < N - 2; i++){
        double d11 = dist(Q[s], Q[i]) + dist(Q[i], Q[0]) + dist(Q[0], P[p]);
        double d12 = dist(Q[s], Q[0]) + dist(Q[0], Q[i]) + dist(Q[i], P[p]);
        double d1 = min(d11, d12);
        double d2 = min(dist(P[p], Q[i + 1]), dist(P[p], Q[N - 2])) + dist(Q[i + 1], Q[N - 2]);
        ans = min(ans, d1 + d2);
      }
      for (int i = 1; i <= s; i++){
        double d11 = dist(Q[s], Q[i]) + dist(Q[i], Q[N - 2]) + dist(Q[N - 2], P[p]);
        double d12 = dist(Q[s], Q[N - 2]) + dist(Q[N - 2], Q[i]) + dist(Q[i], P[p]);
        double d1 = min(d11, d12);
        double d2 = min(dist(P[p], Q[i - 1]), dist(P[p], Q[0])) + dist(Q[i - 1], Q[0]);
        ans = min(ans, d1 + d2);
      }
      cout << ans << endl;
    }
  }
}