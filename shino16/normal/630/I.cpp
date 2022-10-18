#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, m, n) for (int i = (m); i < (n); i++)

int main() {
  int n; scanf("%d", &n);
  printf("%lld\n", (1LL << 2*(n-3)) * (n * 9 - 3));
}