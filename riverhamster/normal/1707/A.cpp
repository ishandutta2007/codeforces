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

const int N = 100005;

int n, q;
int a[N];

bool nofail(int l) {
  int val = q;
  for (int i = l + 1; i < n; ++i) {
    val -= a[i] > val;
  }
  return val > 0;
}
void calc(int l) {
  int val = q;
  for (int i = 1; i <= l; ++i)
    putchar(val >= a[i] ? '1' : '0');
  for (int i = l + 1; i <= n; ++i)
    putchar('1');
  putchar('\n');
}

void single() {
  read(n, q);
  for (int i = 1; i <= n; ++i)
    read(a[i]);
  int l = 0, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (nofail(mid)) ans = mid, r = mid - 1;
    else l = mid + 1;
  }
  assert(ans != -1);
  calc(ans);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T = 1;
  read(T);
  while (T--) single();
  return 0;
}