/*
 * Please stop writing problems.
 * Just copy-paste your template and you'll get AC.
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 234567;
const int M = 12345678;
const int LOG = 18;
const int ALPHA = 26;

int n, m, gol[N], gor[N], length[N], sum_inv[N], cnt[N][ALPHA], rmq[LOG][N];
bool covered[M];
char s[N];

struct ap_t {
  int first, second, last;

  ap_t(int first = 0, int second = 0, int last = 0):first(first), second(second), last(last) {
  }

  void extend(int x) {
    last = x;
    if (!first) {
      first = x;
    }
    if (!second || first == second) {
      second = x;
    }
  }

  void reverse(int n) {
    int diff = second - first;
    swap(first, last);
    first = n - first + 1;
    last = n - last + 1;
    second = first + diff;
  }

  void move(int d) {
    first += d;
    second += d;
    last += d;
  }

  bool check(int x) {
    if (x < first || x > last) {
      return false;
    }
    if (first == second) {
      return x == first;
    }
    return (x - first) % (second - first) == 0;
  }
};

struct dbf_t {
  int n, sa[LOG][N], end[LOG][N], rank[LOG][N], begin[LOG][N];
  char s[N];

  void init() {
    static int a[N], b[N], sum[N], temp[N];
    for (int i = 1; i <= n; ++i) {
      ++sum[s[i] - 'a'];
    }
    for (int i = 1; i < 26; ++i) {
      sum[i] += sum[i - 1];
    }
    for (int i = n; i; --i) {
      sa[0][sum[s[i] - 'a']--] = i;
    }
    rank[0][sa[0][1]] = 1;
    for (int i = 2; i <= n; ++i) {
      rank[0][sa[0][i]] = rank[0][sa[0][i - 1]];
      if (s[sa[0][i]] != s[sa[0][i - 1]]) {
        ++rank[0][sa[0][i]];
      }
    }
    for (int k = 1; (1 << k) <= n; ++k) {
      for (int i = 0; i <= n; ++i) {
        sum[i] = 0;
      }
      for (int i = 1; i <= n; ++i) {
        a[i] = rank[k - 1][i];
        if (i + (1 << k - 1) <= n) {
          ++sum[b[i] = rank[k - 1][i + (1 << k - 1)]];
        } else {
          ++sum[b[i] = 0];
        }
      }
      for (int i = 1; i <= n; ++i) {
        sum[i] += sum[i - 1];
      }
      for (int i = n; i; --i) {
        temp[sum[b[i]]--] = i;
      }
      for (int i = 0; i <= n; ++i) {
        sum[i] = 0;
      }
      for (int i = 1; i <= n; ++i) {
        ++sum[a[i]];
      }
      for (int i = 1; i <= n; ++i) {
        sum[i] += sum[i - 1];
      }
      for (int i = n; i; --i) {
        sa[k][sum[a[temp[i]]]--] = temp[i];
      }
      rank[k][sa[k][1]] = 1;
      for (int i = 2; i <= n; ++i) {
        rank[k][sa[k][i]] = rank[k][sa[k][i - 1]];
        if (a[sa[k][i]] != a[sa[k][i - 1]] || b[sa[k][i]] != b[sa[k][i - 1]]) {
          ++rank[k][sa[k][i]];
        }
      }
    }
    for (int i = 0; (1 << i) <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (!begin[i][rank[i][sa[i][j]]]) {
          begin[i][rank[i][sa[i][j]]] = j;
        }
      }
      for (int j = n; j; --j) {
        if (!end[i][rank[i][sa[i][j]]]) {
          end[i][rank[i][sa[i][j]]] = j;
        }
      }
    }
  }

  ap_t ipm(int k, int p, int l, int r) {
    ap_t result;
    int x = begin[k][rank[k][p]], y = end[k][rank[k][p]], q;
    q = lower_bound(sa[k] + x, sa[k] + y + 1, l) - sa[k];
    if (q >= x && q <= y && sa[k][q] <= r) {
      result.extend(sa[k][q]);
    }
    ++q;
    if (q >= x && q <= y && sa[k][q] <= r) {
      result.extend(sa[k][q]);
    }
    q = upper_bound(sa[k] + x, sa[k] + y + 1, r) - sa[k] - 1;
    if (q >= x && q <= y && sa[k][q] <= r) {
      result.extend(sa[k][q]);
    }
    return result;
  }
} dbf;

struct suffix_array_t {
  int n, rank[N], array[N], height[N], length[N], rmq[LOG][N];
  char s[N];
  
  void init() {
    static int temp[N], first[N], second[N], number[N];
    for (int i = 1; i <= n; ++i) {
      ++number[s[i] - 'a'];
    }
    for (int i = 1; i < 26; ++i) {
      number[i] += number[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
      array[number[s[i] - 'a']--] = i;
    }
    for (int i = 0; i < 26; ++i) {
      number[i] = 0;
    }
    rank[array[1]] = 1;
    for (int i = 2; i <= n; ++i) {
      rank[array[i]] = rank[array[i - 1]] + (s[array[i]] != s[array[i - 1]]);
    }
    for (int length = 1; rank[array[n]] != n; length <<= 1) {
      for (int i = 1; i <= n; ++i) {
        ++number[second[i] = i + length > n ? 0 : rank[i + length]];
      }
      for (int i = 1; i <= n; ++i) {
        number[i] += number[i - 1];
      }
      for (int i = 1; i <= n; ++i) {
        temp[number[second[i]]--] = i;
      }
      for (int i = 0; i <= n; ++i) {
        number[i] = 0;
      }
      for (int i = 1; i <= n; ++i) {
        ++number[first[i] = rank[i]];
      }
      for (int i = 1; i <= n; ++i) {
        number[i] += number[i - 1];
      }
      for (int i = n; i; --i) {
        array[number[first[temp[i]]]--] = temp[i];
      }
      for (int i = 1; i <= n; ++i) {
        number[i] = 0;
      }
      rank[array[1]] = 1;
      for (int i = 2; i <= n; ++i) {
        rank[array[i]] = rank[array[i - 1]] + (first[array[i]] != first[array[i - 1]] || second[array[i]] != second[array[i - 1]]);
      }
    }
    for (int i = 1, j = 0; i <= n; ++i) {
      for (j -= j > 0; rank[i] != 1 && i + j <= n && array[rank[i] - 1] + j <= n && s[i + j] == s[array[rank[i] - 1] + j]; ++j);
      height[rank[i]] = j;
    }
    for (int i = 2; i <= n; ++i) {
      length[i] = length[i >> 1] + 1;
    }
    for (int i = 1; i <= n; ++i) {
      rmq[0][i] = height[i];
    }
    for (int i = 1; i < LOG; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
        rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << i - 1)]);
      }
    }
  }

  int lcp(int x, int y) {
    if (x == y) {
      return n - x + 1;
    }
    x = rank[x];
    y = rank[y];
    if (x > y) {
      swap(x, y);
    }
    ++x;
    int k = length[y - x];
    return min(rmq[k][x], rmq[k][y - (1 << k) + 1]);
  }
} sa, rsa;

inline int merge(ap_t p, ap_t q) {
  if (p.second == p.last) {
    swap(p, q);
  }
  if (q.second == q.last) {
    if (p.check(q.second)) {
      return q.second;
    } else if (p.check(q.first)) {
      return q.first;
    } else {
      return 0;
    }
  } else {
    return max(p.first, q.first) <= min(p.last, q.last) ? min(p.last, q.last) : 0;
  }
}

inline int longest_border(int l, int r) {
  int i = 0;
  while (1 << i <= r - l + 1) {
    ++i;
  }
  while (i--) {
    int length = 1 << i;
    ap_t p = dbf.ipm(i, l, max(l + 1, r - (length << 1) + 2), r - length + 1), q = dbf.ipm(i, r - length + 1, l, min(l + length - 1, r - length));
    if (!p.first || !q.first) {
      continue;
    }
    p.move(length - 1);
    p.reverse(r);
    q.move(1 - l);
    int result = merge(p, q);
    if (result) {
      return result + length - 1;
    }
  }
  return 0;
}

inline void add_square(int l, int r, int times) {
  int length = r - l + 1;
  for (int i = 0; i + 1 < times; ++i) {
    gor[l + length * i] = min(gor[l + length * i], length);
    gol[r + length * (times - i - 1)] = min(gol[r + length * (times - i - 1)], length);
  }
}

inline int query_min(int l, int r) {
  int k = length[r - l];
  return min(rmq[k][l], rmq[k][r - (1 << k) + 1]);
}

inline int query(int l, int r) {
  bool twice = false;
  for (int i = 0; i < ALPHA; ++i) {
    if (cnt[r][i] - cnt[l - 1][i] > 1) {
      twice = true;
    }
  }
  if (!twice) {
    return -1;
  }
  int border = longest_border(l, r);
  if (border) {
    if ((r - l + 1) % (r - l + 1 - border) == 0) {
      return 1;
    } else {
      return 2;
    }
  }
  if (min(gor[l], gol[r]) << 1 <= r - l + 1) {
    return 2;
  }
  if (cnt[r][s[l] - 'a'] != cnt[l][s[l] - 'a'] || cnt[r - 1][s[r] - 'a'] != cnt[l - 1][s[r] - 'a']) {
    return 3;
  }
  if (query_min(l, r) <= r) {
    return 3;
  }
  return 4;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %s %d", &n, s + 1, &m);
  dbf.n = sa.n = rsa.n = n;
  for (int i = 1; i <= n; ++i) {
    dbf.s[i] = sa.s[i] = rsa.s[n - i + 1] = s[i];
  }
  dbf.init();
  sa.init();
  rsa.init();
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < ALPHA; ++j) {
      cnt[i][j] = cnt[i - 1][j] + (s[i] - 'a' == j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    sum_inv[i] = sum_inv[i - 1] + n / i - 1;
    gol[i] = gor[i] = n + 1;
  }
  for (int length = 1; length << 1 <= n; ++length) {
    int l = -1, r = -1;
    for (int i = length; i + length <= n; i += length) {
      if (i > r) {
        int lcp = sa.lcp(i, i + length), lcs = rsa.lcp(n - i + 1, n - i - length + 1);
        if (lcp + lcs - 1 < length) {
          continue;
        }
        l = i - lcs + 1;
        r = i + lcp - 1;
        if (covered[sum_inv[length - 1] + i / length]) {
          continue;
        }
        for (int x = length << 1; l + x + x - 1 <= r + length; x += length) {
          covered[sum_inv[x - 1] + (l + x - 1) / x] = true;
        }
        for (int j = 0; j < length && l + j <= r - length + 1; ++j) {
          add_square(l + j, l + j + length - 1, (r - length + 1 - l - j) / length + 2);
        }
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    length[i] = length[i >> 1] + 1;
  }
  for (int i = 1; i <= n; ++i) {
    rmq[0][i] = i + (gor[i] << 1) - 1;
  }
  for (int i = 1; i < LOG; ++i) {
    for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
      rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << i - 1)]);
    }
  }
  while (m--) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", query(l, r));
  }
  return 0;
}