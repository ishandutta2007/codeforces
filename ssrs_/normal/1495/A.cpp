#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(20);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> X, Y;
    for (int j = 0; j < n * 2; j++){
      int x, y;
      cin >> x >> y;
      if (x == 0){
        Y.push_back(abs(y));
      }
      if (y == 0){
        X.push_back(abs(x));
      }
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    double ans = 0;
    for (int j = 0; j < n; j++){
      ans += hypot(X[j], Y[j]);
    }
    cout << ans << endl;
  }
}