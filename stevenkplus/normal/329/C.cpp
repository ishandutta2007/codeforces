#include <cstdio>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
#define sz(x) int((x).size())

const int MAXN = 100100;

int N, M;
vector<int> conn[MAXN];
bool vis[MAXN];
int ar[MAXN];
int q[MAXN];

int pa[10];
int pb[10];
bool adj[10][10];
int deg[10];
int numed;

void prec() {
  numed = N * (N - 1) / 2;
  int a = 2, b = 1;
  for(int k = 0; k <= numed; ++k) {
    pa[k] = a, pb[k] = b;
    if (b + 1 >= a) {
      ++a;
      b = 1;
    } else {
      ++b;
    }
  }
}

bool go6() {
  prec();
  for(int i = 1; i <= N; ++i) {
    repi(j, conn[i]) {
      adj[i][*j] = true;
    }
  }

  for(int i = 0; i < (1 << numed); ++i) {
    int cnt = 0;
    bool bad = false;
    for(int j = 1; j <= N; ++j) deg[j] = 0;
    for(int j = 0; j < numed; ++j) if ((i >> j) & 1) {
      int a = pa[j], b = pb[j];
      ++deg[a], ++deg[b];
      if (adj[a][b] || deg[a] > 2 || deg[b] > 2) {
        bad = true;
        break;
      }
      ++cnt;
    }

    if (bad || cnt != M) continue;
    for(int j = 0; j < numed; ++j) {
      if ((i >> j) & 1) {
        int a = pa[j], b = pb[j];
        printf("%d %d\n", a, b);
      }
    }
    return true;
  }
  return false;
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i =  0; i < M; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    conn[a].push_back(b);
    conn[b].push_back(a);
  }
  if (M > N) {
    printf("-1\n"); 
  } else if (N <= 6) {
    if (!go6()) printf("-1\n");
  } else {
    int cur = 0;
    for(int i = 1; i <= N; ++i) {
      if (!vis[i]) {
        int a = 0;
        int b = 1;
        q[a] = i;
        vis[i] = true;
        while (a < b) {
          int x = q[a];
          ar[cur] = x;
          ++cur;
          ++a;
          repi(i, conn[x]) {
            if (!vis[*i]) {
              vis[*i] = true;
              q[b] = *i;
              ++b;
            }
          }
        }
      }
    }

    for(int i = 0; i < M; ++i) {
      printf("%d %d\n", ar[i], ar[(i + 3) % N]);
    }
  }
}