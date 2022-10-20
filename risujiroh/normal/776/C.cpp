#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<long long> v{1};
  if (abs(k) > 1) {
    long long cur = k;
    while (abs(cur) < 1e16) {
      v.push_back(cur);
      cur *= k; 
    }
  } else if (k == -1) {
    v.push_back(-1);
  }
  long long res = 0, sum = 0;
  map<long long, int> mp;
  while (n--) {
    ++mp[sum];
    int a;
    cin >> a;
    sum += a;
    for (auto e : v) {
      if (mp.count(sum - e)) {
        res += mp[sum - e];
      }
    }
  }
  cout << res << '\n';
}