#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
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

int n;
char s[200005];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    read(n);
    scanf("%s", s);
    int lim = 0;
    bool equ = true;
    while (lim + 1 < n && s[lim + 1] <= s[lim]) {
      if (s[lim + 1] < s[lim]) equ = false;
      if (equ && s[lim + 1] == s[lim]) break;
      ++lim;
    }
    for (int i = 1; i <= lim; ++i)
      if (s[i] != s[0]) { equ = false; break; }
    if (equ) { printf("%c%c\n", s[0], s[0]); }
    else {
      for (int i = 0; i <= lim; ++i)
        putchar(s[i]);
      for (int i = lim; i >= 0; --i)
        putchar(s[i]);
      putchar('\n');
    }
  }
  return 0;
}