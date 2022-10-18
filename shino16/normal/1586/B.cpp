#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(x) begin(x), end(x)

int t, n, m, a[100000], b[100000], c[100000];
bool used[100000];

int main() {
  scanf("%d", &t);
  while (t--) {
    fill(all(used), false);
    scanf("%d%d", &n, &m);
    rep(i, m) scanf("%d%d%d", a+i, b+i, c+i), a[i]--, b[i]--, c[i]--, used[b[i]] = true;
    int s = -1;
    rep(i, n) if (!used[i]) { s = i; break; }
    assert(s != -1);
    rep(i, n) if (i != s) printf("%d %d\n", s+1, i+1);
  }
}