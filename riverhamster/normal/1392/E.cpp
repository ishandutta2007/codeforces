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

const int N = 30;
ll a[N][N];

int main(){
  // File("e");
  int n;
  gi(n);
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++){
      if(i == n - 1 && j == n - 1) continue;
      if(i == 0 && j == 0) continue;
      int step = i + j - 1;
      if(i & 1) a[i][j] = 1LL << step;
      else a[i][j] = 0;
    }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      wi(a[i][j]), SP;
    EL;
  }
  fflush(stdout);
  int q;
  gi(q);
  while(q--){
    ll s;
    gi(s);
    int x = 0, y = 0, pre = 0;
    wi(1); SP; wi(1); EL;
    for(ll i=0; i<2*n-3; i++){
      int val = (s >> i) & 1;
      if(val == pre) ++y;
      else ++x;
      wi(x + 1); SP; wi(y + 1); EL;
      pre = val;
    }
    wi(n); SP; wi(n); EL;
    fflush(stdout);
  }
  return 0;
}