#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second

int n, m;

int x, y, z;
int P;

void rot(pii &p, int &par) {
  pii z;
  z.X = p.Y;
  z.Y = -p.X;
  par = 1 - par;
  if (par == 0) z.Y += m + 1;
  else z.Y += n + 1;
  p = z;
}

void flip(pii &p, int par) {
  p.Y = -p.Y;
  if (par == 0) p.Y += m + 1;
  else p.Y += n + 1;
}

int main() {
  scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &z, &P);
  for(int i = 0; i < P; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    pii cur(a, b);
    int par = 0;
    for(int j = 0; j < x % 4; ++j) {
      rot(cur, par);
      //printf("at %d %d\n", cur.X, cur.Y);
    }

    if (y % 2 == 1) {
      flip(cur, par);
      //printf("at %d %d\n", cur.X, cur.Y);
    }

    for(int j = 0; j < z % 4; ++j) {
      rot(cur, par);
      rot(cur, par);
      rot(cur, par);
      //printf("at %d %d\n", cur.X, cur.Y);
    }

    printf("%d %d\n", cur.X, cur.Y);
  }
  return 0;
}