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

const int N = 300005;

vector<int> r1, r2;

int cost;
vector<pair<int, int>> G[N];
ll val[N];
bool vis[N];

void DFS(int x) {
  vis[x] = true;
  for (const auto &[v, id] : G[x]) {
    if (!vis[v]) {
      DFS(v);
      if (val[v] >= cost) {
        val[x] += val[v] - cost;
        r1.push_back(id);
      }
      else r2.push_back(id);
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  read(n, m, cost);
  for (int i = 1; i <= n; ++i) read(val[i]);
  if (accumulate(val + 1, val + 1 + n, 0LL) < ll(n - 1) * cost) {
    puts("NO");
    return 0;
  }
  for (int i = 1; i <= m; ++i) {
    int u, v;
    read(u, v);
    G[u].emplace_back(v, i); G[v].emplace_back(u, i);
  }
  DFS(1);
  puts("YES");
  for (int x : r1) printf("%d\n", x);
  for (auto i = r2.rbegin(); i != r2.rend(); ++i)
    printf("%d\n", *i);
  return 0;
}