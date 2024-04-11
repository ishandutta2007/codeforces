#include <bits/stdc++.h>
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
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

const int N = 200005;
char s[N];
int f[N][4];

int main(){
  // File("d");
  int T;
  gi(T);
  while(T--){
    int n;
    gi(n);
    scanf("%s", s);
    for(int i=0; i<n; i++)
      if(s[i] == 'L') s[i] = 0;
      else s[i] = 1;
    int res = 0x7fffffff;
    for(int i=0; i<2; i++)
      for(int j=0; j<2; j++){
        // printf("%d %d\n", i, j);
        int now = (i ^ s[0]) + (j ^ s[1]);
        for(int k=1; k<n; k++)
          f[k][0] = f[k][1] = f[k][2] = f[k][3] = 0x3fffffff;
        f[1][(i << 1) | j] = now;
        for(int k=1; k<n-1; k++){
          for(int p=0; p<4; p++){
            for(int nxt=0; nxt<2; nxt++){
              int q = ((p << 1) | nxt) & 3;
              if(p == 0 && q == 0) continue;
              if(p == 3 && q == 3) continue;
              upmin(f[k + 1][q], f[k][p] + (s[k + 1] ^ nxt));
            }
          }
        }
        for(int k=0; k<4; k++){
          if(i == 0 && j == 0 && (k & 1) == 0) continue;
          if(i == 1 && j == 1 && (k & 1) == 1) continue;
          if(i == 0 && k == 0) continue;
          if(i == 1 && k == 3) continue;
          // printf("f[%d] = %d\n", k, f[n - 1][k]);
          upmin(res, f[n - 1][k]);
        }
      }
    printf("%d\n", res);
  }
  return 0;
}