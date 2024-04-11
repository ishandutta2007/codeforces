#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(x) begin(x), end(x)

int n, p[100], a[100];

int ask() {
  printf("?");
  rep(i, n) printf(" %d", a[i]);
  printf("\n");
  fflush(stdout);
  int x; scanf("%d", &x);
  return x-1;
}

int main() {
  scanf("%d", &n);
  p[n-1] = 1;
  rep2(t, 2, n+1) {
    rep(i, n-1) a[i] = t;
    a[n-1] = 1;
    // exists an elt less than p[n-1]
    if (ask() != -1) p[n-1]++;
  }
  rep2(x, 1, n+1) if (x != p[n-1]) {
    a[n-1] = x - p[n-1];
    int d = a[n-1] < 1 ? 1-a[n-1] : 1;
    rep(i, n-1) a[i] = d;
    a[n-1] += d;
    p[ask()] = x;
  }
  printf("!");
  rep(i, n) printf(" %d", p[i]);
  printf("\n");
  return 0;
}