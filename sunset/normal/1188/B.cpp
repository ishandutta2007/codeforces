#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, p, r;
  cin >> n >> p >> r;
  map<int, int> cnt;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ans += cnt[((long long) a * a % p * a % p * a % p - (long long) r * a % p + p) % p]++;
  }
  cout << ans << "\n";
  return 0;
}