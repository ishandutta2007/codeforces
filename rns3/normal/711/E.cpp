#include <bits/stdc++.h>
using namespace std;

const int mod = 1e6 + 3;

int pw(int x, long long y) {
  if(!y) return 1;
  int z = pw(x, y / 2);
  z = 1ll * z * z % mod;
  if(y & 1) return 1ll * z * x % mod;
  return z;
}

int main() {
  ///freopen("4.in", "r", stdin);
  long long n, k;
  scanf("%I64d %I64d", &n, &k);
  if(n <= 62) {
    long long x = (1ll << n);
    if(k > x) {
      puts("1 1");
      return 0;
    }
  }
  long long x = 0;
  long long kk = k;
  while(k % 2 == 0) {k /= 2; x ++;}
  x = n - x;
  k = kk;
  while(k) {
    k /= 2;
    x += k;
  }
  int a = pw(2, n);
  int b = pw(a, kk);
  int cur = 1;
  for(int i = 1; i <= kk; i ++) {
    cur = 1ll * cur * (a - i + 1) % mod;
    if(!cur) break;
  }
  int A = b - cur;
  if(A < 0) A += mod;
  int B = b;
  A = 1ll * A * pw((mod + 1) / 2, x) % mod;
  B = 1ll * B * pw((mod + 1) / 2, x) % mod;
  printf("%d %d\n", A, B);
}