#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  map<int, ll> mp;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    mp[x - i] += x;
    ans = max(ans, mp[x - i]);
  }
  cout << ans << "\n";
}