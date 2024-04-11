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

const int N = 1000005;

char s[N];
int c1[N];
bool col[N];
int row[N];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    int n, m, cnt;
    read(n, m);
    scanf("%s", s + 1);
    cnt = n * m;
    for (int i = 1; i <= cnt; ++i)
      c1[i] = c1[i - 1] + (s[i] == '1');
    for (int i = 1; i <= cnt; ++i) {
      int lst = max(0, i - m);
      // printf("lst = %d c1 %d %d\n", lst, c1[i], c1[lst]);
      row[i] = c1[i] != c1[lst];
    }
    for (int i = m + 1; i <= cnt; ++i)
      row[i] += row[i - m];
    int cols = 0;
    fill(col, col + m, 0);
    for (int i = 1; i <= cnt; ++i) {
      if (s[i] == '1' && !col[i % m]) col[i % m] = true, ++cols;
      // printf("cols = %d\n", cols);
      printf("%d ", cols + row[i]);
    }
    puts("");
  }
  return 0;
}