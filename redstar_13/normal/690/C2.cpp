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

#define pb push_back
#define NN 111111
int qf, qb, q[1111111];
int vst[NN], best[NN], res[NN];
vector<int> adj[NN], cadj[NN];

void make_tree(int u) {
	int i, v, deg;
	qf=qb=0;
	q[qb++]=u;
	vst[u]=1;
	while (qf<qb) {
		u=q[qf++], deg=cadj[u].size();
		for (i=0; i<deg; i++) {
			v=cadj[u][i];
			if (vst[v]) continue;
			vst[v]=1;
			adj[u].pb(v);
			q[qb++]=v;
		}
	}
}

int main() {

	int N, M, u, v, i, j, mid, k, deg, a[4];
	scanf("%d%d", &N, &M);
	for (i=0; i<M; i++) {
		scanf("%d%d", &u, &v);
		u--, v--;
		cadj[u].pb(v);
		cadj[v].pb(u);
	}
	make_tree(0);
	
	qf=qb=0;
	q[qb++]=0;
	while (qf<qb) {
		u=q[qf++], deg=adj[u].size();
		for (i=0; i<deg; i++) {
			q[qb++]=adj[u][i];
		}
	}

	for (i=qb-1; i>=0; i--) {
		u=q[i], deg=adj[u].size();
		if (deg==0) {
			best[u]=0, res[u]=0;
			continue;
		}

		best[u]=res[u]=mid=k=0;
		for (j=0; j<deg; j++) {
			v=adj[u][j];
			res[u]=max(res[u], res[v]);
			mid=max(mid, best[v]);
			a[k++]=res[v];
			if (k>2) {
				if (a[0]<a[1]) swap(a[0], a[1]);
				if (a[0]<a[2]) swap(a[0], a[2]);
				if (a[1]<a[2]) swap(a[1], a[2]);
				k=2;
			}
		}

		res[u]++;
		best[u]=max(res[u], best[u]);
		best[u]=max(mid, best[u]);
		if (k==1) continue;
		best[u]=max(best[u], a[0]+a[1]+2);
	}

	printf("%d\n", best[0]);

	return 0;
}