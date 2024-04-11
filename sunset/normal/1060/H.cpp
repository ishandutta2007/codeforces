#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, md;
  scanf("%d %d", &n, &md);
  
  auto add = [&](int x, int y) {
    x += y;
    if (x >= md) {
      x -= md;
    }
    return x;
  };

  auto sub = [&](int x, int y) {
    x -= y;
    if (x < 0) {
      x += md;
    }
    return x;
  };

  auto mul = [&](int x, int y) {
    return (long long)x * y % md;
  };

  auto power = [&](int x, int y) {
    int result = 1;
    for (; y; y >>= 1, x = mul(x, x)) {
      if (y & 1) {
        result = mul(result, x);
      }
    }
    return result;
  };

  vector<vector<int>> binom(n + 1, vector<int> (n + 1));
  for (int i = 0; i <= n; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      binom[i][j] = add(binom[i - 1][j], binom[i - 1][j - 1]);
    }
  }
  vector<int> coef(n + 1);
  vector<vector<int>> a(n + 1, vector<int> (n + 2));
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      a[i][j] = mul(binom[n][i], power(j, n - i));
    }
    a[i][n + 1] = i == 2;
  }

  for (int i = 0; i <= n; ++i) {
    int p = i;
    while (!a[p][i]) {
      ++p;
    }
    if (p != i) {
      for (int j = i; j <= n + 1; ++j) {
        swap(a[i][j], a[p][j]);
      }
    }
    int inv = power(a[i][i], md - 2);
    for (int j = 0; j <= n; ++j) {
      if (j != i) {
        int coef = mul(a[j][i], inv);
        for (int k = i; k <= n + 1; ++k) {
          a[j][k] = sub(a[j][k], mul(a[i][k], coef));
        }
      }
    }
  }
  for (int i = 0; i <= n; ++i) {
    coef[i] = mul(a[i][n + 1], power(a[i][i], md - 2));
  }

  int x = 1, y = 2;
  for (int i = 2; i <= n; ++i) {
    printf("+ %d %d %d\n", 3, i + 1, i + 2);
  }
  int total = n + 2;
  
  auto make_add = [&](int x, int y) {
    printf("+ %d %d %d\n", x, y, ++total);
    return total;
  };

  auto make_mul = [&](int x, int y) {
    int result = 0;
    while (y) {
      if (y & 1) {
        if (result) {
          result = make_add(result, x);
        } else {
          result = x;
        }
      }
      x = make_add(x, x);
      y >>= 1;
    }
    return result;
  };

  auto make_power = [&](int x) {
    printf("^ %d %d\n", x, ++total);
    return total;
  };
  
  auto make_square = [&](int z) {
    int result = 0;
    for (int i = 0; i <= n; ++i) {
      if (!coef[i]) {
        continue;
      }
      int value;
      if (i) {
        value = make_power(make_add(z, i + 2));
      } else {
        value = make_power(z);
      }
      value = make_mul(value, coef[i]);
      if (result) {
        result = make_add(result, value);
      } else {
        result = value;
      }
    }
    return result;
  };

  int z = make_add(x, y);
  int px = make_mul(make_square(x), md - 1);
  int py = make_mul(make_square(y), md - 1);
  int pz = make_square(z);
  pz = make_add(pz, px);
  pz = make_add(pz, py);
  pz = make_mul(pz, md + 1 >> 1);
  printf("f %d\n", pz);
  return 0;
}