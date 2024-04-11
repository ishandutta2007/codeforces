#include <bits/stdc++.h>
using namespace std;
long long f(int n){
  if (n < 0){
    return 0;
  } else {
    return (long long) (n + 1) * (n + 2) / 2;
  }
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
    }
    vector<int> q(n);
    for (int j = 0; j < n; j++){
      q[p[j]] = j;
    }
    long long ans = 0;
    int cl = 0, cr = 0;
    for (int j = 1; j < n; j++){
      int l1 = cr, r1 = n - q[0];
      int l2 = cl, r2 = q[0] + 1;
      if (q[j] > q[0]){
        r1 = min(r1, q[j] - q[0]);
        cr = max(cr, q[j] - q[0]);
      } else {
        r2 = min(r2, q[0] - q[j]);
        cl = max(cl, q[0] - q[j]);
      }
      if (l1 < r1 && l2 < r2){
        ans += f(j * 2 - 1 - l1 - l2);
        ans -= f(j * 2 - 1 - l1 - r2);
        ans -= f(j * 2 - 1 - r1 - l2);
        ans += f(j * 2 - 1 - r1 - r2);
      }
    }
    cout << ans + 1 << endl;
  }
}