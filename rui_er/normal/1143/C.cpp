// Problem: CF1143C Queen
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1143C
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
const int N = 1e5+5;

int n, p[N], c[N], tp[N], ok;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) tp[i] = 1;
	rep(i, 1, n) {
		scanf("%d%d", &p[i], &c[i]);
		tp[i] &= c[i];
		if(p[i] > -1) tp[p[i]] &= c[i];
	}
	rep(i, 1, n) {
		if(tp[i]) {
			printf("%d ", i);
			ok = 1;
		}
	}
	if(!ok) puts("-1");
	return 0;
}