#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int j = 0; j < n; j++){
      cin >> a[j] >> b[j];
    }
    vector<int> r(n, m);
    vector<int> x(n, 0), y(n, 0);
    for (int j = 0; j < n; j++){
      if (b[j] < r[j]){
        x[j] = r[j] - b[j];
        r[j] -= x[j];
        a[j] -= x[j];
      }
      if (a[j] < r[j]){
        y[j] = r[j] - a[j];
        r[j] -= y[j];
        b[j] -= y[j];
      }
    }
    long long sa = 0, sb = 0, sr = 0;
    for (int j = 0; j < n; j++){
      sa += a[j];
      sb += b[j];
      sr += r[j];
    }
    for (int j = 0; j < n; j++){
      if (sa - sb > r[j]){
        x[j] += r[j];
        sa -= r[j];
      } else if (sb - sa > r[j]){
        y[j] += r[j];
        sb -= r[j];
      } else {
        if (sa - sb > 0){
          x[j] += sa - sb;
          r[j] -= sa - sb;
          sa -= sa - sb;
        }
        if (sb - sa > 0){
          y[j] += sb - sa;
          r[j] -= sb - sa;
          sb -= sb - sa;
        }
        x[j] += r[j] / 2;
        sa -= r[j] / 2;
        y[j] += r[j] - r[j] / 2;
        sb -= r[j] - r[j] / 2;
      }
    }
    cout << abs(sa - sb) << "\n";
    for (int j = 0; j < n; j++){
      cout << x[j] << ' ' << y[j] << "\n";
    }
  }
}