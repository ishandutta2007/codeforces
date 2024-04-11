#include <cstdio>

typedef long long ll;
const int mod = 1E9+7;

int main() {
  int n;
  scanf("%d", &n);
  // ans = 27^n - 7^n
  ll a = 1, b = 1;
  for(int i = 0; i < n; ++i) {
    a *= 27;
    b *= 7;
    a %= mod;
    b %= mod;
  }
  int ans = (a - b) % mod;
  if (ans < 0) ans += mod;
  printf("%d\n", ans);
}