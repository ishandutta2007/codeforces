#include <cstdio>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
vector <vector<int> > v;

const int MAXN = 1010;

int K;

bool adj[MAXN][MAXN];

void join(int a, int b) {
  adj[a][b] = adj[b][a] = true;
}

int main() {
  for(int i = 3; i + 1 <= 32; ++i) {
    join(i, i + 1);
  }
  join(32, 2);

  join(1, 34);
  join(1, 35);
  for(int i = 1; i + 1 <= 30; ++i) {
    int a = 2 * i + 32, b = a + 1;
    join(a, a + 2);
    join(a, a + 3);
    join(b, a + 2);
    join(b, a + 3);
  }

  scanf("%d", &K);

  for(int i = 0; i < 30; ++i) {
    if ((K >> i) & 1) {
      if (i == 0) join(1, 3);
      else {
        int a = 2 * i + 32, b = a + 1;
        int c = i + 3;
        join(a, c);
        join(b, c);
      }
    }
  }

  printf("95\n");
  for(int i = 1; i <= 95; ++i) {
    for(int j = 1; j <= 95; ++j) {
      if (adj[i][j]) printf("Y");
      else printf("N");
    }
    printf("\n");
  }
  return 0;
}