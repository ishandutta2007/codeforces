#include <bits/stdc++.h>
using namespace std;
const int INF = 400000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> x(n);
    for (int j = 0; j < n; j++){
      cin >> x[j];
      x[j] *= 2;
    }
    vector<int> t(n);
    for (int j = 0; j < n; j++){
      cin >> t[j];
      t[j] *= 2;
    }
    int tv = 400000001, fv = -1;
    int ans;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      int L = -INF, R = INF;
      for (int j = 0; j < n; j++){
        if (mid < t[j]){
          L = INF;
          R = -INF;
        } else {
          L = max(L, x[j] - (mid - t[j]));
          R = min(R, x[j] + (mid - t[j]));
        }
      }
      if (L <= R){
        tv = mid;
        ans = L;
      } else {
        fv = mid;
      }
    }
    if (ans % 2 == 0){
      cout << ans / 2 << endl;
    } else {
      cout << ans / 2 << ".5" << endl;
    }
  }
}