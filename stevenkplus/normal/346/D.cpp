#include <cstdio>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
const int MAXN = 1001000;

vector<int> to[MAXN];
vector<int> from[MAXN];

bool vis[MAXN];
int dist[MAXN];
int qn[MAXN];
int qd[MAXN];

int N, M;
int A, B;
int a = 0, b = 0;

void pshb(int x, int d) {
  if (vis[x]) return;
  qn[b] = x;
  qd[b] = d;
  ++b;
  b %= MAXN;
}

void pshf(int x, int d) {
  if (vis[x]) return;
  a += MAXN - 1;
  a %= MAXN;
  qn[a] = x;
  qd[a] = d;
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    to[a].push_back(b);
    from[b].push_back(a);
  }
  scanf("%d %d", &A, &B);
  for(int i = 1; i <= N; ++i) {
    dist[i] = -1;
  }

  pshb(B, 0);
  while (a != b) {
    int nxt = qn[a];
    int d = qd[a];
    ++a;

    if (vis[nxt]) continue;
    vis[nxt] = true;
    bool spec = true;
    repi(i, to[nxt]) {
      if (dist[*i] == -1 || dist[*i] != d - 1) {
        spec = false;
        break;
      }
    }

    if (d <= 0) spec = false;
    if (spec) --d;

    dist[nxt] = d;
    repi(i, from[nxt]) {
      if (spec)
        pshf(*i, d + 1);
      else pshb(*i, d + 1);
    }
  }

  printf("%d\n", dist[A]);
  return 0;
}