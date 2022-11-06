#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t; ll a[69];

int main() {
  cin >> t;
  while (t--) {
    for (int i = 0; i < 4; ++i) {
      scanf("%lld", a + i);
    }
    sort(a, a + 4);
    cout << a[0] * a[2] << '\n';
  }
  return 0;
}