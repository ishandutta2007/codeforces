#include <bits/stdc++.h>
using namespace std;
#define M 3000010
typedef long long LL;
LL ans[M];
int cnt[M], a[M], n, sz[M];

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
    sz[a[i]]++;
  }
  for (int i = M - 2; i; i--) cnt[i] += cnt[i + 1];

  for (int i = 1; i <= M - 10; i++) {
    int j = max(i, (M - 11) / i + 1);
    if (!sz[i]) continue;
    if (i == j) {
      ans[M - 10] += 2LL * sz[i] * (cnt[j] - sz[i]);
      ans[M - 10] += 1LL * sz[i] * (sz[i] - 1);
    }
    else {
      ans[M - 10] += 2LL * sz[i] * cnt[j];
    }
  }

  for (int i = 1; i <= M - 11; i++) {
    if (1LL * i * i > M - 11) break;
    for (int j = i * i + i; j <= M - 11; j += i) {
      ans[j] += 2LL * sz[i] * sz[j / i];
    }
    ans[i * i] += 1LL * sz[i] * (sz[i] - 1);
  }
  for (int i = M - 11; i; i--) {
    ans[i] += ans[i + 1];
  }
  //printf("%I64d\n", ans[24]);

  int Q, x;
  for (scanf("%d", &Q); Q--;) {
    scanf("%d", &x); printf("%I64d\n", ans[x]);
  }
}