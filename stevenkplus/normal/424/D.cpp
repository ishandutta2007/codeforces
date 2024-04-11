#include <cstdio>
#include <set>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAXN = 333;
const int inf = 1 << 30;

typedef pair<int, int> pii;

int grid[MAXN][MAXN];
int h1[MAXN][MAXN], h2[MAXN][MAXN];
int v1[MAXN][MAXN], v2[MAXN][MAXN];

#define chk(x) if (abs((x)-T)<ans) { ans = abs((x)-T),a=lft,b=rgt,c=it->second,d=down; }
int N, M, T;

int a, b, c, d;
int ans = inf;

void go(int h1[MAXN][MAXN], int h2[MAXN][MAXN], int v1[MAXN][MAXN], int v2[MAXN][MAXN]) {
  for(int lft = 0; lft < M; ++lft) {
    for(int rgt = lft + 2; rgt < M; ++rgt) {
      set<pii> s;
      for(int down = 0; down < N; ++down) {
        int o = 0;
        o += h2[down][rgt] - h2[down][lft];
        o += v1[down][rgt];
        o += v2[down][lft];
        int need = T - o;
        set<pii>::iterator it = s.lower_bound(pii(need, -1));
        if (it != s.end()) chk(it->first + o);
        if (it != s.begin()) --it;
        if (it != s.end()) chk(it->first + o);

        int up = down - 1;
        if (up >= 0) {
          int val = h1[up][rgt] - h1[up][lft];
          val -= v1[up][rgt];
          val -= v2[up][lft];
          s.insert(pii(val, up));
        }
      }
    }
  }
}

int main () {
  scanf("%d %d %d", &N, &M, &T);

  int x, y, z;
  scanf("%d %d %d", &x, &y, &z);
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      scanf("%d", grid[i] + j);
    }
  }

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      h1[i][j + 1] = h1[i][j];
      h2[i][j + 1] = h2[i][j];
      if (grid[i][j + 1] > grid[i][j]) h1[i][j + 1] += y, h2[i][j + 1] += z;
      else if (grid[i][j + 1] == grid[i][j]) h1[i][j + 1] += x, h2[i][j + 1] += x;
      else h1[i][j + 1] += z, h2[i][j + 1] += y;
      v1[i + 1][j] = v1[i][j];
      v2[i + 1][j] = v2[i][j];
      if (grid[i + 1][j] > grid[i][j]) v1[i + 1][j] += y, v2[i + 1][j] += z;
      else if (grid[i + 1][j] == grid[i][j]) v1[i + 1][j] += x, v2[i + 1][j] += x;
      else v1[i + 1][j] += z, v2[i + 1][j] += y;
    }
  }

  go(h1, h2, v1, v2);
//  go(h2, h1, v2, v1);

  printf("%d %d %d %d\n", c + 1, a + 1, d + 1, b + 1);
  return 0;
}