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
vector<int> G[N];

pair<int, int> far(int x, int fa) {
  pii res = {0, x};
  for(int v : G[x]){
    if(v == fa) continue;
    pii f = far(v, x);
    ++f.first;
    res = max(res, f);
  }
  return res;
}
int dist(int x, int y, int fa){
  if(x == y) return 0;
  for(int v : G[x]){
    if(v == fa) continue;
    int d = dist(v, y, x);
    if(d != -1) return d + 1;
  }
  return -1;
}

int main(){
  // File("b");
	int T;
  gi(T);
  while(T--){
    int n, a, b, da, db;
    gi(n); gi(a); gi(b); gi(da); gi(db);
    for(int i=1; i<=n; i++)
      G[i].clear();
    for(int i=1; i<n; i++){
      int x, y;
      gi(x); gi(y);
      G[x].push_back(y); G[y].push_back(x);
    }
    int x = far(1, 1).second;
    int d = far(x, x).first;
    da = min(da, d);
    db = min(db, d);
    if(da * 2 < db && dist(a, b, a) > da) puts("Bob");
    else puts("Alice");
  }
	return 0;
}