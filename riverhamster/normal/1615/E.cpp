#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>
#include <cassert>
#include <functional>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 200005;

vector<int> G[N];
int len[N];
vector<int> chain;

void DFS(int u, int fa = 0) {
  int son = 0;
  len[u] = 1;
  for (int v : G[u]) {
    if (v == fa) continue;
    DFS(v, u);
    len[u] = max(len[u], len[v] + 1);
    if (!son || len[v] > len[son]) son = v;
  }
  for (int v : G[u])
    if (v != fa && v != son) chain.push_back(len[v]);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, k;
  read(n, k);
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u, v);
    G[u].push_back(v); G[v].push_back(u);    
  }
  DFS(1);
  chain.push_back(len[1]);
  sort(all(chain), greater<int>());
  ll ans = -ll(n - n / 2) * (n / 2);
  // printf("ans = %lld\n", ans);
  int fre = n;
  for (int i = 1; i <= k; ++i) {
    if (i <= (int)chain.size())
      fre -= chain[i - 1];
    int b = min(n / 2, fre);
    // printf("i = %d b = %d\n", i, b);
    ans = max(ans, ll(i - b) * (n - i - b));
  }
  printf("%lld\n", ans);
  return 0;
}