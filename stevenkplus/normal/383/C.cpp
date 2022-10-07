#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 200100;

int N, M;

int val[MAXN];
int BIT[MAXN];

int first[MAXN];
int last[MAXN];
int lev[MAXN];
vector<int> ch[MAXN];

int num = 0;
void dfs(int cur, int prv = 0, int dpth = 0) {
  ++num;
  lev[cur] = dpth;
  first[cur] = num;
  for(int i = 0; i < int(ch[cur].size()); ++i) {
    int n = ch[cur][i];
    if (n != prv) {
      dfs(n, cur, dpth + 1);
    }
  }
  last[cur] = num;
}

void inc(int x, int v) {
  while (x < MAXN) {
    BIT[x] += v;
    x += x & -x;
  }
}

int ask(int x) {
  int ret = 0;
  while (x) {
    ret += BIT[x];
    x -= x & -x;
  }
  return ret;
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 1; i <= N; ++i) {
    scanf("%d", val + i);
  }
  for(int i = 0; i < N - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    ch[a].push_back(b);
    ch[b].push_back(a);
  }

  dfs(1);
  for(int i = 0; i < M; ++i) {
    int qtype;
    scanf("%d", &qtype);
    if (qtype == 1) {
      int x, v;
      scanf("%d %d", &x, &v);
      if (lev[x] % 2 == 1) v = -v;
      inc(first[x], v);
      inc(last[x] + 1, -v);
    } else {
      int x;
      scanf("%d", &x);
      int ans = val[x];
      int as = ask(first[x]);
//      printf("%d: ans = %d, as = %d\n", x, ans, as);
      if (lev[x] % 2 == 0) ans += as;
      else ans -= as;

      printf("%d\n", ans);
    }
  }

  return 0;
}