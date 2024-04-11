//2016-06-17 12:44:07.518000
#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second
#define beyond(x, y) (x<0 || y<0 || x>=N || y>=M)

typedef long long INT;
typedef pair<int, int> pii;
#define NN 111111
#define MM 222222

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
vector<int> son[NN];
int anc[NN], vst[NN], cnt[NN];
INT dst[NN], best[NN], a[NN];
int qf, qb, q[1111111], qqf, qqb, qq[1111111];
int to[MM], next[MM], head[NN], wei[MM], E;

int make_edge(int u, int v, int c) {
	to[E]=v; wei[E]=c;
	next[E]=head[u];
	head[u]=E++;	
}

int main() {
	
	int n, i, j, u, uu, v, c, e;
	scanf("%d", &n);
	for (i=0; i<n; i++) scanf("%I64d", a+i);
	memset(head, -1, sizeof(head));
	E=0;
	
	for (i=0; i<n-1; i++) {
		scanf("%d%d", &u, &c);
		u--;
		make_edge(u, i+1, c);
		make_edge(i+1, u, c);
	}
	
	memset(vst, 0, sizeof(vst));
	for (i=0; i<n; i++) son[i].clear();
	memset(anc, -1, sizeof(anc));
	
	qf=qb=0;
	q[qb++]=0; dst[0]=0; vst[0]=1;
	while (qf<qb) {
		u=q[qf++];
		for (e=head[u]; e!=-1; e=next[e]) {
			v=to[e];
			if (vst[v]) continue;
			son[u].push_back(v);
			anc[v]=u;
			vst[v]=1;
			dst[v]=dst[u]+wei[e];
			q[qb++]=v;
		}
	}
	
	memset(cnt, 0, sizeof(cnt));
	for (i=qb-1; i>=0; i--) {
		u=q[i];
		cnt[u]=1;
		for (j=0; j<son[u].size(); j++) cnt[u]+=cnt[son[u][j]];
	}
	
	memset(best, 0x3f, sizeof(best));
	
	for (i=0; i<qb; i++) {
		u=q[i];
		best[u]=dst[u];
		if (anc[u]!=-1) best[u]=min(best[u], best[anc[u]]);
	}
	
	int res=0;
	
	memset(vst, 0, sizeof(vst));

	for (i=0; i<qb; i++) {
		u=q[i];
		if (vst[u]) continue;

		if (best[u]<dst[u]-a[u]) {
//			printf("%d\n", u+1);
			res+=cnt[u];
			qqf=qqb=0;
			qq[qqb++]=u; vst[u]=1;
			while (qqf<qqb) {
				uu=qq[qqf++];
				for (j=0; j<son[uu].size(); j++) {
					v=son[uu][j];
					vst[v]=1;
					qq[qqb++]=v;
				}
			}
		}
	}
	
	printf("%d\n", res);
	
	return 0; 
}