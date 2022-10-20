#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#else
#define File(s)
#endif

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

const int N = 105;
char a[N][N];
int c;
array<int, 6> op[N * N];

void s2(int x, int y) {
  int xs = 0;
  for (int i : {0, 1})
    for (int j : {0, 1})
      xs ^= (a[x + i][y + j] - '0');
  for (int i : {0, 1})
    for (int j : {0, 1})
      a[x + i][y + j] ^= xs;
  if (a[x][y] == '1') op[++c] = {x + 1, y, x, y + 1, x + 1, y + 1};
  if (a[x + 1][y] == '1') op[++c] = {x, y, x, y + 1, x + 1, y + 1};
  if (a[x][y + 1] == '1') op[++c] = {x, y, x + 1, y, x + 1, y + 1};
  if (a[x + 1][y + 1] == '1') op[++c] = {x, y, x + 1, y, x, y + 1};
}
void work() {
  c = 0;
  int n, m;
  gi(n, m);
  for (int i = 1; i <= n; ++i)
    scanf("%s", a[i] + 1);
  if (n % 2 == 1) {
    for (int i = 1; i <= m; ++i) {
      if (a[n][i] == '0') continue;
      a[n][i] = '0';
      a[n - 1][i] ^= 1; a[n - 1][i == m ? i - 1 : i + 1] ^= 1;
      op[++c] = {n, i, n - 1, i, n - 1, i == m ? i - 1 : i + 1};
    }
    --n;
  }
  if (m % 2 == 1) {
    for (int i = 1; i <= n; ++i) {
      if (a[i][m] == '0') continue;
      a[i][m] = '0';
      a[i][m - 1] ^= 1; a[i == 1 ? i + 1 : i - 1][m - 1] ^= 1;
      op[++c] = {i, m, i, m - 1, i == 1 ? i + 1 : i - 1, m - 1};
    }
    --m;
  }
  for (int i = 1; i < n; i += 2)
    for (int j = 1; j < m; j += 2)
      s2(i, j);
  wi(c), EL;
  for (int i = 1; i <= c; ++i) {
    for (int j = 0; j < 6; ++j)
      wi(op[i][j]), SP;
    EL;
  }
}

int main(){
  // File("a");
  int T;
  gi(T);
  while (T--) work();
  return 0;
}