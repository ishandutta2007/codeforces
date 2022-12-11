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
  ll x;
  cin >> x;
  if (x % 10 < 6) cout << x / 10 * 10;
  else cout << (x / 10 + 1) * 10;
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;  

#ifdef SERT
  t = 4;
#endif

  for (int i = 0; i < t; i++)
    solve();
}