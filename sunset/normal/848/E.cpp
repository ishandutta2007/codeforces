#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 262145;
const int M = 20;
const int G = 3;
const int mod = 998244353;

int fft_n, fft_l, fft_i[M], fft_w[M], fft_r[N];

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

void init(int n) {
  for (fft_n = 1, fft_l = 0; fft_n < n; fft_n <<= 1, ++fft_l);
  fft_w[0] = power(G, mod - 1 >> fft_l);
  for (int i = 1; i < fft_l; ++i) {
    fft_w[i] = mul(fft_w[i - 1], fft_w[i - 1]);
  }
  fft_i[0] = power(fft_w[0], mod - 2);
  for (int i = 1; i < fft_l; ++i) {
    fft_i[i] = mul(fft_i[i - 1], fft_i[i - 1]);
  }
  for (int i = 0; i < fft_n; ++i) {
    fft_r[i] = (fft_r[i >> 1] >> 1) | ((i & 1) << fft_l - 1);
  }
}

void dft(int *x, int *fft_w, bool div) {
  for (int i = 0; i < fft_n; ++i) {
    if (i < fft_r[i]) {
      swap(x[i], x[fft_r[i]]);
    }
  }
  for (int i = 1, l = fft_l - 1; i < fft_n; i <<= 1, --l) {
    for (int j = 0; j < fft_n; j += i << 1) {
      for (int k = 0, w = 1; k < i; ++k, w = mul(w, fft_w[l])) {
        int u = x[j + k], v = mul(x[j + k + i], w);
        x[j + k] = add(u, v);
        x[j + k + i] = sub(u, v);
      }
    }
  }
  if (div) {
    int inv = power(fft_n, mod - 2);
    for (int i = 0; i < fft_n; ++i) {
      x[i] = mul(x[i], inv);
    }
  }
}

int n, answer, f[N], g[N], h[N], dp[N], value[N], dft_f[N], dft_g[N], dft_h[N], dft_zero[N], dft_one[N], dft_two[N], result[N];

void solve(int l, int r) {
  if (r - l <= 128) {
    for (int i = l; i <= r; ++i) {
      f[i] = add(f[i], mul(dp[i], value[i]));
      g[i] = add(g[i], mul(dp[i], value[i + 1]));
      h[i] = add(h[i], mul(dp[i], value[i + 2]));
      for (int j = l; j <= i - 1; ++j) {
        f[i] = add(f[i], mul(f[j], mul(dp[i - j - 1], value[i - j - 1])));
        g[i] = add(g[i], mul(f[j], mul(dp[i - j - 1], value[i - j - 0])));
        h[i] = add(h[i], mul(g[j], mul(dp[i - j - 1], value[i - j - 0])));
      }
      for (int j = l; j <= i - 3; ++j) {
        f[i] = add(f[i], mul(g[j], mul(dp[i - j - 3], value[i - j - 2])));
        g[i] = add(g[i], mul(g[j], mul(dp[i - j - 3], value[i - j - 1])));
        h[i] = add(h[i], mul(h[j], mul(dp[i - j - 3], value[i - j - 1])));
      }
    }
    return;
  }
  int mid = l + r >> 1;
  solve(l, mid);
  init(mid + r - (l << 1));
  for (int i = 0; i < fft_n; ++i) {
    dft_f[i] = dft_g[i] = dft_h[i] = dft_zero[i] = dft_one[i] = dft_two[i] = 0;
  }
  for (int i = l; i <= mid; ++i) {
    dft_f[i - l] = f[i];
    dft_g[i - l] = g[i];
    dft_h[i - l] = h[i];
  }
  for (int i = 0; i < r - l; ++i) {
    dft_zero[i] = mul(dp[i], value[i]);
    dft_one[i] = mul(dp[i], value[i + 1]);
    dft_two[i] = mul(dp[i], value[i + 2]);
  }
  dft(dft_f, fft_w, false);
  dft(dft_g, fft_w, false);
  dft(dft_h, fft_w, false);
  dft(dft_zero, fft_w, false);
  dft(dft_one, fft_w, false);
  dft(dft_two, fft_w, false);
  for (int i = 0; i < fft_n; ++i) {
    result[i] = mul(dft_f[i], dft_zero[i]);
  }
  dft(result, fft_i, true);
  for (int i = mid + 1; i <= r; ++i) {
    f[i] = add(f[i], result[i - l - 1]);
  }
  for (int i = 0; i < fft_n; ++i) {
    result[i] = mul(dft_f[i], dft_one[i]);
  }
  dft(result, fft_i, true);
  for (int i = mid + 1; i <= r; ++i) {
    g[i] = add(g[i], result[i - l - 1]);
  }
  for (int i = 0; i < fft_n; ++i) {
    result[i] = mul(dft_g[i], dft_one[i]);
  }
  dft(result, fft_i, true);
  for (int i = mid + 1; i <= r; ++i) {
    h[i] = add(h[i], result[i - l - 1]);
  }
  for (int i = 0; i < fft_n; ++i) {
    result[i] = mul(dft_g[i], dft_one[i]);
  }
  dft(result, fft_i, true);
  for (int i = max(mid + 1, l + 3); i <= r; ++i) {
    f[i] = add(f[i], result[i - l - 3]);
  }
  for (int i = 0; i < fft_n; ++i) {
    result[i] = mul(dft_g[i], dft_two[i]);
  }
  dft(result, fft_i, true);
  for (int i = max(mid + 1, l + 3); i <= r; ++i) {
    g[i] = add(g[i], result[i - l - 3]);
  }
  for (int i = 0; i < fft_n; ++i) {
    result[i] = mul(dft_h[i], dft_two[i]);
  }
  dft(result, fft_i, true);
  for (int i = max(mid + 1, l + 3); i <= r; ++i) {
    h[i] = add(h[i], result[i - l - 3]);
  }
  solve(mid + 1, r);
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    value[i] = mul(i, i);
  }
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (i >= 2) {
      dp[i] = add(dp[i], dp[i - 2]);
    }
    if (i >= 4) {
      dp[i] = add(dp[i], dp[i - 4]);
    }
  }
  solve(0, n);
  answer = mul(mul(add(dp[n - 1], dp[n - 3]), value[n - 1]), n);
  for (int i = 2; i <= n - 2; ++i) {
    int coef = 0;
    coef = add(coef, mul(mul(dp[i - 1], f[n - i - 1]), value[i - 1]));
    coef = add(coef, mul(mul(dp[i - 2], g[n - i - 2]), value[i - 1]));
    coef = add(coef, mul(mul(dp[i - 2], g[n - i - 2]), value[i - 1]));
    if (i >= 3 && i <= n - 3) {
      coef = add(coef, mul(mul(dp[i - 3], h[n - i - 3]), value[i - 1]));
    }
    answer = add(answer, mul(coef, i));
  }
  printf("%d\n", answer);
  return 0;
}