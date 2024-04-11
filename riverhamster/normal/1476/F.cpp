#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

using ll = long long;

template<class T> void read(T &x){
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 300005;
int p[N], f[N], from[N];
int n;
int st[20][N];
char res[N];

void buildST() {
  for (int i = 1; i <= n; ++i)
    st[0][i] = i + p[i];
  for (int i = 1, li = __lg(n); i <= li; ++i)
    for (int j = 1; j <= n - (1 << i) + 1; ++j)
      st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}
int range_max(int l, int r) {
  if (l > r) return 0;
  int k = __lg(r - l + 1);
  return max(st[k][l], st[k][r - (1 << k) + 1]);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    read(n);
    for (int i = 1; i <= n; ++i) read(p[i]);
    buildST();
    fill(f + 1, f + 1 + n, 0);
    from[1] = 1;
    for (int i = 2; i <= n; ++i) {
      if (!p[i]) { f[i] = f[i - 1]; from[i] = i; continue; }
      int t = lower_bound(f, f + i, i - p[i] - 1) - f;
      from[i] = t;
      if (t == i) f[i] = f[i - 1];
      else {
        f[i] = max(i - 1, range_max(t + 1, i - 1));
        if (f[i - 1] > f[i]) f[i] = f[i - 1], from[i] = i;
        if (f[i - 1] >= i && i + p[i] > f[i]) {
          f[i] = i + p[i];
          from[i] = i;
        }
      }
    }

    if (f[n] < n) puts("NO");
    else {
      puts("YES");
      int cur = n;
      while (cur) {
        if (from[cur] == cur) res[cur] = 'R', --cur;
        else {
          res[cur] = 'L';
          fill(res + from[cur] + 1, res + cur, 'R');
          cur = from[cur];
        }
      }
      res[n + 1] = 0; puts(res + 1);
    }
  }
  return 0;
}