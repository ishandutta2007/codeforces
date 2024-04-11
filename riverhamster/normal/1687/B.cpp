#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
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

char str[505];

int main() {
// #ifdef LOCAL
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif
  int n, m;
  read(n, m);
  vector<pair<int, int>> e;
  fill(str, str + m, '0');
  for (int i = 0; i < m; ++i) {
    str[i] = '1'; printf("? %s\n", str); fflush(stdout);
    int x; read(x);
    e.emplace_back(x, i);
    str[i] = '0';
  }
  sort(all(e));
  int lst = 0;
  for (auto p : e) {
    str[p.second] = '1';
    printf("? %s\n", str); fflush(stdout);
    int x; read(x);
    if (x != lst + p.first) str[p.second] = '0';
    else lst = x;
  }
  printf("! %d\n", lst);
  fflush(stdout);
  return 0;
}