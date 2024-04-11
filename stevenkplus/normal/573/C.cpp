#include <cstdio>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

const int MAXN = 100100;

int N;

vector<int> conn[MAXN];
int deg[MAXN];
int del[MAXN];
int row[MAXN];
int level[MAXN];

int cnt[MAXN];
int branch[MAXN];
void dfs(int cur, int par = 0) {
  repi(i, conn[cur]) {
    int nxt = *i;
    if (nxt != par) {
      dfs(nxt, cur);
      cnt[cur] += cnt[nxt];
      if (cnt[nxt]) {
        ++branch[cur];
      }
    }
  }
  if (level[cur] == 0) {
    ++cnt[cur];
  }
}

void check2(int cur) {
  if (level[cur]) return;
  int bad = 0;
  int good = 0;
  repi(i, conn[cur]) {
    if (level[*i] != 3) {
      ++bad;
    } else {
      ++good;
    }
  }
  if (bad <= 1 && good <= 2) {
    level[cur] = 2;
  }
}


void check(int cur) {
  if (level[cur]) return;
  while (!level[cur] && (deg[cur] == 1 || (deg[cur] == 2 && del[cur]))) {
    level[cur] = 3;
    int par = conn[cur][0];
    if (deg[cur] == 2) {
      par = conn[cur][0] + conn[cur][1] - del[cur];
    }

    del[par] = cur;
    cur = par;
  }
}

bool _main() {
  scanf("%d", &N);
  for(int i = 1; i < N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    conn[a].push_back(b);
    conn[b].push_back(a);
    ++deg[a];
    ++deg[b];
  }

  for(int i = 1; i <= N; ++i) {
    check(i);
  }

  for(int i = 1; i <= N; ++i) {
    check2(i);
  }


  int rt = 0;
  for(int i = 1; i <= N; ++i) {
    if (level[i] == 0) {
      rt = i;
    }
  }

  if (rt) {
    dfs(rt);
    if (branch[rt] > 2) {
      return false;
    }

    for(int i = 1; i <= N; ++i) {
      if (i != rt && branch[i] > 1) {
        return false;
      }
    }
    return true;
  } else {
    return true;
  }
}

int main() {
  if (_main()) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}