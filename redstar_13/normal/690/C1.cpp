#include <bits/stdc++.h>

#define eps 1e-7
#define sq(x) ((x)*(x))
#define x1 kakaskakas
#define x2 jmjjmjjmjj
#define y1 spiderspid
#define y2 likolikoli
#define inf 0x3f3f3f3f
using namespace std;

template<class T> inline void smin(T &a, T b) {if(a>b) a=b;}
template<class T> inline void smax(T &a, T b) {if(a<b) a=b;}

#define NN 1111
int adj[NN][NN], vst[NN], deg[NN];
int qf, qb, q[111111];

int main() {
	int N, M, i, j, u, v;
	scanf("%d%d", &N, &M);
	if (M!=N-1) {
		puts("no");
		return 0;
	}
	for (i=0; i<M; i++) {
		scanf("%d%d", &u, &v);
		u--, v--;
		adj[u][deg[u]++]=v;
		adj[v][deg[v]++]=u;
	}
	qf=qb=0;
	q[qb++]=0;
	vst[0]=1;
	while (qf<qb) {
		u=q[qf++];
		for (i=0; i<deg[u]; i++) {
			v=adj[u][i];
			if (vst[v]) continue;
			q[qb++]=v;
			vst[v]=1;
		}
	}
	if (qb!=N) puts("no");
	else puts("yes");

	return 0;
}