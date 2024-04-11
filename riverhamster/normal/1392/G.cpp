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

namespace io {
  const int SIZE = (1 << 21) + 1;
  char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1;
  char getc () { return (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++); }
  void flush () { fwrite (obuf, 1, oS - obuf, stdout); oS = obuf; }
  void putc (char x) { *oS ++ = x; if (oS == oT) flush (); }
  template <class T> void read(T &x) {
    char ch; int f = 1;
    x = 0;
    while (isspace(ch = getc()));
    if (ch == '-') ch = getc(), f = -1;
    do x = x * 10 + (ch - '0'); while(isdigit(ch = getc()));
    x *= f;
  }
  template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }
  template <class T> void write(T x) {
    static char stk[128];
    int top = 0;
    if (x == 0) { putc('0'); return; }
    if (x < 0) putc('-'), x = -x;
    while (x) stk[top++] = x % 10, x /= 10;
    while (top) putc(stk[--top] + '0');
  }
  template <class T, class ...A> void write(T x, A... args) { write(x); putc(' '); write(args...) ; }
  void space() { putc(' '); }
  void endl() { putc('\n'); }
  struct _f {~_f() { flush(); }} __f;
}
using io::read; using io::write; using io::flush; using io::space; using io::endl; using io::getc; using io::putc;

const int N = (1 << 20) + 3;

int read_bin() {
  int x = 0;
  char ch;
  while (isspace(ch = getc()))
    ;
  for (int i = 0; isdigit(ch); ++i, ch = getc())
    x |= int(ch - '0') << i;
  return x;
}

int A[N], B[N];
int perm[20];
int n, m, K;
int fir_a[N], fir_b[N];

void supset_min(int *A, int *dp) {
  memset(dp, 0x3f, sizeof(int) * N);
  for (int i = 0; i <= n; ++i)
    dp[A[i]] = min(dp[A[i]], i);
  for (int i = (1 << K) - 1; i >= 0; --i)
    for (int j = 0; j < K; ++j)
      dp[i] = min(dp[i], dp[i | (1 << j)]);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(n, m, K);
  A[0] = read_bin(); B[0] = read_bin();
  LOG("A[0] = %d B[0] = %d\n", A[0], B[0]);
  iota(perm, perm + K, 0);
  for (int i = 1; i <= n; ++i) {
    int u, v;
    read(u, v);
    --u; --v;
    int p = find(perm, perm + K, u) - perm, q = find(perm, perm + K, v) - perm;
    swap(perm[p], perm[q]);
    A[i] = A[i - 1]; B[i] = B[i - 1];
    if (((A[i] >> p) & 1) != ((A[i] >> q) & 1))
      A[i] ^= (1 << p) | (1 << q);
    if (((B[i] >> p) & 1) != ((B[i] >> q) & 1))
      B[i] ^= (1 << p) | (1 << q);
  }

  supset_min(A, fir_a);
  reverse(B, B + n + 1);
  supset_min(B, fir_b);

  int ans = 0x3f3f3f3f, ansl = 0, ansr = 0;
  int pop = __builtin_popcount(A[0]) + __builtin_popcount(B[0]);
  for (int i = 0; i < (1 << K); ++i) {
    if (fir_a[i] + fir_b[i] + m <= n) {
      int c = pop - 2 * __builtin_popcount(i);
      if (c < ans) {
        ans = c;
        ansl = fir_a[i] + 1;
        ansr = n - fir_b[i];
      }
    }
  }
  printf("%d\n%d %d\n", K - ans, ansl, ansr);
  return 0;
}