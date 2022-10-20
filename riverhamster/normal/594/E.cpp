#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

constexpr int N = 5e6 + 5;

char s[N], r[N * 2];
int k, n;

pair<int, int> ly[N];
int lc = 0;

void lyndon_factorization(const char *s) {
  for (int i = 0; s[i];) {
    int j = i, k = i + 1;
    for (; s[j] <= s[k]; ++k)
      if (s[j] < s[k]) j = i;
      else ++j;
    while (i <= j) i += k - j;
    ly[++lc] = {i, k - j};
  }
}

void Z(const char *s, int *z) {
  z[0] = 0;
  int l = 0, r = 0;
  for (int i = 1; s[i]; ++i) {
    if (i > r) z[i] = 0;
    else z[i] = min(z[i - l], r - i + 1);
    while (s[i + z[i]] == s[z[i]]) ++z[i];
    if (z[i] > r) l = i, r = i + z[i] - 1;
  }
}

void work1() {
  bool eq = true;
  for (int i = 0; i < n; ++i)
    if (s[i] < s[n - i - 1]) {
      puts(s);
      eq = false; break;
    }
    else if (s[i] > s[n - i - 1]) {
      for (int i = n - 1; i >= 0; --i) putchar(s[i]);
      putchar('\n');
      eq = false; break;
    }
  if (eq) puts(s);
}

void work2() {
  reverse_copy(s, s + n, r); r[n] = 0;
  copy(r, r + n, r + n);
  int i = 0, j = 1, k = 0;
  while (i < n && j < n && k < n) {
    if (r[i + k] == r[j + k]) ++k;
    else {
      r[i + k] < r[j + k] ? j += k + 1 : i += k + 1;
      if (i == j) ++i;
      k = 0;
    }
  }
  int p = min(i, j);
  static char r1[N]; copy(r + p, r + p + n, r1);

  reverse_copy(r, r + n, r + n);
  static int z[N * 2];
  Z(r, z);
  int optr = n - 1;
  for (int i = n - 2; i > 0; --i) {
    int lcp = z[n + n - optr];
    int len = optr - i;
    if (lcp >= len) {
      lcp = z[optr - i];
      if (lcp < i && r[lcp] < r[optr - i + lcp]) optr = i;
    }
    else if (r[optr - 1 - lcp] < r[lcp]) optr = i;
  }
  static char r2[N];
  reverse_copy(r + optr, r + n, r2);
  copy(r, r + optr, r2 + n - optr);

  char _tp = r[n]; r[n] = 0;
  lc = 0;
  lyndon_factorization(r);
  r[n] = _tp;
  optr = ly[lc - 1].first;
  for (int i = lc - 2; i >= 0; --i) {
    int p = ly[i].first;
    if (!equal(r + ly[i + 1].first, r + n, r + p)) break;
    int border = n - optr;
    for (int i = p + border, j = optr - 1; i < n; ++i, --j)
      if (r[i] < r[j]) { optr = p; break; }
      else if (r[i] > r[j]) break;
  }
  static char r3[N];
  copy(r + optr, r + n, r3);
  reverse_copy(r, r + optr, r3 + n - optr);

  char *res = min({r1, r2, r3, s}, [](char *p, char *q) { return lexicographical_compare(p, p + n, q, q + n); });
  for (int i = 0; i < n; ++i) putchar(res[i]);
  putchar('\n');
}

void work3() {
  reverse_copy(s, s + n, r);
  lyndon_factorization(r);
  int i = lc;
  static char _res[N]; char *res = _res;
  for (; i; --i) {
    k -= !(ly[i].second == 1 && ly[i + 1].second == 1);
    if (k == 1) {
      int d = res - _res;
      printf("%s", _res);
      n -= d;
      for (int i = 0; i < n; ++i) s[i] = s[i + d];
      s[n] = 0;
      work2();
      return;
    }
    copy(r + ly[i - 1].first, r + ly[i].first, res);
    res += ly[i].first - ly[i - 1].first;
  }
  if (i) copy(r, r + ly[i].first, res);
  puts(_res);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  scanf("%s%d", s, &k);
  n = strlen(s);

  if (k == 1) work1();
  else if (k >= 3) work3();
  else work2();
  return 0;
}