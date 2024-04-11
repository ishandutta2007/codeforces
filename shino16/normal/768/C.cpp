#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

map<vector<int>, int> rec;

int main() {
  int n, k, x; scanf("%d%d%d", &n, &k, &x);
  vector<int> a(n);
  rep(i, n) scanf("%d", &a[i]);
  sort(a.begin(), a.end());
  rep(i, k) {
    if (auto itr = rec.find(a); itr != rec.end()) {
      int rest = k - i - 1;
      rest %= i - itr->second;
      k = i + rest + 1;
    }
    rec[a] = i;
    rep(i, (n + 1) / 2) a[i * 2] ^= x;
    sort(a.begin(), a.end());
  }
  pair key(*min_element(a.begin(), a.end()), *max_element(a.begin(), a.end()));
  printf("%d %d\n", key.second, key.first);
}