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

int comp(int x) {
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) return true;
  return false;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    int n;
    read(n);
    vector<int> a(n);
    for (int &x : a)
      read(x);
    int sum = accumulate(all(a), 0);
    if (comp(sum)) {
      printf("%d\n", n);
      for (int i = 1; i <= n; ++i)
        printf("%d ", i);
      puts("");
    }
    else {
      for (int i = 0; i < n; ++i) {
        if (comp(sum - a[i])) {
          printf("%d\n", n - 1);
          for (int j = 0; j < n; ++j)
            if (j != i) printf("%d ", j + 1);
          puts("");
          break;
        }
      }
    }
  }
  return 0;
}