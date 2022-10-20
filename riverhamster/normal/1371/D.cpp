// Codeforces contest template
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

const int N = 305;
int a[N][N];

int main(){
	// File("d");
  int T;
  gi(T);
  while(T--){
    int n, k;
    gi(n); gi(k);
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        a[i][j] = 0;
    int x = 0, y = 0;
    if(k % n == 0) puts("0");
    else puts("2");
    for(int i=0; i<k; i++){
      a[x][y] = true;
      x = (x + 1) % n; y = (y + 1) % n;
      if(x == 0) ++y;
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++) wi(a[i][j]);
      EL;
    }
  }
	return 0;
}