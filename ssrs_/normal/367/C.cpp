#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> q(m), w(m);
  for (int i = 0; i < m; i++){
    cin >> q[i] >> w[i];
  }
  sort(w.begin(), w.end(), greater<int>());
  int tv = 0, fv = m + 1;
  while (fv - tv > 1){
    long long mid = (tv + fv) / 2;
    long long cnt = mid * (mid - 1) / 2;
    if (mid % 2 == 0){
      cnt += mid / 2;
    } else {
      cnt++;
    }
    if (cnt <= n){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  long long ans = 0;
  for (int i = 0; i < tv; i++){
    ans += w[i];
  }
  cout << ans << endl;
}