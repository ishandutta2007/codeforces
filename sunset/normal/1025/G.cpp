#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int sub(int x, int y) {
  x -= y;
  if (x < 0) {
    x += mod;
  }
  return x;
}

int mul(int x, int y) {
  return (long long)x * y % mod;
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

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (~x) {
      ++a[x - 1];
    }
  }
  int answer = power(2, n - 1) - 1;
  for (int i = 0; i < n; ++i) {
    answer = sub(answer, power(2, a[i]) - 1);
  }
  printf("%d\n", answer);
  return 0;
}