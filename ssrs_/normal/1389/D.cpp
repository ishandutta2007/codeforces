#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    long long k;
    cin >> n >> k;
    int l1, r1;
    cin >> l1 >> r1;
    int l2, r2;
    cin >> l2 >> r2;
    bool ok = false;
    if (l2 <= l1 && l1 <= r2){
      ok = true;
    }
    if (l2 <= r1 && r1 <= r2){
      ok = true;
    }
    if (l1 <= l2 && l2 <= r1){
      ok = true;
    }
    if (l1 <= r2 && r2 <= r1){
      ok = true;
    }
    if (ok){
      long long M = max(r1, r2) - min(l1, l2);
      long long C = min(r1, r2) - max(l1, l2);
      if (k <= C * n){
        cout << 0 << endl;
      } else if (k <= M * n){
        cout << k - C * n << endl;
      } else {
        cout << (M - C) * n + (k - M * n) * 2 << endl;
      }
    } else {
      long long d;
      if (r1 <= l2){
        d = l2 - r1;
      } else {
        d = l1 - r2;
      }
      long long ans = INF;
      for (int j = 1; j <= n; j++){
        long long tmp = d * j;
        long long M = max(r1, r2) - min(l1, l2);
        if (k <= M * j){
          tmp += k;
        } else {
          tmp += M * j + (k - M * j) * 2;
        }
        ans = min(ans, tmp);
      }
      cout << ans << endl;
    }
  }
}