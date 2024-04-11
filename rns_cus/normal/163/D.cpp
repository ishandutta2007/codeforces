#include <bits/stdc++.h>
using namespace std;
#define M 200010
#define ep 1e-9

typedef long long LL;

LL A, B, C, S, aa, bb, cc;

int n;

LL p[M], v;
int d[M], s[M];

void DFS(LL val, LL cur, int c) {
  if (c == n || cur * p[c] > val) {
    if (B < cur) B = cur; return;
  }
  LL tp = 1;
  for (int i = 0; i <= s[c]; i++) {
    if (cur * tp > val) break;
    DFS(val, cur * tp, c + 1);
    tp = tp * p[c];
  }
}

inline LL F(LL a, LL b, LL c) {return a * b + b * c + c * a;}

LL L;

void dfs(LL val, int c) {

  if (val > L) return;

  if (c == n) {
    LL lim = (LL)(sqrt(v / val) + ep);

    A = val; B = 0;

    if (2 * A * lim + v / val >= S) return;

    DFS(lim, 1, 0);
    C = v / A / B;
    LL tp = F(A, B, C);

    if (tp < S) aa = A, bb = B, cc = C, S = tp;

    return;
  }
  LL tp = 1;
  for (int i = 0; i <= d[c]; i++) {
    s[c] = d[c] - i;
    dfs(val * tp, c + 1);
    tp = tp * p[c];
  }
}

int main() {
	//freopen("in.txt", "r", stdin);
  int T;
  for (scanf("%d", &T); T--; ) {
    scanf("%d", &n);
    v = 1;
    for (int i = 0; i < n; i++) {
      scanf("%I64d %d", p + i, d + i);
      for (int j = 0; j < d[i]; j++) v *= p[i];
    }
    L = LL(pow(v, 1. / 3) + ep);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (p[i] > p[j]) swap(p[i], p[j]), swap(d[i], d[j]);
      }
    }
    S = 2 * v + 2;
    dfs(1, 0);
    printf("%I64d %I64d %I64d %I64d\n", 2 * S, aa, bb, cc);
  }
}