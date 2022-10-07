#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 100100;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
vector<int> conn[MAXN];
int sm[MAXN];
int L[MAXN];

double wt[MAXN];

int deg[MAXN];
int N, Q;

double getwt(int guy) {
  double d = deg[guy];
  double tot = double(N) * (N - 1) / 2;
  double ways = d * (N - d);
  return ways / tot * 3;
}

int dfs(int cur, int prv = 0) {
  ++deg[cur];
  repi(i, conn[cur]) {
    int nxt = sm[*i] - cur;
    if (nxt == prv) continue;
    deg[cur] += dfs(nxt, cur);
    wt[*i] = getwt(nxt);
  }

  return deg[cur];
}

int main() {
  scanf("%d", &N);

  for(int i = 1; i < N; ++i) {
    int a, b, l;
    scanf("%d %d %d", &a, &b, &l);
    L[i] = l;
    sm[i] = a + b;
    conn[a].push_back(i);
    conn[b].push_back(i);
  }

  dfs(1);
  double sum = 0;
  for(int i = 1; i < N; ++i) {
    sum += L[i] * wt[i];
  }

  scanf("%d", &Q);
  for(int q = 0; q < Q; ++q) {
    int a, b;
    scanf("%d %d", &a, &b);
    int diff = L[a] - b;
    L[a] = b;
    sum -= diff * wt[a];
    printf("%.10lf\n", sum);
  }

  return 0;
}