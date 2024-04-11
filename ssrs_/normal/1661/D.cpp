#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<long long> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  reverse(b.begin(), b.end());
  vector<long long> imos_a(n + 1, 0), imos_b(n + 1, 0);
  long long ans = 0;
  for (int i = 0; i <= n - k; i++){
    b[i] -= imos_a[i] * i + imos_b[i];
    if (b[i] > 0){
      long long cnt = (b[i] + k - 1) / k;
      ans += cnt;
      imos_a[i] -= cnt;
      imos_a[i + k] += cnt;
      imos_b[i] += cnt * (k + i);
      imos_b[i + k] -= cnt * (k + i);
    }
    imos_a[i + 1] += imos_a[i];
    imos_b[i + 1] += imos_b[i];
  }
  long long mx = 0;
  for (int i = n - k + 1; i < n; i++){
    b[i] -= imos_a[i] * i + imos_b[i];
    if (b[i] > 0){
      mx = max(mx, (b[i] + n - i - 1) / (n - i));
    }
    imos_a[i + 1] += imos_a[i];
    imos_b[i + 1] += imos_b[i];
  }
  cout << ans + mx << endl;
}