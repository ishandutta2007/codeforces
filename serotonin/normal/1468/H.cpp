#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int t, n, k, m;

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d %d", &n, &k, &m);
    k >>= 1;
    set <int> out;
    for (int i = 1; i <= n; ++i) out.emplace(i);
    for (int i = 0; i < m; ++i) {
      int x; scanf("%d", &x);
      out.erase(x);
    }
    if ((n - m) % (k + k)) {
      puts("NO");
      continue;
    }
    vector <int> vec(out.begin(), out.end());
    int lo = vec[k - 1], hi = vec[vec.size() - k];
    bool ok = 0;
    for (int i = lo + 1; i < hi; ++i) {
      if (!out.count(i)) {
        ok = 1;
        break;
      }
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}