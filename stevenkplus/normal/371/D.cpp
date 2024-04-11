#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 200100;

int val[MAXN];
int cap[MAXN];
int par[MAXN];
int pla[MAXN];

int N, Q;

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

void join(int a, int b) {
  a = find(a);
  b = find(b);
  par[a] = b;
  pla[b] = max(pla[a], pla[b]);
}

void pour(int amt, int loc) {
  //printf("pouring %d %d\n", amt, loc);
  loc = pla[find(loc)];
  //printf("loc->%d\n", loc);
  if (loc > N) return;
  if (amt == 0) return;

  val[loc] += amt;
  if (val[loc] > cap[loc]) {
    int tmp = val[loc] - cap[loc];
    val[loc] = cap[loc];
    join(loc, loc + 1);
    pour(tmp, loc);
  }
}

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i) {
    scanf("%d", cap + i);
    par[i] = i;
    pla[i] = i;
  }
  par[N + 1] = N + 1;
  pla[N + 1] = N + 1;

  scanf("%d", &Q);
  for(int i = 0; i < Q; ++i) {
    int qtype;
    scanf("%d", &qtype);
    if (qtype == 1) {
      int p, x;
      scanf("%d %d", &p, &x);
      pour(x, p);

    } else if (qtype == 2) {
      int k;
      scanf("%d", &k);
      printf("%d\n", val[k]);
    }
  }
  return 0;
}