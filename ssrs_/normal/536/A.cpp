#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int A, B, n;
  cin >> A >> B >> n;
  for (int i = 0; i < n; i++){
    int l, t, m;
    cin >> l >> t >> m;
    int tv = l - 1, fv = INF;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      long long mx = A + (long long) (mid - 1) * B;
      long long mn = A + (long long) (l - 1) * B;
      long long S = (mn + mx) * (mid - l + 1) / 2;
      if (S <= (long long) m * t && mx <= t){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    if (tv == l - 1){
      cout << -1 << "\n";
    } else {
      cout << tv << "\n";
    }
  }
}