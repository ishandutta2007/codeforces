#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1e5+2;
int phi[N], counts[N];
vector<int> divisors[N];

int main () {
  //ios_base::sync_with_stdio(0); cin.tie(0);

  iota(phi, phi+N, 0);
  for (int i = 1; i < N; i++) {
    divisors[i].push_back(i);
    for (int j = 2*i; j < N; j += i){
      divisors[j].push_back(i);
      phi[j] -= phi[i];
    }
  }

  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  int ans = 0;
  for (int d = 1; d <= n; d++) {
    vector<int> seen;
    for (int j = d-1; j < n; j += d) {
      for (int div: divisors[a[j]]) {
        if (!counts[div]++) seen.push_back(div);
      }
    }
    for (int div: seen) {
      int count = counts[div];
      ans += (1LL*count*count*phi[div]*phi[d]) % MOD;
      counts[div] = 0;
      ans %= MOD;
    }
  }
  cout << ans << '\n';
}