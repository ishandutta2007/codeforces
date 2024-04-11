#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool query(ll l, ll r) {
  printf("%lld %lld\n", l, r);
  fflush(stdout);
  string result;
  cin >> result;
  if (result == "Yes" && l == r) {
    exit(0);
  }
  return result == "Yes";
}

int main() {
  srand(time(0));
  ll n;
  int k;
  cin >> n >> k;
  ll l = 1, r = n;
  while (true) {
    ll length = r - l + 1;
    if (length >= (k + 1 << 2)) {
      ll mid = l + r >> 1;
      if (query(l, mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    } else {
      int p = rand() % length;
      query(l + p, l + p);
    }
    l = max(1ll, l - k);
    r = min(n, r + k);
  }
  return 0;
}