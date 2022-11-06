//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e3+5; 

int n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	int L = 0, R = 0;
	rep(i, 1, n) {
		if(a[i] != i) {
			if(!L) L = i;
			R = i;
		}
	}
	if(!L && !R) return puts("0 0")&0;
	reverse(a+L, a+1+R);
	rep(i, 1, n) {
		if(a[i] != i) return puts("0 0")&0;
	}
	printf("%d %d\n", L, R);
	return 0;
}