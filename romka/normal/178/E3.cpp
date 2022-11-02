#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory.h>
#include <cstring>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

bool a[2010][2010];
int n;
int kp;
short x[4000010], y[4000010];
bool u[2010][2010];
int s[2010][2010];

void dfs(int cx, int cy) {
  x[kp] = cx;
  y[kp] = cy;
  u[cx][cy] = true;
  kp++;

  forn(q, 4) {
    int nx = cx + dx[q];
    int ny = cy + dy[q];
    if (nx >= 0 && ny >= 0 && nx < n && ny < n)
      if (a[nx][ny] && !u[nx][ny])
        dfs(nx, ny);
  }
}

#define sqr(x) (x)*(x)

bool isBorder(int cx, int cy) {
  if (cx == 0 || cy == 0 || cx == n-1 || cy == n-1) return true;
  forn(q, 4) {
    int nx = cx + dx[q];
    int ny = cy + dy[q];
    if (a[nx][ny] == 0) return true;
  }
  return false;
}

int main()
{
  scanf("%d", &n);
  int z;
  forn(i, n)
    forn(j, n) {
      scanf("%d", &z);
      a[i][j] = z;
    }

  for (int i = 1; i < n - 1; i++)
    for (int j = 1; j < n - 1; j++) {
      int cnt = 0;
      forn(q, 8) {
        cnt += a[i+dx[q]][j+dy[q]];
      }
      if (cnt < 2) a[i][j] = 0;
      if (cnt > 6) a[i][j] = 1;
    }
      

  forn(q, 1) {

  forn(i, n+5)
    forn(j, n+5)
      s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + a[i][j];

  forn(i, n)
    forn(j, n) {
      if (i < 3 || j < 3) a[i][j] = 0;
      else {
        int ss = s[i+4][j+4] - s[i+4][j-3] - s[i-3][j+4] + s[i-3][j-3];
        a[i][j] = ss > 24;
      }
    }

  }

  int ci = 0, sq = 0;
  forn(i, n)
    forn(j, n)
      if (a[i][j] && !u[i][j]) {
        kp = 0;
        dfs(i, j);
        if (kp < 50) continue;
        double sx = 0, sy = 0;
        forn(i, kp) {
          sx += x[i];
          sy += y[i];
        }
        sx /= kp, sy /= kp;
        double maxD = -1, minD = 1e9;
        forn(i, kp) {
          if (!isBorder(x[i], y[i])) continue;
          double d = sqr(x[i]-sx) + sqr(y[i]-sy);
          if (d < minD) minD = d;
          if (d > maxD) maxD = d;
        }
        // printf("%.5f\n", maxD / minD);

        if (maxD / minD < 1.5) ci++;
        else sq++;
      }
  printf("%d %d\n", ci, sq);
  return 0;
}