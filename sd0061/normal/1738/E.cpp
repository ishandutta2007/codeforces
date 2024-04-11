#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;
const int Q = 998244353;

int n, a[N];
int64 s[N], t[N];

int I[N], P[N], inv[N];
void InitCombination(int n) {
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = 1LL * (Q - Q / i) * inv[Q % i] % Q;
  }
  P[0] = I[0] = 1;
  for (int i = 1; i <= n; ++i) {
    P[i] = 1LL * P[i - 1] * i % Q;
    I[i] = 1LL * I[i - 1] * inv[i] % Q;
  }
}
int Combination(int a, int b) {
  if (a < 0 || b < 0 || b > a) {
    return 0;
  }
  return 1LL * P[a] * I[b] % Q * I[a - b] % Q;
}
int power(int A, int B, int QQ = Q) {
  int res = 1;
  while (B) {
    if (B & 1) {
      res = 1LL * res * A % QQ;
    }
    A = 1LL * A * A % QQ;
    B >>= 1;
  }
  return res;
}
int cal(int a, int b) {
  --a;
  --b;
  return (1LL * Combination(a + b + 2, a + 2) * (a + 2) + (Q - b - 1)) % Q *
         power(b + 1, Q - 2) % Q;
}
int pre(int a, int b) {
  return Combination(a + b + 1 , b);
}

void work() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  std::set<int64> h;
  for (int i = 1; i <= n; ++i) {
    s[i] = s[i - 1] + a[i - 1];
    t[i] = t[i - 1] + a[n - i];
    h.insert(s[i]);
  }
  int sum = 1;
  for (auto &x : h) {
    int L = std::lower_bound(s + 1, s + n + 1, x) - s;
    int R = std::upper_bound(s + 1, s + n + 1, x) - s - 1;
    int l = std::lower_bound(t + 1, t + n + 1, x) - t;
    int r = std::upper_bound(t + 1, t + n + 1, x) - t - 1;
    if (L <= R && l <= r && L + l <= n) {
      // printf("%d %d %d %d\n", l , r , L, R);
      int tmp = sum;
      int delta = 1LL * sum * cal(r - l + 1, R - L + 1) % Q;
      // printf("%d\n", cal(r - l + 1, R - L + 1));
      sum += delta;
      sum %= Q;
      if (r + R > n) {
        int res = 0;
        for (int i = L; i <= R; ++i) {
          int A = std::max(l, n - i + 1), B = r;
          if (A <= B) {
            // for (int j = A ; j <= B ; ++ j) {
            //   res += Combination(i-L+ j - l, j - l);
            //   printf("%d %d : %d\n", i ,j, Combination(i-L+ j - l, j - l) );
            //   res %= Q;
            // }
            // printf("%d : %d %d\n", i , A, B);
            res += pre(i - L, B - l);
            res %= Q;
            res +=  -pre(i - L, A - 1 - l) + Q;
            res %= Q;
          }
          // 
        }
        sum += Q - 1LL * res * tmp % Q;
        sum %= Q;
      }

      // printf("%d : %d %d %d %d\n", x , L, R , l , r);
      // for (int i = L ; i <= R ; ++ i) {
      //   for (int j = l ; j <= r ; ++ j) {
      //     for (int a = 0 ; a < i ; ++ a) {
      //       for (int b = 0 ; b < j ; ++ b) {
      //         f[i][j] += f[a][b];
      //       }
      //     }
      //   }
      // }
    }
  }
    printf("%d\n", sum);

  // for (int i = 0; i <= n; ++i) {
  //   for (int j = 0; i + j <= n; ++j) {
  //     printf("%4d", f[i][j]);
  //   }
  //   puts("");
  // }
}

int main() {
  InitCombination(N - 1);
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}