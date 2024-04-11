// LUOGU_RID: 96685545
// monisai 0728 T1
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

int p, y;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool check(int x) {
	if(x < 2) return 0;
	for(int i=2;i<=p&&1LL*i*i<=x;i++) if(!(x % i)) return 0;
	return 1;
}

int main() {
	scanf("%d%d", &p, &y);
	per(i, y, max(y-30000, p+1)) if(check(i)) return printf("%d\n", i)&0;
	puts("-1");
	return 0;
}