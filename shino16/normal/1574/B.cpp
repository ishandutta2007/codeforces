#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int t, as[3], m, n;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d", as, as + 1, as + 2, &m);
    sort(as, as + 3);
    auto [c, b, a] = as;
    n = a + b + c;
    int hi = a - 1 + b - 1 + c - 1;
    int lo = a - (b + c) - 1;
    printf("%s\n", lo <= m && m <= hi ? "Yes" : "No");
  }
}