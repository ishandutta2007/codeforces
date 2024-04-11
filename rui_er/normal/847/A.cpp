//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 105; 

int n, l[N], r[N], lm[N], rm[N], tot, vis[N];
int* L[N];
int* R[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d", &l[i], &r[i]);
	rep(i, 1, n) if(!vis[i]) {
		vis[i] = 1;
		int u = i;
		while(l[u]) vis[u=l[u]] = 1;
		L[++tot] = &l[u];
		lm[tot] = u;
		u = i;
		while(r[u]) vis[u=r[u]] = 1;
		R[tot] = &r[u];
		rm[tot] = u;
	}
	rep(i, 2, tot) {
		*R[i-1] = lm[i];
		*L[i] = rm[i-1];
	}
	rep(i, 1, n) printf("%d %d\n", l[i], r[i]);
	return 0;
}