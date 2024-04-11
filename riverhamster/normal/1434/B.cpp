#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

#define F(var, s, t) for (int var = s; var <= t; ++var)
#define RF(var, s, t) for (int var = s; var >= t; --var)
#define LOG(f...) fprintf(stderr, f)
const int N = 100005;
bool t[N * 2];
int v[N * 2];
int stk[N * 2], res[N], top = 0;

int main() {
  int n;
  scanf("%d", &n);
  F(i, 1, n * 2) {
    char s[10];
    scanf("%s", s);
    if (s[0] == '+') t[i] = true;
    else t[i] = false, scanf("%d", v + i);
  }
  int p = n;
  RF(i, n * 2, 1) {
    if (t[i]) {
      if (!top) {
        puts("NO");
        return 0;
      }
      res[p--] = stk[top--];
    }
    else {
      if (top && v[i] > stk[top]) {
        puts("NO");
        return 0;
      }
      stk[++top] = v[i];
    }
  }
  puts("YES");
  for (int i = 1; i <= n; ++i)
    printf("%d%c", res[i], " \n"[i == n]);
  return 0;
}