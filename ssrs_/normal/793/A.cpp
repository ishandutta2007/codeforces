#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int mn = *min_element(a.begin(), a.end());
  bool ok = true;
  long long ans = 0;
  for (int i = 0; i < n; i++){
    int d = a[i] - mn;
    if (d % k != 0){
      ok = false;
    } else {
      ans += d / k;
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}