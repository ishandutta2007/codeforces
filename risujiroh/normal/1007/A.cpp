#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n; cin >> n;
  VI a(n); for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  
  int res = 0;
  int p = 0;
  for (int i = 0; i < n; i++) {
    while (p < n and a[p] <= a[i]) p++;
    if (p == n) break;
    p++, res++;
  }
  cout << res << '\n';
  return 0;
}