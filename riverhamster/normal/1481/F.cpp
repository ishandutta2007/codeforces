#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <bitset>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

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

const int N = 100005;
vector<int> G[N], L[N];
int mxdep = 0;
bool leaf[N];

void DFS(int x, int dep) {
  L[dep].emplace_back(x);
  mxdep = max(mxdep, dep);
  for (int v : G[x])
    DFS(v, dep + 1);
}

bitset<50048> f, g, update;
int from[50005];
char type[2] = {'b', 'a'};
bool t[N];
char res[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, x, _x;
  read(n, x); _x = x;
  if (n - x < x) x = n - x, swap(type[0], type[1]);
  for (int i = 2, fa; i <= n; ++i)
    read(fa), G[fa].emplace_back(i);
  DFS(1, 0);
  f.set(0);
  for (int i = 0; i <= mxdep; ++i) {
    g = f << L[i].size();
    update = ~f & g;
    for (int j = update._Find_first(); j <= x; j = update._Find_next(j)) {
      f.set(j);
      from[j] = i;
    }
  }
  if (f.test(x)) {
    printf("%d\n", mxdep + 1);
    for (int i = x; i; i -= L[from[i]].size()) t[from[i]] = true;
    for (int i = 0; i <= mxdep; ++i)
      for (int p : L[i])
        res[p] = type[t[i]];
  }
  else {
    printf("%d\n", mxdep + 2);
    int V = n;
    for (int i = 0; i <= mxdep; ++i) {
      if (x >= (int)L[i].size()) {
        x -= L[i].size();
        for (int p : L[i]) res[p] = type[1];
      }
      else if (V - x >= (int)L[i].size())
        for (int p : L[i]) res[p] = type[0];
      else {
        int nonleaf = x >= V - x;
        int nc = max(x, V - x), c = V - nc;
        for (int p : L[i])
          if (!G[p].empty()) res[p] = type[nonleaf], x -= nonleaf == 1;
          else if (c) res[p] = type[nonleaf ^ 1], x -= nonleaf == 0, --c;
          else res[p] = type[nonleaf], --nc, x -= nonleaf == 1;
      }
      V -= L[i].size();
    }
  }
  puts(res + 1);
  return 0;
}