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
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    v[i]--;
  }

  for (int i = 0; i < n; i++) {
    if (v[v[v[i]]] == i) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;  

#ifdef SERT
  t = 2;
#endif

  for (int i = 0; i < t; i++)
    solve();
}