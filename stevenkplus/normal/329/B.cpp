#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 1010;

bool tree[MAXN][MAXN];
char grid[MAXN][MAXN];
int nums[MAXN][MAXN];
bool vis[MAXN][MAXN];

const int mx[] = {0, -1, 0, 1};
const int my[] = {1, 0, -1, 0};

int N, M;

int sx, sy;
int ex, ey;

queue<int> xq, yq, dq;

void psh(int x, int y, int d) {
//  printf("Trying to push %d %d %d\n", x, y, d);
  if (x < 0 || y < 0 || x >= N || y >= M) return;
  if (tree[x][y]) return;
  if (vis[x][y]) return;
  vis[x][y] = true;

  xq.push(x);
  yq.push(y);
  dq.push(d);
}

void visit(int x, int y, int d) {
  for(int j = 0; j < 4; ++j) {
    psh(x + mx[j], y + my[j], d + 1);
  }
}


int bfs(int srcx, int srcy) {
  for(int i = 0; i < MAXN; ++i) {
    for(int j = 0; j < MAXN; ++j) {
      vis[i][j] = false;
    }
  }

  //printf("bfsing from %d %d\n", srcx, srcy);
  int sum = 0;
  xq = queue<int>();
  yq = queue<int>();
  dq = queue<int>();
  psh(srcx, srcy, 0);

  int dst = -1;
  while (!xq.empty()) {
    int x = xq.front(); xq.pop();
    int y = yq.front(); yq.pop();
    int d = dq.front(); dq.pop();

//    printf("At %d %d %d\n", x, y, d);
    visit(x, y, d);
    if (x == sx && y == sy) {
      dst = d;
//      printf("dst = %d\n", dst);
    }
    if (dst == -1 || d <= dst) {
      sum += nums[x][y];
    } else if (dst != -1) break;
  }
  //printf("dst = %d\n", dst);
  return sum;
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; ++i) {
    scanf("%s", grid[i]);
    for(int j = 0; j < M; ++j) {
      char c = grid[i][j];
      if (c == 'S') {
        sx = i;
        sy = j;
      } else if (c == 'E') {
        ex = i;
        ey = j;
      } else if (c == 'T') {
        tree[i][j] = true;
      } else {
        nums[i][j] = grid[i][j] - '0';
      }
    }
  }

  int ans = bfs(ex, ey);

  printf("%d\n", ans);
  return 0;
}