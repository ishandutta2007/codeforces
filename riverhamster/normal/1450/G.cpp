#include <cstdio>
#include <cassert>
#include <algorithm>
#include <numeric>
using namespace std;

const int N = 5005;
char s[N];
int a[N];
char alpha[26];
int acnt = 0;
bool vis[26];
int L[26], R[26], cnt[26];
bool f[1 << 20 | 5];

int main() {
  int n, A, B;
  scanf("%d%d%d", &n, &A, &B);
  scanf("%s", s);
  for (int i = 0; i < n; ++i)
    if (!vis[s[i] - 'a']) {
      vis[s[i] - 'a'] = true;
      alpha[acnt++] = s[i];
    }
  sort(alpha, alpha + acnt);
  fill(L, L + acnt, -1);
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(alpha, alpha + acnt, s[i]) - alpha;
    if (L[a[i]] == -1) L[a[i]] = i;
    R[a[i]] = i;
    ++cnt[a[i]];
  }

  f[0] = true;
  for (int i = 0; i < acnt; ++i)
    if (cnt[i] * B >= (R[i] - L[i] + 1) * A)
      f[1 << i] = true;

  int p[26];
  iota(p, p + acnt, 0);
  sort(p, p + acnt, [](int x, int y) { return L[x] < L[y]; });
  for (int s = 1; s < (1 << acnt); ++s) {
    if (f[s]) continue;
    int l = 1000000000, r = -1000000000, c = 0;
    bool flag = false;
    for (int i = 0; i < acnt; ++i)
      if ((s >> i) & 1) {
        l = min(l, L[i]), r = max(r, R[i]), c += cnt[i];
        flag |= (f[s ^ (1 << i)]);
      }
    if (c * B >= (r - l + 1) * A && flag) {
      f[s] = true;
      continue;
    }

    int t = 0;
    for (int i = 0; i < acnt; ++i) {
      if ((s >> p[i]) & 1) {
        t |= (1 << p[i]);
        if (f[t] && f[s ^ t]) {
          f[s] = true;
          break;
        }
      }
    }
  }

  const int U = (1 << acnt) - 1;
  char res[20];
  int rc = 0;
  for (int i = 0; i < acnt; ++i) {
    if (f[U ^ (1 << i)]) res[rc++] = alpha[i];
  }
  printf("%d ", rc);
  for (int i = 0; i < rc; ++i)
    putchar(res[i]), putchar(' ');
  putchar('\n');
  return 0;
}