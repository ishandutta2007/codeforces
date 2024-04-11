//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
//freopen("a.in","r",stdin);
//freopen("a.out","w",stdout);
  long long sum, x;
  cin >> sum >> x;
  long long a = (sum - x) / 2;
  if (a < 0 || x + 2 * a != sum || (x & a) != 0) {
    cout << 0 << endl;
    return 0;
  }
  long long bits = 0;
  long long tmp = x;
  while (tmp > 0) {
    bits += tmp & 1;
    tmp >>= 1;
  }
  long long ans = 1LL << bits;
  if (a == 0) {
    ans -= 2;
  }
  cout << ans << endl;
  return 0;
}