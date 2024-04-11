#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  long long ans = (long long) n * (n + 1) / 2;
  for (int i = 0; i < n - 1; i++){
    if (a[i] != a[i + 1]){
      ans += (long long) (i + 1) * (n - 1 - i);
    }
  }
  for (int i = 0; i < m; i++){
    int p, x;
    cin >> p >> x;
    p--;
    if (p > 0){
      if (a[p - 1] != a[p]){
        ans -= (long long) p * (n - p);
      }
    }
    if (p < n - 1){
      if (a[p] != a[p + 1]){
        ans -= (long long) (p + 1) * (n - 1 - p);
      }
    }
    a[p] = x;
    if (p > 0){
      if (a[p - 1] != a[p]){
        ans += (long long) p * (n - p);
      }
    }
    if (p < n - 1){
      if (a[p] != a[p + 1]){
        ans += (long long) (p + 1) * (n - 1 - p);
      }
    }
    cout << ans << "\n";
  }
}