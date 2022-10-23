#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i] -= i + 1;
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    b[i] = min(i, -1 - a[i]);
    b[i] = max(b[i] + 1, 0);
  }
  vector<vector<int>> p(n + 1);
  for (int i = 0; i < n; i++){
    p[b[i]].push_back(i);
  }
  vector<int> mn1(n + 1), mn2(n + 1);
  mn1[n] = n;
  mn2[n] = n;
  for (int i = n; i >= 0; i--){
    for (int j : p[i]){
      if (j < mn1[i]){
        mn2[i] = mn1[i];
        mn1[i] = j;
      } else if (j < mn2[i]){
        mn2[i] = j;
      }
    }
    if (i > 0){
      mn1[i - 1] = mn1[i];
      mn2[i - 1] = mn2[i];
    }
  }
  mn1[0] = 0;
  mn2[0] = 0;
  vector<long long> S1(n + 2), S2(n + 2);
  S1[0] = 0;
  S2[0] = 0;
  for (int i = 0; i <= n; i++){
    S1[i + 1] = S1[i] + mn1[i];
    S2[i + 1] = S2[i] + mn2[i];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int p, x;
    cin >> p >> x;
    p--;
    x -= p + 1;
    int b2 = max(min(p, -1 - x) + 1, 0);
    long long ans = S1[n + 1];
    if (b[p] <= b2){
      int k = upper_bound(mn1.begin() + 1, mn1.end(), p) - mn1.begin();
      if (k <= b2){
        ans -= S1[b2 + 1] - S1[k];
        ans += (long long) (b2 + 1 - k) * p;
      }
    } else {
      int k = lower_bound(mn1.begin() + 1, mn1.end(), p) - mn1.begin();
      if (k <= b[p]){
        k = max(k, b2 + 1);
        ans -= S1[b[p] + 1] - S1[k];
        ans += S2[b[p] + 1] - S2[k];
      }
    }
    ans -= (long long) n * (n - 1) / 2;
    cout << ans << "\n";
  }
}