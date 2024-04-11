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

const int N = 200005;
int a[N], c[N * 32][2], id[N * 32], s[N * 32], nc = 0;

void insert(int v) {
  int x = 0;
  for (int i = 29; i >= 0; --i) {
    int d = (v >> i) & 1;
    if (!c[x][d]) c[x][d] = ++nc;
    x = c[x][d];
  }
}
int dfs(int x) {
  if (!c[x][0] && !c[x][1]) return 1;
  if (!c[x][0] || !c[x][1]) return dfs(c[x][0] | c[x][1]);
  return max(dfs(c[x][0]), dfs(c[x][1])) + 1;
}

int main() {
  int n;
  gi(n);
  for (int i = 1; i <= n; ++i) {
    int x;
    gi(x);
    insert(x);
  }
  wi(n - dfs(0)), EL;
  return 0;
}