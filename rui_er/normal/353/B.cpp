//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 205; 

int n, a[N], buc[N], vis[N], ans[N], tA, tB, tC;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n); n <<= 1;
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		++buc[a[i]];
	}
	rep(i, 1, n) {
		if(buc[a[i]] == 1) {
			if(tA < tB) {ans[i] = 1; ++tA;}
			else {ans[i] = 2; ++tB;}
		}
		else {
			if(!vis[a[i]]) {ans[i] = 1; ++vis[a[i]]; ++tC;}
			else if(vis[a[i]] == 1) {ans[i] = 2; ++vis[a[i]];}
		}
	}
	tA += tC; tB += tC;
	printf("%d\n", tA*tB);
	rep(i, 1, n) {
		if(buc[a[i]] > 2 && !ans[i]) {
			if(tA < (n >> 1)) {ans[i] = 1; ++tA;}
			else {ans[i] = 2; ++tB;}
		}
	}
	rep(i, 1, n) printf("%d%c", ans[i], " \n"[i==n]);
	return 0;
}