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
    vector<int> a(n);
    for (int &x : a)
      read(x);
    auto slv = [&](int B) {
      vector<int> b, c;
      for (int x : a)
        if (x != B) b.push_back(x);
      c.resize(b.size());
      reverse_copy(all(b), begin(c));
      if (b == c) return true;
      return false;
    };
    bool pal = true;
    for (int i = 0; i < n; ++i)
      if (a[i] != a[n - 1 - i]) {
        puts(slv(a[i]) || slv(a[n - 1 - i]) ? "YES" : "NO");
        pal = false;
        break;
      }
    if (pal) puts("YES");
  }
  return 0;
}