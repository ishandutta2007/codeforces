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

const int N = 1e6 + 5;

int cnt[N];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    int n, siz;
    read(n, siz);
    fill(cnt, cnt + siz + 1, 0);
    for (int i = 0; i < n; ++i) {
      int x;
      read(x);
      ++cnt[x];
    }
    partial_sum(cnt, cnt + siz + 1, cnt);
    bool ok = true;
    for (int i = 1; i <= siz; ++i) {
      if (cnt[i] == cnt[i - 1]) continue;
      for (int j = 1, li = siz / i; j <= li; ++j) {
        int l = i * j - 1, r = min(siz, i * (j + 1) - 1);
        // printf("i = %d j = %d l = %d r = %d\n", i, j, l, r);
        if (cnt[l] != cnt[r] && cnt[j] == cnt[j - 1]) {
          // printf("c[j] %d c[j - 1] %d\n", cnt[j], cnt[j - 1]);
          ok = false;
          break;
        }
      }
      if (!ok) break;
    }
    puts(ok ? "Yes" : "No");
  }
  return 0;
}