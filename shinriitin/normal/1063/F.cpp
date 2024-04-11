#include <bits/stdc++.h>

const int max_N = (int) 5e5 + 21;
const int log_N = 22;

namespace SuffixArray {
int sa[max_N], rk[max_N], ht[max_N], st[log_N][max_N], bit[max_N];

int tmp[max_N], cnt[max_N], bc[max_N];

void build(const char *s, int n) {
  int i, j, k, T, sigma;

  for (i = 1; i <= n; ++i) sa[i] = i;
  std::sort(sa + 1, sa + 1 + n, [&](int a, int b) { return s[a] < s[b]; });
  for (i = 2, bc[sa[1]] = 1; i <= n; ++i) {
    bc[sa[i]] = bc[sa[i - 1]] + (s[sa[i - 1]] < s[sa[i]]);
  }

  for (T = 1; (sigma = bc[sa[n]]) < n; T <<= 1) {
    auto cmp = [&](const int &a, const int &b) {
      if (bc[a] != bc[b]) return bc[a] < bc[b];
      return (a + T > n || b + T > n) ? a > b : bc[a + T] < bc[b + T];
    };

    for (i = 0; i <= sigma; ++i) cnt[i] = 0;
    for (i = 1; i <= n; ++i) ++cnt[(i + T > n) ? 0 : bc[i + T]];
    for (i = 1; i <= sigma; ++i) cnt[i] += cnt[i - 1];
    for (i = n; i; --i) {
      tmp[cnt[(sa[i] + T > n) ? 0 : bc[sa[i] + T]]--] = sa[i];
    }

    for (i = 0; i <= sigma; ++i) cnt[i] = 0;
    for (i = 1; i <= n; ++i) ++cnt[bc[i]];
    for (i = 1; i <= sigma; ++i) cnt[i] += cnt[i - 1];
    for (i = n; i; --i) sa[cnt[bc[tmp[i]]]--] = tmp[i];

    for (i = 2, tmp[sa[1]] = 1; i <= n; ++i) {
      tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
    }
    memcpy(bc + 1, tmp + 1, sizeof(int) * n);
  }

  for (i = 1; i <= n; ++i)rk[sa[i]] = i;

  for (i = 1, k = 0; i <= n; ++i) {
    if (rk[i] == 1) k = 0;
    else {
      j = sa[rk[i] - 1];
      if (k) --k;
      while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) ++k;
    }
    ht[rk[i]] = k;
  }

  for (i = 1; i <= n; ++i) {
      bit[i] = i == 1 ? 0 : bit[i >> 1] + 1;
      st[0][i] = ht[i];
  }
  for (j = 1; j <= bit[n]; ++j) {
    for (i = 1; i + (1 << j) - 1 <= n; ++i) {
      st[j][i] = std::min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
    }
  }
}

inline int lcp(int x, int y, int n) {
  if (x == y) {
    return n - x + 1;
  }
  int l = rk[x];
  int r = rk[y];
  if (l > r) {
    std::swap(l, r);
  }
  ++l;
  int i = bit[r - l + 1];
  return std::min(st[i][l], st[i][r - (1 << i) + 1]);
}
}

int n, dp[max_N], seg[max_N * 4], pos[max_N];

char s[max_N];

#define ls(x) ((x) << 1)
#define rs(x) (ls(x) | 1)
#define mid ((l + r) >> 1)
#define lch ls(x), l, mid
#define rch rs(x), mid + 1, r

inline void update(int x) {
  seg[x] = std::max(seg[ls(x)], seg[rs(x)]);
}

void build(int x = 1, int l = 1, int r = n) {
  if (l == r) {
    pos[l] = x;
  } else {
    build(lch);
    build(rch);
  }
}

void modify(int x, int y) {
  x = pos[x];
  seg[x] = y;
  for (; x > 1; x >>= 1) {
    update(x >> 1);
  }
}

int query(int ql, int qr, int x = 1, int l = 1, int r = n) {
  if (ql <= l && r <= qr) {
    return seg[x];
  } else {
    int ret = 0;
    if (ql <= mid) {
      ret = std::max(ret, query(ql, qr, lch));
    }
    if (qr > mid) {
      ret = std::max(ret, query(ql, qr, rch));
    }
    return ret;
  }
}

int main() {
  scanf("%d%s", &n, s + 1);
  SuffixArray::build(s, n);
  /*
  for (int i = 1; i <= n; ++i) {
    printf("sa[%d] = %d: %s\n", i, SuffixArray::sa[i], s + SuffixArray::sa[i]);
  }
  fflush(stdout);
  */
  build();
  int k = 0, right = n;
  for (int i = n; i; --i) {
    for (++k; k > 1; --k) {
      while (right >= i + k) {
        modify(SuffixArray::rk[right], dp[right]);
        --right;
      }
      int ql, qr;

      ql = qr = SuffixArray::rk[i];
      for (int step = 1 << log_N; step; step >>= 1) {
        if (ql - step >= 1 && SuffixArray::lcp(i, SuffixArray::sa[ql - step], n) >= k - 1) {
          ql -= step;
        }
        if (qr + step <= n && SuffixArray::lcp(i, SuffixArray::sa[qr + step], n) >= k - 1) {
          qr += step;
        }
      }
      if (query(ql, qr) >= k - 1) {
        break;
      }

      if (i == n) {
        continue;
      }
      ql = qr = SuffixArray::rk[i + 1];
      for (int step = 1 << log_N; step; step >>= 1) {
        if (ql - step >= 1 && SuffixArray::lcp(i + 1, SuffixArray::sa[ql - step], n) >= k - 1) {
          ql -= step;
        }
        if (qr + step <= n && SuffixArray::lcp(i + 1, SuffixArray::sa[qr + step], n) >= k - 1) {
          qr += step;
        }
      }
      if (query(ql, qr) >= k - 1) {
        break;
      }
    }
    dp[i] = k;
  }
  int ret = 0;
  for (int i = 1; i <= n; ++i) {
    ret = std::max(ret, dp[i]);
  }
  printf("%d\n", ret);
}