#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 200100;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

int N;

int DP[2][MAXN];
// A: DP[1]

vector<int> conn[MAXN];
int par[MAXN];
int ht[MAXN];

int dfs(int cur, int prv = 0, int lev = 1) {
  par[cur] = prv;
  ht[cur] = lev;
  int cnt = 0;
  int sum = 0;
  repi(i, conn[cur]) {
    int nxt = *i;
    if (nxt == prv) continue;
    ++cnt;
    sum += dfs(nxt, cur, lev + 1);
  }

  int *A = DP[lev % 2];
  int *B = DP[(lev + 1) % 2];
  if (cnt == 0) {
    A[cur] = B[cur] = 1;
    return 1;
  }

  A[cur] = sum;
  B[cur] = 0;
  repi(i, conn[cur]) {
    int nxt = *i;
    if (nxt == prv) continue;
    if (A[nxt] < A[cur]) {
      A[cur] = A[nxt];
    }

    B[cur] += B[nxt];
  }

  return sum;
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    conn[a].push_back(b);
    conn[b].push_back(a);
  }

  int M = dfs(1);
  int a = DP[1][1];
  int b = DP[0][1];
  printf("%d %d\n", M + 1 - a, b);
}