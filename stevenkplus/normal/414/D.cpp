#include <cstdio>
#include <vector>

using namespace std;

#define repi(i,a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
const int MAXN = 100100;

typedef long long ll;

vector<int> conn[MAXN];

int cnt[MAXN];

int N, K, P;

void dfs(int cur, int prv = 0, int dpth = 0) {
  ++cnt[dpth];
  repi(i, conn[cur]) {
    int nxt = *i;
    if (nxt != prv) {
      dfs(nxt, cur, dpth + 1);
    }
  }
}

int main() {
  scanf("%d %d %d", &N, &K, &P);
  for(int i = 0; i < N - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    conn[a].push_back(b);
    conn[b].push_back(a);
  }

  dfs(1);

  int lft = 1, rgt = 1;
  ll cur = 0;
  int tot = 0;
  int ans = 0;

  while (rgt <= N) {
    //printf("lft = %d, rgt = %d, cur = %ll d, tot = %d\n", lft, rgt, cur, tot);
    if (cur <= P) {
      ll extr = P - cur;
      int cand = tot;
      if (lft > 1) {
        int len = rgt - lft;
        int get = extr / len;
        cand += get;
      }
      if (cand > ans) ans = cand;

      cur += tot;
      tot += cnt[rgt];
      ++rgt;
    } else {
      cur -= cnt[lft] * ll(rgt - lft - 1);
      tot -= cnt[lft];
      ++lft;
    }
  }

  if (ans > K) ans = K;

  printf("%d\n", ans);
  return 0;
}