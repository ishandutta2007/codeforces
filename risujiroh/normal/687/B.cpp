#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

vector<int> min_factor;
void prepare(int n) {
  min_factor.assign(n + 1, 0);
  for (int p = 2; p <= n; ++p) {
    if (min_factor[p]) continue;
    for (int i = p; i <= n; i += p)
      if (min_factor[i] == 0) min_factor[i] = p;
  }
}
map<int, int> factorize(int n) {
  map<int, int> res;
  while (int d = min_factor[n])
    ++res[d], n /= d;
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  prepare(1e6);
  int n, k;
  cin >> n >> k;
  auto mp = factorize(k);
  while (n--) {
    int c;
    cin >> c;
    auto nmp = factorize(c);
    for (auto it = begin(mp); it != end(mp); ) {
      if (nmp.count(it->first) and it->second <= nmp[it->first]) {
        it = mp.erase(it);
      } else {
        ++it;
      }
    }
  }
  if (empty(mp)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}