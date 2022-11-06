//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 2e5+5; 

int n, m, q, a[N], ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &m);
	ans = n;
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		if(u > v) swap(u, v);
		if(!a[u]++) --ans;
	}
	for(scanf("%d", &q);q;q--) {
		int op, x, y;
		scanf("%d", &op);
		switch(op) {
			case 1: {
				scanf("%d%d", &x, &y);
				if(x > y) swap(x, y);
				if(!a[x]++) --ans;
				break;
			}
			case 2: {
				scanf("%d%d", &x, &y);
				if(x > y) swap(x, y);
				if(!--a[x]) ++ans;
				break;
			}
			default:{
				printf("%d\n", ans);
				break;
			}
		}
	}
	return 0;
}