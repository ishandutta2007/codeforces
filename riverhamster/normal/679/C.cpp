#include <cstdio>
#include <algorithm>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

const int N = 505;
char a[N][N];
int id[N][N], cnt[N * N], cur_id = 0;
bool vis[N * N];
int n, k;
int con = 0;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

bool check(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= n && a[x][y] != 'X'; }
void DFS(int x, int y) {
  id[x][y] = cur_id;
  ++cnt[cur_id]; ++con;
  for (int d = 0; d < 4; ++d)
    if (check(x + dx[d], y + dy[d]) && !id[x + dx[d]][y + dy[d]])
      DFS(x + dx[d], y + dy[d]);
}

int x, y;

void down() {
  for (int i = y; i < y + k; ++i) ++cnt[id[x][i]];
  for (int i = y; i < y + k; ++i) --cnt[id[x + k][i]];
  ++x;
}
void left() {
  --y;
  for (int i = x; i < x + k; ++i) ++cnt[id[i][y + k]];
  for (int i = x; i < x + k; ++i) --cnt[id[i][y]];
}
void right() {
  for (int i = x; i < x + k; ++i) ++cnt[id[i][y]];
  for (int i = x; i < x + k; ++i) --cnt[id[i][y + k]];
  ++y;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i)
    scanf("%s", a[i] + 1);

  int res = 0;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (!id[i][j] && a[i][j] != 'X') {
        con = 0;
        ++cur_id, DFS(i, j);
        res = max(res, con);
      }

  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= k; ++j)
      --cnt[id[i][j]];
  x = 1; y = 1;
  int yd = 1;

  while (x <= n - k + 1) {
    int now = k * k;
    auto check = [&](int id) {
      if (id && !vis[id])
        vis[id] = true, now += cnt[id];
    };
    if (y > 1)
      for (int i = x; i < x + k; ++i) check(id[i][y - 1]);
    if (y + k <= n)
      for (int i = x; i < x + k; ++i) check(id[i][y + k]);
    if (x > 1)
      for (int i = y; i < y + k; ++i) check(id[x - 1][i]);
    if (x + k <= n)
      for (int i = y; i < y + k; ++i) check(id[x + k][i]);

    res = max(res, now);

    if (y > 1)
      for (int i = x; i < x + k; ++i) vis[id[i][y - 1]] = false;
    if (y + k <= n)
      for (int i = x; i < x + k; ++i) vis[id[i][y + k]] = false;
    if (x > 1)
      for (int i = y; i < y + k; ++i) vis[id[x - 1][i]] = false;
    if (x + k <= n)
      for (int i = y; i < y + k; ++i) vis[id[x + k][i]] = false;

    if (yd == 1) {
      if (y + yd <= n - k + 1) right();
      else down(), yd = -yd;
    }
    else {
      if (y + yd >= 1) left();
      else down(), yd = -yd;
    }
  }

  printf("%d\n", res);
  return 0;
}