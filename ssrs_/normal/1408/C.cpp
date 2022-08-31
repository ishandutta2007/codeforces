#include <bits/stdc++.h>
using namespace std;
const double INF = 10000000000;
int main(){
  cout << fixed << setprecision(20);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, l;
    cin >> n >> l;
    vector<int> a(n + 2);
    a[0] = 0;
    for (int j = 1; j <= n; j++){
      cin >> a[j];
    }
    a[n + 1] = l;
    double tv = INF;
    double fv = 0;
    for (int j = 0; j < 100; j++){
      double mid = (tv + fv) / 2;
      double d1 = -1;
      double t1 = 0;
      for (int j = 0; j < n + 1; j++){
        double dt = (double) (a[j + 1] - a[j]) / (j + 1);
        if (t1 + dt > mid){
          d1 = a[j] + (mid - t1) * (j + 1);
          break;
        }
        t1 += dt;
      }
      if (d1 < 0){
        d1 = l;
      }
      double d2 = -1;
      double t2 = 0;
      for (int j = n + 1; j >= 1; j--){
        double dt = (double) (a[j] - a[j - 1]) / (n + 2 - j);
        if (t2 + dt > mid){
          d2 = a[j] - (mid - t2) * (n + 2 - j);
          break;
        }
        t2 += dt;
      }
      if (d2 < 0){
        d2 = 0;
      }
      if (d1 > d2){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}