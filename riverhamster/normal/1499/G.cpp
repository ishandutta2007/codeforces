#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <list>
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

#define assert_f(expr, fmt...) (!!(expr) || (LOG("Assertion Failed!\n"), LOG(fmt), LOG("\n"), abort(), true))

const int M = 998244353;
const int N = 400005;

int add(int x, int y) { return x + y >= M ? x + y - M : x + y; }
void inc(int &x, int y) { x += y; if (x >= M) x -= M; }
void dec(int &x, int y) { x -= y; if (x < 0) x += M; }

list<int> path[N];
int match[N];
int pc = 0;
int id[N];
int ec = 0;
int res[N], rc = 0, Hash = 0;
bool col[N];
int pow2[N];
int n1, n2, m;

pair<int, int> EDGE[N];
int EC = 0, deg[N];

void link(int u, int v) {
  ++ec;
  if (!id[u] && !id[v]) {
    path[++pc] = {ec};
    id[u] = pc; id[v] = -pc;
    match[u] = v; match[v] = u;
    return;
  }
  if (id[v] && !id[u]) swap(u, v);
  if (id[u] && !id[v]) {
    id[v] = id[u]; id[u] = 0;
    match[match[u]] = v;
    match[v] = match[u];
    match[u] = 0;
    if (id[v] > 0) {
      if (!col[path[id[v]].front()]) {
        col[ec] = true;
        inc(Hash, pow2[ec]);
      }
      path[id[v]].emplace_front(ec);
    }
    else {
      if (!col[path[-id[v]].back()]) {
        col[ec] = true;
        inc(Hash, pow2[ec]);
      }
      path[-id[v]].emplace_back(ec);
    }
  }
  else { // id[u] && id[v]
    if (id[u] == -id[v]) {
      if (!col[path[abs(id[u])].front()])
        col[ec] = true, inc(Hash, pow2[ec]);
      path[abs(id[u])].clear();
      id[u] = id[v] = 0;
      match[u] = match[v] = 0;
      return;
    }
    if (path[abs(id[u])].size() > path[abs(id[v])].size())
      swap(u, v);
    if ((id[u] > 0) == (id[v] > 0)) {
      path[abs(id[u])].reverse();
      id[u] = -id[u];
      id[match[u]] = -id[match[u]];
    }
    bool col_u = id[u] > 0 ? col[path[id[u]].front()] : col[path[-id[u]].back()];
    bool col_v = id[v] > 0 ? col[path[id[v]].front()] : col[path[-id[v]].back()];
    if (col_u != col_v) {
      for (int e : path[abs(id[u])]) {
        if (col[e]) dec(Hash, pow2[e]), col[e] = false;
        else inc(Hash, pow2[e]), col[e] = true;
      }
    }
    if (id[v] > 0) {
      path[id[v]].push_front(ec);
      path[id[v]].splice(path[id[v]].begin(), path[-id[u]]);
    }
    else {
      path[-id[v]].push_back(ec);
      path[-id[v]].splice(path[-id[v]].end(), path[id[u]]);
    }
    int del_id = abs(id[u]);
    int cnt = 0;
    for (int i = 1; i <= n1 + n2; ++i)
      cnt += abs(id[i]) == del_id;
    id[match[u]] = id[v];
    match[match[v]] = match[u];
    match[match[u]] = match[v];
    match[u] = match[v] = 0;
    if (!col_v)
      col[ec] = true, inc(Hash, pow2[ec]);
    id[u] = id[v] = 0;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  pow2[0] = 1;
  for (int i = 1; i <= 400000; ++i)
    pow2[i] = pow2[i - 1] * 2 % M;

  read(n1, n2, m);
  while (m--) {
    int u, v;
    read(u, v);
    link(u, v + n1);
  }

  int Q;
  read(Q);
  while (Q--) {
    int opt, u, v;
    read(opt);
    if (opt == 1) {
      read(u, v);
      link(u, v + n1);
      printf("%d\n", Hash); fflush(stdout);
    }
    else {
      rc = 0;
      for (int i = 1; i <= ec; ++i)
        if (col[i]) res[rc++] = i;
      printf("%d\n", rc);
      for (int i = 0; i < rc; ++i) printf("%d ", res[i]);
      putchar('\n'); fflush(stdout);
    }
  }
  return 0;
}