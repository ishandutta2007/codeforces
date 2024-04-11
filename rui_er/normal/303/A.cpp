//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5; 

int n;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	if(!(n & 1)) return puts("-1")&0;
	rep(i, 0, n-1) printf("%d%c", i, " \n"[i==n-1]);
	rep(i, 0, n-1) printf("%d%c", i, " \n"[i==n-1]);
	rep(i, 0, n-1) printf("%d%c", 2*i%n, " \n"[i==n-1]);
	return 0;
}