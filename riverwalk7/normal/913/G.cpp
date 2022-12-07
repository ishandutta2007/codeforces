#include <bits/stdc++.h>

using namespace std;

inline long long mul(long long a, long long b, long long md) {
  long long res = 0;
  while (b > 0) {
    if (b & 1) {
      res += a; if (res >= md) res -= md;
    }
    a += a; if (a >= md) a -= md;
    b >>= 1;
  }
  return res;
}
long long xx[5000];

inline long long power(long long a, long long b, long long md) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a, md);
    }
    a = mul(a, a, md);
    b >>= 1;
  }
  return res;
}

int main() {
  int tt;
  cin >> tt;
  for(int i=0; i<5000; i++)
  {
      for(int j=0; j<5000; j++)
      {
          xx[i] += j;
      }
  }
  while (tt--) {
    long long a;
    cin >> a;
    int n = (int) to_string(a).length();
    for (int m = 0; ; m++) {
      long long b = (-a) & ((1LL << (n + m)) - 1);
      if ((a + b) % 5 == 0) {
        b += (1LL << (n + m));
      }
      if ((b == 0 && m == 0) || (int) to_string(b).length() <= m) {
        long long c = (a + b) >> (n + m);
        long long t = vector<long long>{-1, 0, 1, 3, 2}[c % 5];
        long long p5 = 5;
        for (int i = 1; i < n + m; i++) {
          while (power(2, t, p5 * 5) != c % (p5 * 5)) {
            t += p5 / 5 * 4;
          }
          p5 *= 5;
        }
        t += n + m;
        cout << t << endl;
        break;
      }
      a *= 10;
    }
  }
  return 0;
}