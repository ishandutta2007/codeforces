#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> pos(n), a(n);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pos[x - 1] = i;
    a[i] = x - 1;
  }

  vector<bool> isPrime(n + 2, true);
  vector<int> primes;
  for (int i = 2; i < n + 2; i++) {
    if (!isPrime[i]) continue;
    primes.push_back(i);
    for (int j = i * 2; j < n + 2; j += i)
      isPrime[j] = false;
  }
  vector<pair<int, int>> ans;

  auto isP = [&](int x) { return x >= 2 && isPrime[x]; };

  auto getPath = [&](int dist) {
    vector<int> ans;
    if (isPrime[dist + 1]) {
      ans = {dist + 1};
      return ans;
    }
    for (int i = 0; i < 1000; i++) {      
      if (isP(dist - primes[i] + 2)) return ans = {primes[i], dist - primes[i] + 2};
      if (!ans.empty()) return ans;
      if (isP(dist - primes[i] + 1)) return ans = {2, primes[i], dist - primes[i] + 1};
      if (!ans.empty()) return ans;
    }
    exit(11);
  };

  for (int i = 0; i < n; i++) {    
    int dist = pos[i] - i;
    if (dist == 0) continue;    

    vector<int> path = getPath(dist);
    int x = i + dist;
    for (int p : path) {      
      int y = x - p + 1;
      ans.emplace_back(y, x);
      swap(a[x], a[y]);
      pos[a[x]] = x;
      pos[a[y]] = y;
      x = y;
    }
  }

  cout << ans.size() << "\n";
  for (auto &[a, b] : ans) {
    cout << a + 1 << " " << b + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
#ifdef SERT
  t = 3;
#endif
  while (t--) solve();
}