#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mkp make_pair
#define pb push_back
#define SP putchar(' ')
#define EL putchar('\n')

mt19937 rnd(chrono :: steady_clock :: now().time_since_epoch().count());
mt19937_64 rnd64(chrono :: steady_clock :: now().time_since_epoch().count()) ;

template<class T> inline void gi(T &x){
  char ch; x = 0;int f = 1;
  while(isspace(ch = getchar()));
  if(ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
  x *= f;
}
template<class T> inline void wi(T x){
  static char stk[128]; int top = 0;
  if(x == 0) putchar('0');
  if(x < 0) putchar('-'), x = -x;
  while(x) stk[++top] = x % 10, x /= 10;
  while(top) putchar(stk[top--] + '0');
}
template<class T, class ...Args>
inline void gi(T &x, Args&... args) {gi(x); gi(args...);}
template<class T, class ...Args>
inline void wi(T x, Args... args) {wi(x); SP; wi(args...);}
template<class T> void upmax(T &x, T y) {x = x > y ? x : y;}
template<class T> void upmin(T &x, T y) {x = x < y ? x : y;}

const int N = 5005;
char s[N], t[N];
int f[N][N];

int main() {
  int n, m;
  gi(n, m);
  scanf("%s%s", s + 1, t + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (s[i] == t[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 2);
      else f[i][j] = max({f[i - 1][j], f[i][j - 1], 1}) - 1;
    }
  int res = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      upmax(res, f[i][j]);
  wi(res), EL;
  return 0;
}