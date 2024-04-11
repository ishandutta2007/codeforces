#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200005;
const int mod = 1e9 + 7;

int n, parity, a[N], binary[N], f[N][2][2][2];

int add(int x, int y) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
  return x;
}

int mul(int x, int y) {
  return (ll)x * y % mod;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %d", &n, &parity);
  binary[0] = 1;
  for (int i = 1; i <= n; ++i) {
    binary[i] = add(binary[i - 1], binary[i - 1]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  f[0][0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int have_black = 0; have_black < 2; ++have_black) {
      for (int have_white = 0; have_white < 2; ++have_white) {
        for (int all = 0; all < 2; ++all) {
          if (a[i] != 0) {
            int coef_zero = have_white ? binary[i - 1] : 0, coef_one = have_white ? binary[i - 1] : binary[i];
            f[i + 1][have_black][have_white][all] = add(f[i + 1][have_black][have_white][all], mul(f[i][have_black][have_white][all], coef_zero));
            f[i + 1][1][have_white][!all] = add(f[i + 1][1][have_white][!all], mul(f[i][have_black][have_white][all], coef_one));
          }
          if (a[i] != 1) {
            int coef_zero = have_black ? binary[i - 1] : 0, coef_one = have_black ? binary[i - 1] : binary[i];
            f[i + 1][have_black][have_white][all] = add(f[i + 1][have_black][have_white][all], mul(f[i][have_black][have_white][all], coef_zero));
            f[i + 1][have_black][1][!all] = add(f[i + 1][have_black][1][!all], mul(f[i][have_black][have_white][all], coef_one));
          }
        }
      }
    }
  }
  int answer = 0;
  for (int have_black = 0; have_black < 2; ++have_black) {
    for (int have_white = 0; have_white < 2; ++have_white) {
      answer = add(answer, f[n][have_black][have_white][parity]);
    }
  }
  printf("%d\n", answer);
  return 0;
}