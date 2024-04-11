#include <bits/stdc++.h>
using uint64 = unsigned long long;

const int N = 100000;

const uint64 inv5 = 14757395258967641293ULL;
const uint64 inv55 = inv5 * inv5 * inv5 * inv5 * inv5;

struct Polynomial {
  uint64 a[5];  // w10 ^ {0 .. 4}

  Polynomial() {
    memset(a, 0, sizeof(a));
  }

  Polynomial(uint64 x) {
    memset(a, 0, sizeof(a));
    a[0] = x;
  }
  Polynomial(const std::vector<uint64>& v) {
    for (int i = 0; i < v.size(); ++i) {
      a[i] = v[i];
    }
  }

  void print() {
    for (int _i = 0 ; _i < 5; ++ _i) {
      printf("%d%c" , a[_i], " \n"[_i + 1 == 5]);
    }
  }

  Polynomial operator+(const Polynomial& rhs) {
    Polynomial res{};
    for (int i = 0; i < 5; ++i) {
      res.a[i] = a[i] + rhs.a[i];
    }
    return res;
  }
  Polynomial operator-(const Polynomial& rhs) {
    Polynomial res{};
    for (int i = 0; i < 5; ++i) {
      res.a[i] = a[i] - rhs.a[i];
    }
    return res;
  }
  Polynomial operator*(const Polynomial& rhs) {
    Polynomial res{};
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        uint64 w = a[i] * rhs.a[j];
        if (i + j >= 5) {
          res.a[i + j - 5] -= w;
        } else {
          res.a[i + j] += w;
        }
      }
    }
    res.a[0] -= res.a[4];
    res.a[1] += res.a[4];
    res.a[2] -= res.a[4];
    res.a[3] += res.a[4];
    res.a[4] -= res.a[4];
    return res;
  }
  Polynomial pow(int k) {
    Polynomial res = Polynomial(1), p = *this;
    while (k) {
      if (k & 1) {
        res = res * p;
      }
      p = p * p;
      k >>= 1;
    }
    return res;
  }
};
int p10[] = {1, 10, 100, 1000, 10000};

Polynomial w_pool[205];
Polynomial* w = w_pool + 102;
Polynomial fwtm[10][10], ifwtm[10][10];

void FWT(Polynomial *a, Polynomial m[10][10]) {
  for (int d = 0 ; d < 5 ; ++ d) {
    for (int i = 0 ; i < N ; ++ i) {
      if (i / p10[d] % 10 == 0) {
        static Polynomial t[10];
        memset(t, 0, sizeof(t));
        for (int j = 0 ; j < 10 ; ++ j) {
          for (int k = 0 ; k < 10 ; ++ k) {
            t[j] = t[j] + a[i + p10[d] * k] * m[k][j]; 
          }
        }
        for (int j = 0 ; j < 10 ; ++ j) {
          a[i + p10[d] * j] = t[j];
        }
      }
    }
  }
}

Polynomial a[N];
void work() {
  int n;
  scanf("%d" , &n);
  for (int i = 0 ; i < n ; ++ i) {
    int x;
    scanf("%d" , &x);
    ++ a[x].a[0];
  }
  FWT(a, fwtm);
  for (int i = 0 ; i < N ; ++ i) {
    a[i] = a[i].pow(n);
  }
  FWT(a, ifwtm);
  uint64 mod = 1ULL << 58;
  for (int i = 0 ; i < n; ++ i) {
    uint64 res = a[i].a[0] * inv55;
    printf("%llu\n", (res / 32) % mod);
  }
}

int main() {
  w[0] = Polynomial(1);
  w[1] = Polynomial({0, 1, 0, 0, 0});
  for (int i = 2 ; i < 100 ; ++ i) {
    w[i] = w[i - 1] * w[1];
  }
  w[-1] = Polynomial({1, ~0ULL, 1, ~0ULL});
  for (int i = -2 ; i > -100 ; -- i) {
    w[i] = w[i + 1] * w[-1];
  }
  for (int i = 0 ; i < 10 ; ++ i) {
    for (int j = 0 ; j < 10 ; ++ j) {
      fwtm[i][j] = w[i * j];
      ifwtm[i][j] = w[-i * j];
    }
  }
  int T = 1;
  // scanf("%d", &T);
  while (T--) {
    // static int ca = 0;
    // printf("Case #%d: ", ++ca);
    work();
  }
  return 0;
}