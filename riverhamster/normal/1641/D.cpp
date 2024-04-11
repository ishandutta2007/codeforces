#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>
#include <cassert>
#include <array>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 100005;
const ull bas = 94358723053ULL;

using vt = array<int, 5>;
using ui = unsigned int;

pair<vt, int> a[N];
int stk[N], top = 0;

struct hashmap {
  static const int M = (1 << 22) - 1;
  struct node {
    ull k;
    ui v;
    node *nxt;
  } t[N << 5];
  node *hd[M + 1], *alloc = t;
  ui eval(ull k) {
    node *p = hd[k & M];
    while (p && p->k != k) p = p->nxt;
    return !p ? 0 : p->v;
  }
  void ins(ull k, ui v) {
    node *p = hd[k & M];
    while (p && p->k != k) p = p->nxt;
    if (p) p->v += v;
    else p = alloc++, *p = {k, v, hd[k & M]}, hd[k & M] = p;
  }
};
hashmap H;

vt A;
ui sum = 0;
int n, m;

void DFS1(int i, ull h) {
  if (i == m) { sum += H.eval(h); return; }
  DFS1(i + 1, h);
  DFS1(i + 1, h * bas + A[i]);
}

void DFS2(int i, ull h, int v) {
  if (i == m) { H.ins(h, v); return; }
  DFS2(i + 1, h, v);
  DFS2(i + 1, h * bas + A[i], -v);
}

bool chk(int i) {
  A = a[i].first;
  sum = 0;
  DFS1(0, 0);
  return sum;
}

void ins(int i, int v) {
  A = a[i].first;
  DFS2(0, 0, v);
}

bool inter(int i, int j) {
  int p = 0, q = 0;
  while (p != m && q != m) {
    if (a[i].first[p] == a[j].first[q]) return true;
    else if (a[i].first[p] < a[j].first[q]) ++p;
    else ++q;
  }
  return false;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      read(a[i].first[j]), a[i].first[j] += 43;
    sort(a[i].first.begin(), a[i].first.begin() + m);
    read(a[i].second);
  }
  sort(a, a + n, [](const auto &a, const auto &b) { return a.second < b.second; });
  int ans = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    A = a[i].first;
    while (top && chk(i)) {
      if (!inter(i, stk[top]))
        ans = min(ans, a[i].second + a[stk[top]].second);
      ins(stk[top--], -1);
    }
    stk[++top] = i;
    ins(i, 1);
  }
  if (ans == numeric_limits<int>::max()) puts("-1");
  else printf("%d\n", ans);
  // int Ans = numeric_limits<int>::max();
  // for (int i = 0; i < n; ++i)
  //   for (int j = i + 1; j < n; ++j)
  //     if (!inter(i, j)) Ans = min(Ans, a[i].second + a[j].second);
  // printf("Ans = %d\n", Ans);
  // assert(Ans == ans);
  return 0;
}