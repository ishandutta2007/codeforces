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

char s[200005];
char a[200005], b[200005];

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
    scanf("%s", s);
    vector<int> pa, pb;
    for (int i = 0; i < n; ++i)
      if (s[i] == '0') pb.push_back(i);
      else pa.push_back(i);
    if (pa.size() % 2 || pb.size() % 2) {
      puts("NO");
      continue;
    }
    a[n] = 0; b[n] = 0;
    for (int i = 0, li = pa.size() / 2; i < li; ++i)
      a[pa[i]] = b[pa[i]] = '(';
    for (int i = pa.size() / 2, li = pa.size(); i < li; ++i)
      a[pa[i]] = b[pa[i]] = ')';
    for (int i = 0, li = pb.size(); i < li; ++i)
      a[pb[i]] = '(' ^ (i & 1), b[pb[i]] = ')' ^ (i & 1);
    int sum = 0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      sum += b[i] == '(' ? 1 : -1;
      if (sum < 0) {
        puts("NO");
        ok = false;
        break;
      }
    }
    if (ok) {
      puts("YES");
      puts(a); puts(b);
    }
  }
  return 0;
}