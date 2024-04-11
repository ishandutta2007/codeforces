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
 
char s[100005], t[100005];
 
int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    int n;
    read(n);
    scanf("%s%s", s, t);
    // if (!count(s, s + n, '1')) {
    //   puts("-1");
    //   continue;
    // }
    int ans = n + 1, cur = 0, zeroes = 0;
    for (int i = 0; i < n; ++i) {
      cur += s[i] != t[i];
      if (s[i] != t[i]) zeroes += s[i] == '0';
    }
    if ((~cur & 1) && zeroes == cur / 2) ans = min(ans, cur);
    cur = 0;
    zeroes = 0;
    for (int i = 0; i < n; ++i) {
      cur += s[i] == t[i];
      if (s[i] == t[i]) zeroes += s[i] == '0';
    }
    if ((cur & 1) && zeroes == cur / 2) ans = min(ans, cur);
    if (ans <= n) printf("%d\n", ans);
    else puts("-1");
  }
  return 0;
}