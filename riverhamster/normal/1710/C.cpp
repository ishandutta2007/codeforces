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
  do x = x * 10 + (ch - '0'); while (isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 200005;
const int M = 998244353;

void inc(int &x, int y) { if ((x += y) >= M) x -= M; }

char s[N];
int dp[2][8][4];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  scanf("%s", s);
  int (*f)[4] = dp[0], (*g)[4] = dp[1];
  f[7][0] = 1;
  for (int i = 0; s[i]; ++i, swap(f, g)) {
    memset(g, 0, sizeof(dp[0]));
    int val = s[i] - '0';
    for (int h = 0; h < 8; ++h) {
      for (int st = 0; st < 4; ++st) {
        for (int v = 0; v < 8; ++v) {
          int nh;
          if (val == 0 && ((~v & h) != h)) continue;
          else if (val == 0) nh = h;
          else nh = h & v;
          if (v == 0 || v == 7)
            inc(g[nh][st], f[h][st]);
          else {
            int nst = st;
            int dif = __builtin_parity(v) ? v : v ^ 7;
            if (st == 0 && dif != 1) continue;
            else if (st == 1 && dif == 4) continue;
            nst += (st == 0 && dif == 1);
            nst += (st == 1 && dif == 2);
            nst += (st == 2 && dif == 4);
            inc(g[nh][nst], f[h][st]);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 8; ++i)
    inc(ans, f[i][3]);
  ans = 6LL * ans % M;
  printf("%d\n", ans);
  return 0;
}