#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

const int p10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
using ll = long long;

template<class T> void read(T &x){
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }
int getlen() {
  while (isspace(getchar()));
  int s = 0;
  while (getchar() == '?') ++s;
  return s;
}

int lenof(int x) {
  int res = 0;
  while (x) ++res, x /= 10;
  return res;
}

int cnt[6][6], cur[6][6];
vector<pair<int, int>> input;
int prufer[6];
int vis[6];
int L = 0;
int len[200005];
int n;

void work() {
  vector<pair<int, int>> edge;
  memcpy(cur, cnt, sizeof(cnt));
  fill(vis, vis + L, 0);
  for (int i = 0; i < L - 2; ++i) ++vis[prufer[i]];
  for (int i = 0; i < L - 2; ++i) {
    int pi = prufer[i];
    for (int j = 0; j < L; ++j)
      if (!vis[j]) {
        vis[j] = true;
        --cur[pi][j]; --cur[j][pi];
        if (cur[pi][j] < 0) return;
        edge.emplace_back(p10[pi], p10[j]);
        break;
      }
    --vis[prufer[i]];
  }
  vector<int> unvis;
  for (int i = 0; i < L; ++i)
    if (!vis[i]) unvis.push_back(i);
  if (unvis.size() == 2) {
    --cur[unvis[0]][unvis[1]]; --cur[unvis[1]][unvis[0]];
    if (cur[unvis[0]][unvis[1]] < 0) return;
    edge.emplace_back(p10[unvis[0]], p10[unvis[1]]);
  }

  int V[64], M[64];
  fill_n(V, 1 << L, 0);
  fill_n(M, 1 << L, 0);
  for (int i = 0; i < L; ++i) {
    int c = min(n, p10[i + 1] - 1) - p10[i];
    for (int s = 1; s < (1 << L); ++s)
      if ((s >> i) & 1) V[s] += c;
  }
  for (int i = 0; i < L; ++i)
    for (int j = i; j < L; ++j)
      for (int s = 0; s < (1 << L); ++s)
        if (((s >> i) & 1) || ((s >> j) & 1)) M[s] += cur[i][j];

  auto verify = [&]() {
    for (int i = 0; i < (1 << L); ++i)
      if (V[i] > M[i]) return false;
    return true;
  };
  if (!verify()) return;

  for (auto p : edge) printf("%d %d\n", p.first, p.second);
  for (int i = 1; i <= n; ++i) {
    int v = len[i] - 1;
    if (p10[v] == i) continue;
    for (int j = 0; j < L; ++j) {
      if (!cur[v][j]) continue;
      --cur[v][j];
      if (j != v) --cur[j][v];
      for (int s = 1; s < (1 << L); ++s) {
        V[s] -= ((s >> v) & 1);
        M[s] -= ((s >> v) & 1) || ((s >> j) & 1);
      }
      if (verify()) {
        printf("%d %d\n", i, p10[j]);
        break;
      }
      else {
        ++cur[v][j]; ++cur[j][v];
        for (int s = 1; s < (1 << L); ++s) {
          V[s] += ((s >> v) & 1);
          M[s] += ((s >> v) & 1) || ((s >> j) & 1);
        }
      }
    }
  }

  exit(0);
}

void DFS(int p) {
  if (p >= L - 2) return work();
  for (int i = 0; i < L; ++i) {
    prufer[p] = i;
    DFS(p + 1);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  setbuf(stdout, NULL);
#endif
  read(n);
  for (int i = 1; i <= n; ++i) len[i] = lenof(i);
  L = len[n];
  for (int i = 1; i < n; ++i) {
    int x = getlen(), y = getlen();
    input.emplace_back(x, y);
    if (x != y) ++cnt[x][y], ++cnt[y][x];
    else ++cnt[x][y];
  }
  DFS(0);
  puts("-1");
  return 0;
}