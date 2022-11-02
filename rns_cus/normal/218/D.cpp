#include <bits/stdc++.h>
using namespace std;
#define N 1001001

typedef pair <int, int> pii;

int n, k, c[N], cnt;
pii p[N];

pii calc(int a, int b) {
  if (b == 1) {
    return make_pair(a, a - 2);
  }
  pii rlt = calc(b, a % b);
  rlt.first += a / b;
  rlt.second += a / b - 1;
  return rlt;
}

void get_ans(int a, int b) {
  if (b == 1) {
    c[cnt++] = a - 1; return;
  }
  c[cnt++] = a / b;
  get_ans(b, a % b);
}

int main() {
//  freopen("d.in", "r", stdin);
  scanf("%d %d", &n, &k);
  if (n == 1 && k == 1) {
    printf("0\nT\n"); return 0;
  }
  for (int i = 1; i <= k; i ++) if (__gcd(i, k) == 1) p[i] = calc(k, i);
  int mn = n + 1, num = 0;
  for (int i = 1; i <= k; i ++) if (__gcd(i, k) == 1 && p[i].first == n) {
    if (p[i].second < mn) mn = p[i].second, num = i;
  }
  if (!num) {
    puts("IMPOSSIBLE"); return 0;
  }
  get_ans(k, num);
  c[cnt++] = 1;
  reverse(c, c + cnt);
  printf("%d\n", mn);
  for (int i = 0; i < cnt; i ++) {
    for (int j = 1; j <= c[i]; j ++) printf("%c", i % 2 == 0 ? 'T' : 'B');
  }
  puts("");
  return 0;
}