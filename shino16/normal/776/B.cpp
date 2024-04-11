#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, m, n) for (int i = (m); i < (n); i++)

bool is_p[100005];

int main() {
  fill(is_p + 2, end(is_p), true);
  for (int p = 2; p * p < size(is_p); p++)
    if (is_p[p])
      for (int m = p * p; m < size(is_p); m += p)
        is_p[m] = false;

  int n; scanf("%d", &n);
  printf("%d\n", n <= 2 ? 1 : 2);
  rep(i, n) printf("%d%c", 2 - is_p[i + 2], " \n"[i==n-1]);
}