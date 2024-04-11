#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

typedef pair<pii, int> pi3;

#define NN 303030

pi3 p[NN];
int x[NN], y[NN];
INT dpx[NN], dpy[NN], ans[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		scanf("%d %d", x+i, y+i);
		p[i]=pi3(pii(x[i], y[i]), i);
	}
	sort(p+1, p+n+1, [](pi3 a, pi3 b) {
		return a.x.x-a.x.y<b.x.x-b.x.y;
	});
	
	for(int i=1; i<=n; i++) {
		dpx[i]=dpx[i-1]+p[i].x.x;
		dpy[i]=dpy[i-1]+p[i].x.y;
	}
	
	for(int i=1; i<=n; i++) {
		int X=p[i].x.x, Y=p[i].x.y, id=p[i].y;
		ans[id]=dpx[i-1]+(INT)(i-1)*Y;
		ans[id]+=(INT)(n-i)*X+dpy[n]-dpy[i];
	}
	while(m--) {
		int u, v; scanf("%d %d", &u, &v);
		int mn=min(x[u]+y[v], x[v]+y[u]);
		ans[u]-=mn, ans[v]-=mn;
	}
	
	for(int i=1; i<=n; i++) printf("%I64d ", ans[i]);
}