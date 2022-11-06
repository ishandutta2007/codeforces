//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e3+5; 

int n, k, a[N];
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%s", &k, s+1);
	n = strlen(s+1);
	rep(i, 1, n) ++a[s[i]-'a'];
	int ok = 1;
	rep(i, 0, 25) ok &= !(a[i] % k);
	if(!ok) return puts("-1")&0;
	rep(i, 1, k) rep(j, 0, 25) rep(_, 1, a[j]/k) putchar('a'+j);
	return 0;
}