#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

#define all(cont) begin(cont), end(cont)

const int N = 3005;

vector<int> G[N];
int n, m;
int nc = 0;
bool vis[N];

void dfs(int x) {
  vis[x] = true; ++nc;
  for (int v : G[x])
    if (!vis[v]) dfs(v);
}

bool euler(int x) {
  int ter = 0;
  for (int i = 1; i <= n; ++i)
    if ((G[i].size() & 1) && i != x) {
      if (!ter) ter = i;
      else return false;
    }
  fill(vis + 1, vis + 1 + n, false);
  nc = 0; dfs(x);
  int sum = 0;
  for (int i = 1; i <= n; ++i) sum += !G[i].empty() || i == x;
  return nc == sum;
}

int stk[N], top = 0;
bool evis[N][N];

void geteuler(int x) {
  while (!G[x].empty()) {
    int v = G[x].back(); G[x].pop_back();
    if (evis[x][v] || evis[v][x]) continue;
    evis[x][v] = true;
    geteuler(v);
  }
  stk[++top] = x;
}

void output(int x, const vector<int> &del, int Ndel = -1) {
  geteuler(x);
  printf("%d\n", top + del.size() * 2 - 2 * (Ndel != -1) + 1);
  for (int i = 1; i <= top; ++i) printf("%d ", stk[i]);
  printf("-1 ");
  for (int v : del)
    if (v != Ndel) printf("%d %d ", v, x);
  putchar('\n');
  exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    read(u, v);
    G[u].push_back(v); G[v].push_back(u);
  }
  for (int c = 1; c <= n; ++c) {
    vector<int> del, nG;
    for (int v : G[c])
      if (G[v].size() & 1)
        del.push_back(v), G[v].erase(find(all(G[v]), c));
      else nG.push_back(v);
    G[c] = nG;
    if (euler(c)) output(c, del);
    for (int v : del) {
      G[c].push_back(v); G[v].push_back(c);
      if (euler(c)) output(c, del, v);
      G[c].pop_back(); G[v].pop_back();
    }
    for (int v : del)
      G[c].push_back(v), G[v].push_back(c);
  }
  puts("0");
  return 0;
}