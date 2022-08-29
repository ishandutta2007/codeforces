#include <bits/stdc++.h>
using namespace std;
int main(){
  cout << fixed << setprecision(10);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<int> r(m);
    vector<double> p(m);
    for (int j = 0; j < m; j++){
      cin >> r[j] >> p[j];
    }
    int mx = n;
    for (int j = 0; j < n; j++){
      if (a[j] != j){
        mx = j;
      }
    }
    if (mx == n){
      cout << 1 << endl;
    } else {
      double q = 1;
      for (int j = 0; j < m; j++){
        if (r[j] > mx){
          q *= 1 - p[j];
        }
      }
      cout << 1 - q << endl;
    }
  }
}