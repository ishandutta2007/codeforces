#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define LOG(FMT...) fprintf(stderr, FMT)

const int Node = 600005, N = 300005;

struct node {
  int c[26];
  int fail, val, sum;
  int &operator[](int x) { return c[x]; }
} t[Node];
int nc = 0;
vector<int> G[N];
char s[N];
int rt[96], sz[96];

void insert(int &rt, char *s, int val) {
  if (!rt) rt = ++nc;
  int x = rt;
  for (; *s; ++s) {
    int c = *s - 'a';
    if (!t[x][c]) t[x][c] = ++nc;
    x = t[x][c];
  }
  t[x].val += val;
}
void build(int rt) {
  static int q[N];
  int l = 0, r = 0;
  for (int i = 0; i < 26; ++i)
    if (t[rt][i]) q[++r] = t[rt][i], t[t[rt][i]].fail = rt;
  while (l < r) {
    int x = q[++l];
    t[x].sum = t[t[x].fail].sum + t[x].val;
    for (int i = 0; i < 26; ++i)
      if (t[x][i]) {
        int f = t[x].fail;
        while (f != rt && !t[f][i]) f = t[f].fail;
        if (!t[f][i]) t[t[x][i]].fail = rt;
        else t[t[x][i]].fail = t[f][i];
        q[++r] = t[x][i];
      }
  }
}
int Merge(int x, int y) {
  if (!x || !y) return x | y;
  t[x].val += t[y].val;
  for (int i = 0; i < 26; ++i)
    if (t[x][i] || t[y][i]) t[x][i] = Merge(t[x][i], t[y][i]);
  return x;
}
int query(int rt, char *s) {
  int res = 0, x = rt;
  for (; *s; ++s) {
    int c = *s - 'a';
    while (x != rt && !t[x][c]) x = t[x].fail;
    if (t[x][c]) x = t[x][c];
    res += t[x].sum;
  }
  return res;
}

int main() {
  int m;
  scanf("%d", &m);
  int top = 0;
  while (m--) {
    int op;
    scanf("%d%s", &op, s);
    auto fix = [&]() {
      while (top >= 2 && sz[top] >= sz[top - 1]) {
        sz[top - 1] += sz[top]; sz[top] = 0;
        Merge(rt[top - 1], rt[top]), rt[top] = 0;
        --top;
      }
      build(rt[top]);
    };
    if (op == 1) {
      if (top && sz[top] == 1) insert(rt[top], s, +1), ++sz[top];
      else ++top, insert(rt[top], s, +1), ++sz[top];
      fix();
    }
    else if (op == 2) {
      if (sz[top] == 1) insert(rt[top], s, -1), ++sz[top];
      else ++top, insert(rt[top], s, -1), ++sz[top];
      fix();
    }
    else {
      int res = 0;
      for (int i = 1; i <= top; ++i)
        res += query(rt[i], s);
      printf("%d\n", res); fflush(stdout);
    }
  }
  return 0;
}