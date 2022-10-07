#include <cstdio>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

const int MAXN = 100100;

int par[MAXN];
int deg[MAXN];
int ed[MAXN];

int N;

int anscnt = 0;
int ans[MAXN];
int flip[MAXN];
int moved[MAXN];

vector<int> ch[MAXN];

void go(int cur) {
  int p = par[par[cur]];
  if (moved[p]) moved[cur] ^= 1;

  if (flip[cur] != moved[cur]) {
    ans[anscnt] = cur;
    moved[cur] ^= 1;
    ++anscnt;
  }

  repi(i, ch[cur]) {
    go(*i);
  }
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    ed[a] += b;
    ed[b] += a;
    ++deg[a];
    ++deg[b];
  }

  for(int i = 1; i <= N; ++i) {
    scanf("%d", flip + i);
  }
  for(int i = 1; i <= N; ++i) {
    int x;
    scanf("%d", &x);
    flip[i] ^= x;
  }

  deg[1] = 0;

  for(int i = 1; i <= N; ++i) {
    int cur = i;
    while (deg[cur] == 1) {
      par[cur] = ed[cur];
      ch[par[cur]].push_back(cur);
      deg[cur] = 0;
      ed[cur] = 0;
      --deg[par[cur]];
      ed[par[cur]] -= cur;
      cur = par[cur];
    }
  }

  go(1);

  printf("%d\n", anscnt);
  for(int i = 0; i < anscnt; ++i) {
    printf("%d\n", ans[i]);
  }

  return 0;
}