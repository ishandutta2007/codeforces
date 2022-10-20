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

struct Val{
  ll v;
  int id;
  bool operator<(Val rhs) {return v < rhs.v;}
};

int main(){
  setbuf(stdout, NULL);
  Val a[3];
  for(int i=0; i<3; i++)
    scanf("%lld", &a[i].v), a[i].id = i + 1;
  puts("First");
  puts("1000000000");
  int id = 0;
  scanf("%d", &id);
  a[id - 1].v += 1000000000;
  sort(a, a + 3);
  printf("%lld\n", 1LL * 2 * a[2].v - a[0].v - a[1].v);
  scanf("%d", &id);
  if(id == 0) return 0;
  ll val = 1LL * 2 * a[2].v - a[0].v - a[1].v;
  for(int i=0; i<3; i++)
    if(a[i].id == id)
      a[i].v += val;
  sort(a, a + 3);
  printf("%lld\n", a[1].v - a[0].v);
	return 0;
}