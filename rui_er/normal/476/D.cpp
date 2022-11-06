// LUOGU_RID: 90441093
// Problem: CF476D Dreamoon and Sets
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF476D
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

int n, k;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &k);
	printf("%d\n", k*(6*n-1));
	rep(i, 1, n) printf("%d %d %d %d\n", k*(6*i-5), k*(6*i-4), k*(6*i-3), k*(6*i-1));
	return 0;
}