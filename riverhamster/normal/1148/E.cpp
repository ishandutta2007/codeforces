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

const int N = 300005;

int a[N], b[N], id[N];
int stk[N], top = 0;
vector<tuple<int, int, int>> ans;

bool match(int i, int j) {
  if (a[i] < 0 && a[j] > 0) {
    int d = min(-a[i], a[j]);
    ans.emplace_back(i, j, d);
    a[i] += d; a[j] -= d;
    return true;
  }
  return false;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  read(n);
  for (int i = 0; i < n; ++i)
    read(a[i]);
  for (int i = 0; i < n; ++i)
    read(b[i]);
  if (accumulate(a, a + n, 0LL) != accumulate(b, b + n, 0LL)) {
    puts("NO");
    return 0;
  }
  iota(id, id + n, 0);
  sort(id, id + n, [](int x, int y) { return a[x] < a[y]; });
  sort(a, a + n);
  sort(b, b + n);
  for (int i = 0; i < n; ++i)
    a[i] -= b[i];
  for (int i = 0; i < n; ++i) {
    while (top) {
      if (!match(stk[top], i)) break;
      if (!a[stk[top]]) --top;
      else break;
    }
    if (a[i]) stk[++top] = i;
  }
  if (!top) {
    puts("YES");
    printf("%lld\n", (ll)ans.size());
    for (auto [i, j, d] : ans)
      printf("%d %d %d\n", id[i] + 1, id[j] + 1, d);
  }
  else {
    puts("NO");
  }
  return 0;
}