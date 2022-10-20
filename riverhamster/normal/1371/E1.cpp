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

const int N = 100005;
int n, p;
int a[N];
int res[N * 2], rc = 0;

bool check(int x){
  int res = 1;
  for(int i=0; i<n; i++){
    int cnt = x + n - a[i];
    upmin(cnt, n);
    cnt -= i;
    if(cnt <= 0) return false;
    res = (1LL * res * cnt) % p;
  }
  return res != 0;
}

int main(){
	// File("e1");
  gi(n); gi(p);
  for(int i=0; i<n; i++) gi(a[i]);
  sort(a, a + n, greater<int>());
  for(int x=0; x<=2000; x++)
    if(check(x)) res[++rc] = x;
  wi(rc); EL;
  for(int i=1; i<=rc; i++) wi(res[i]), SP;
  EL;
	return 0;
}