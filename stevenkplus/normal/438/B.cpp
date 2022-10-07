#include <cstdio>
#include <algorithm>

using namespace std;

#define X first
#define Y second

typedef pair<int, int> pii;
typedef pair<int, pii> ed;

const int MAXN = 100100;

int ar[MAXN];
ed edges[MAXN];

int par[MAXN];
int sz[MAXN];
int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

void join(int a, int b) {
  par[a] = b;
  sz[b] += sz[a];
}

int N, M;

int main() {
  scanf("%d %d", &N, &M);

  for(int i = 1; i <= N; ++i) {
    scanf("%d", ar + i);
  }
  for(int i = 0; i < M; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    int wt = min(ar[a], ar[b]);
    edges[i] = ed(wt, pii(a, b));
  }


  for(int i = 1; i <= N; ++i) {
    par[i] = i;
    sz[i] = 1;
  }


  sort(edges, edges + M);
  reverse(edges, edges + M);
  double sum = 0;
  for(int i = 0; i < M; ++i) {
    int a = edges[i].Y.X, b = edges[i].Y.Y;
    int w = edges[i].X;
    a = find(a); b = find(b);
    if (a == b) continue;
    sum += double(w) * sz[a] * sz[b];
    join(a, b);
  }

  sum /= double(N) * (N - 1) / 2;
  printf("%.10lf\n", sum);
  return 0;
}