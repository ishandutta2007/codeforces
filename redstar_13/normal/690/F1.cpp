#include <bits/stdc++.h>
#define rep(i, a, b) for(i=(a); i<(b); i++)
using namespace std;
template <class T> inline void smin(T &a, T b) {if(a>b)a=b;}
template <class T> inline void smax(T &a, T b) {if(a<b)a=b;}
#define NN 11111
int deg[NN];

int main() {
	int i, n, u, v;
	scanf("%d", &n);
	memset(deg, 0, sizeof(deg));
	rep(i, 0, n-1) {
		scanf("%d%d", &u, &v);
		u--; v--;
		deg[u]++; deg[v]++;
	}
	int ans=0;
	rep(i, 0, n) {
		if(deg[i]<2) continue;
		ans+=deg[i]*(deg[i]-1)/2;
	}
	printf("%d\n", ans);

	return 0;
}