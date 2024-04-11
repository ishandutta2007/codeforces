#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 200200;
int jar[MAXN];
int par[MAXN];

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

int up(int x) {
  if (jar[x] == x) return x;
  return jar[x] = up(jar[x]);
}

void join_find(int x, int y) {
  x = find(x);
  y = find(y);
  par[x] = y;
}

void join_up(int x, int y) {
  if (x > y) swap(x, y);
  x = up(x);
  while (x < y) {
//    printf("jar[%d] = %d\n", x, y);
    jar[x] = y;
    join_find(x, x + 1);
    x = jar[x + 1];
  }
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; ++i) {
    jar[i] = i;
    par[i] = i;
  }

  for(int p = 0; p < q; ++p) {
    int qtype, x, y;
    scanf("%d %d %d", &qtype, &x, &y);
    if (qtype == 1) {
      join_find(x, y);
    } else if (qtype == 2) {
      join_up(x, y);
    } else {
      if (find(up(x)) == find(up(y))) {
        printf("YES\n");
      } else { 
        printf("NO\n");
      }
    }
  }

  return 0;
}