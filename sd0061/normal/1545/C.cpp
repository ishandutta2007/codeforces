#include <bits/stdc++.h>

const int N = 505;
const int Q = 998244353;

int n;
int a[N + N][N];
bool g[N + N][N + N];
std::set<int> cnt[N][N];
int existed[N + N];
std::queue<int> q;

int f[N + N], c[N + N];
int getf(int x) {
  if (f[x] == x) {
    return x;
  }
  int fx = getf(f[x]);
  c[x] ^= c[f[x]];
  return f[x] = fx;
}
void merge(int x, int y) {
  int fx = getf(x);
  int fy = getf(y);
  if (fx != fy) {
    f[fx] = fy;
    c[fx] = c[x] ^ c[y] ^ 1;
  }
}

void clean_up(int i) {
  for (int j = 0; j < n; ++j) {
    cnt[j][a[i][j]].erase(i);
    if (cnt[j][a[i][j]].size() == 1) {
      int x = *cnt[j][a[i][j]].begin();
      if (existed[x] == -1) {
        existed[x] = 1;
        q.push(x);
      }
    }
  }
}

void work() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cnt[i][j].clear();
    }
  }
  for (int i = 0; i < n + n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
      --a[i][j];
      cnt[j][a[i][j]].insert(i);
    }
  }
  for (int i = 0; i < n + n; ++i) {
    for (int j = 0; j < i; ++j) {
      g[i][j] = g[j][i] = 0;
      for (int k = 0; k < n; ++k) {
        if (a[i][k] == a[j][k]) {
          g[i][j] = g[j][i] = 1;
          break;
        }
      }
    }
  }

  // for (int i = 0; i < n + n; ++i) {
  //   int cnt = 0;
  //   for (int j = 0; j < n + n; ++j) {
  //     printf("%d ", g[i][j]);
  //     cnt += (g[i][j] == 0);
  //   }
  //   printf(": %d\n", cnt);
  // }

  memset(existed, -1, sizeof(existed));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (cnt[i][j].size() == 1) {
        int x = *cnt[i][j].begin();
        if (existed[x] == -1) {
          existed[x] = 1;
          q.push(x);
        }
      }
    }
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (existed[x] == 1) {
      for (int i = 0; i < n + n; ++i) {
        if (g[x][i] && existed[i] == -1) {
          existed[i] = 0;
          q.push(i);
        }
      }
    }
    clean_up(x);
  }

  for (int i = 0; i < n + n; ++i) {
    // printf("%d ", existed[i]);
    if (existed[i] == -1) {
      f[i] = i;
      c[i] = 0;
      for (int j = 0; j < i; ++j) {
        if (existed[j] == -1 && g[i][j]) {
          merge(i, j);
        }
      }
    }
  }
  int res = 1;
  for (int i = 0; i < n + n; ++i) {
    if (existed[i] == -1) {
      if (getf(i) == i) {
        res += res;
        res %= Q;
      }
      existed[i] = c[i];
    }
  }
  printf("%d\n", res);
  for (int i = 0; i < n + n; ++i) {
    // printf("%d ", existed[i]);
    if (existed[i] == 1) {
      printf("%d ", i + 1);
    }
  }
  puts("");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}