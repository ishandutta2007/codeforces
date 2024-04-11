#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <cmath>
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

const int N = 1005;

bool a[N];

int main() {
  int n;
  read(n);
  if (n <= 3) {
    puts("0");
    return 0;
  }
  int B = int(sqrt(n) + 1e-7);
  int L = n - n / B - 1 - B + 1;
  if (n % B == 0) ++L;
  int sum = 0;
  while (sum < L) {
    vector<int> q;
    int contiguous = 0;
    for (int i = 1; i <= n && (int)q.size() < B; ++i) {
      if (!a[i]) {
        if (contiguous + 1 == B)
          contiguous = 0;
        else q.push_back(i), a[i] = true, ++contiguous;
      }
      else ++contiguous;
    }
    printf("%d ", (int)q.size());
    for (int x : q)
      printf("%d ", x);
    puts("");
    fflush(stdout);
    sum += q.size();
    int p;
    read(p);
    for (int i = 0, li = q.size(); i < li; ++i) {
      if (a[p]) {
        --sum;
        a[p] = false;
      }
      p = p % n + 1;
    }
  }
  puts("0");
  return 0;
}