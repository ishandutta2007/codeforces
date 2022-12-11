#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;

ll pow2(ll step) {
  if (step == 0) return 1;
  if (step % 2) return pow2(step - 1) * 2 % MD;
  ll q = pow2(step / 2);
  return q * q % MD;
}

void solve() {
  int n;
  cin >> n;
  int a = -1, b;
  for (int i = 1; i < n - i; i++) {
    if (__gcd(i, n - i) == 1) {
      a = i;
      b = n - i;
    }
  }
  cout << a << " " << b << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;  

#ifdef SERT
  t = 3;
#endif

  for (int i = 0; i < t; i++)
    solve();
}