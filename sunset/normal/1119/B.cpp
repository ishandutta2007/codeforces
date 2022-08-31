#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, h;
  cin >> n >> h;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  auto check = [&](vector<int> a) {
    sort(a.begin(), a.end(), greater<int>());
    long long sum = 0;
    for (int i = 0; i < (int) a.size(); i += 2) {
      sum += a[i];
    }
    return sum <= h;
  };
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (check(vector<int>(a.begin(), a.begin() + mid))) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << "\n";
  return 0;
}