#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k, l;
  cin >> n >> k >> l;
  int m = n * k;
  vector<int> a(m);
  for (int i = 0; i < m; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int cnt = upper_bound(a.begin(), a.end(), a[0] + l) - a.begin();
  if (cnt < n){
    cout << 0 << endl;
  } else {
    long long ans = 0;
    for (int i = 0; i < n; i++){
      int id = min(i * k, cnt - (n - i));
      ans += a[id];
    }
    cout << ans << endl;
  }
}