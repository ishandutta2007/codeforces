#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int n, s;
int gr[61];

int main() {
  for (int i = 0, x = 0; i < 61; x++) {
    rep(_, x + 1) if (i < 61) gr[i++] = x;
  }
  scanf("%d", &n);
  int x = 0;
  rep(i, n) scanf("%d", &s), x ^= gr[s];
  printf("%s\n", x ? "NO" : "YES");
}