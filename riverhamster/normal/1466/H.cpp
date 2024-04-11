#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <map>
#include <functional>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf(f)
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
  do x = x * 10 + (ch - '0'); while (isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int M = 1000000007;

using state = array<int, 41>;

map<state, int> mem;
int fc[41][41], C[41][41];
int n;

int solve(state st) {
  auto ret = mem.emplace(st, 0);
  int &ans = ret.first->second;
  if (!ret.second) return ans;

  int vcnt = 0;
  for (int i = 1; i <= n; ++i)
    vcnt += st[i] * i;

  state sub;
  fill(all(sub), 0);
  function<void(int)> DFS = [&](int i) {
    if (i > n) {
      int rem = 0, coef = M - 1;
      for (int i = 1; i <= n; ++i) {
        rem += sub[i] * i;
        coef = (ll)coef * C[st[i]][sub[i]] % M;
        if ((st[i] ^ sub[i]) & 1) coef = M - coef;
      }
      if (rem != vcnt) {
        ans = (ans + (ll)coef * fc[rem][vcnt - rem] % M * solve(sub)) % M;
      }
      return;
    }
    for (sub[i] = 0; sub[i] <= st[i]; ++sub[i])
      DFS(i + 1);
  };
  DFS(1);
  return ans;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n);
  state st;
  fill(all(st), 0);
  vector<int> p(n), vis(n);
  for (int &x : p)
    read(x), --x;
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    int siz = 0;
    while (!vis[i]) vis[i] = 1, i = p[i], ++siz;
    ++st[siz];
  }
  vector<int> fac(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = (ll)fac[i - 1] * i % M;
  for (int i = 0; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
  }
  for (int i = 0; i <= n; ++i) {
    int sum = 0;
    for (int j = 0; j <= i; ++j)
      sum = (sum + (ll)fac[j] * fac[n - 1 - j] % M * C[i][j]) % M;
    fc[i][1] = sum;
    for (int j = 2; j <= n; ++j)
      fc[i][j] = (ll)fc[i][j - 1] * sum % M;
  }
  state term;
  fill(all(term), 0);
  mem[term] = 1;
  printf("%d\n", solve(st));
  return 0;
}