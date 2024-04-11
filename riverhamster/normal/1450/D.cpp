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

const int N = 300005;
int a[N];
vector<int> pos[N];
char res[N];

bool isp(int l, int r, int mx) {
  vector<int> A(a + l, a + r + 1);
  sort(A.begin(), A.end());
  int M = *max_element(A.begin(), A.end());
  if (M > mx) return false;
  return unique(A.begin(), A.end()) == A.end();
}

int main(){
  int T;
  gi(T);
  while (T--) {
    int n;
    gi(n);
    for (int i = 1; i<= n; ++i) pos[i].clear();
    for (int i = 1; i <= n; ++i) gi(a[i]), pos[a[i]].pb(i);
    res[n] = *min_element(a + 1, a + 1 + n) == 1 ? '1' : '0';
    res[1] = isp(1, n, n) + '0';
    int l = 1, r = n;
    for (int i = 1; i <= n; ++i) {
      if (pos[i].size() == 0) {
        for (int j = n - i + 1; j >= 2; --j) res[j] = '0';
        break;
      }
      res[n - i + 1] = '1';
      if (pos[i].size() > 1 || (pos[i][0] != l && pos[i][0] != r)) {
        for (int j = n - i; j >= 2; --j) res[j] = '0';
        break;
      }
      if (pos[i][0] == l) ++l;
      else --r;
    }
    res[n + 1] = 0;
    puts(res + 1);
  }
  return 0;
}