#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> r(m, 0);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    r[a[i] % m]++;
  }
  sort(a.begin(), a.end());
  bool flg = false;
  for (int i = 0; i < m; i++){
    if (r[i] > 1){
      flg = true;
    }
  }
  if (flg){
    cout << 0;
  } else {
    long long ans = 1;
    for (int i = 0; i < n; i++){
      for (int j = i + 1; j < n; j++){
        ans *= (a[j] - a[i]) % m;
        ans %= m;
      }
    }
    cout << ans;
  }
}