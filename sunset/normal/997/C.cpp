#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000005;
const int mod = 998244353;

int n, fac[N], ifac[N];

int add(int x, int y) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
  return x;
}

int sub(int x, int y) {
  x -= y;
  if (x < 0) {
    x += mod;
  }
  return x;
}

int mul(int x, int y) {
  return (ll)x * y % mod;
}

int power(int x, int y) {
  int result = 1;
  for (; y; y >>= 1, x = mul(x, x)) {
    if (y & 1) {
      result = mul(result, x);
    }
  }
  return result;
}

int binom(int x, int y) {
  return mul(fac[x], mul(ifac[y], ifac[x - y]));
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d", &n);
  fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fac[i] = mul(fac[i - 1], i);
    ifac[i] = mul(mod - mod / i, ifac[mod % i]);
  }
  for (int i = 2; i <= n; ++i) {
    ifac[i] = mul(ifac[i], ifac[i - 1]);
  }
  int answer = power(power(3, n), n);
  answer = sub(answer, power(sub(power(3, n), 3), n));
  for (int i = 1; i <= n; ++i) {
    int coef = 0;
    coef = add(coef, mul(3, power(sub(power(3, n - i), 1), n)));
    coef = add(coef, mul(sub(power(3, i), 3), power(power(3, n - i), n)));
    coef = mul(coef, binom(n, i));
    if (i & 1) {
      answer = add(answer, coef);
    } else {
      answer = sub(answer, coef);
    }
  }
  printf("%d\n", answer);
  return 0;
}