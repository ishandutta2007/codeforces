#include <bits/stdc++.h>
using namespace std;
double INF = 1e18;
double dist(pair<double, double> A, pair<double, double> B){
  return sqrt(pow(B.first - A.first, 2) + pow(B.second - A.second, 2));
}
int main(){
  cout << fixed << setprecision(20);
  int ax, ay, bx, by, tx, ty;
  cin >> ax >> ay >> bx >> by >> tx >> ty;
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
  vector<double> d(n);
  for (int i = 0; i < n; i++){
    d[i] = dist(make_pair(tx, ty), make_pair(x[i], y[i])) * 2;
  }
  double sum = 0;
  for (int i = 0; i < n; i++){
    sum += d[i];
  }
  vector<pair<double, int>> A(n);
  for (int i = 0; i < n; i++){
    A[i] = make_pair(dist(make_pair(ax, ay), make_pair(x[i], y[i])) - d[i] / 2, i);
  }
  sort(A.begin(), A.end());
  vector<pair<double, int>> B(n);
  for (int i = 0; i < n; i++){
    B[i] = make_pair(dist(make_pair(bx, by), make_pair(x[i], y[i])) - d[i] / 2, i);
  }
  sort(B.begin(), B.end());
  if (A[0].second != B[0].second){
    double ans = INF;
    ans = min(ans, sum + A[0].first + B[0].first);
    ans = min(ans, sum + A[0].first);
    ans = min(ans, sum + B[0].first);
    cout << ans << endl;
  } else {
    if (n == 1){
      cout << min(dist(make_pair(ax, ay), make_pair(x[0], y[0])) + dist(make_pair(x[0], y[0]), make_pair(tx, ty)), dist(make_pair(bx, by), make_pair(x[0], y[0])) + dist(make_pair(x[0], y[0]), make_pair(tx, ty))) << endl;
    } else {
      double ans = INF;
      ans = min(ans, sum + A[0].first + B[1].first);
      ans = min(ans, sum + A[1].first + B[0].first);
      ans = min(ans, sum + A[0].first);
      ans = min(ans, sum + B[0].first);
      cout << ans << endl;
    }
  }
}