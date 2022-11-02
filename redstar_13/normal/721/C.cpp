
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

typedef pair<int, int> pii;
typedef pair<int, pii> pi3;

typedef long long INT;

template <class T> inline void smin(T &a, T b) {if (a>b) a=b;}
template <class T> inline void smax(T &a, T b) {if (a<b) a=b;}
priority_queue<pi3, vector<pi3>, greater<pi3> > pq;

#define NN 5010

int dst[NN][NN];
int pre[NN][NN];
int head[NN], nxt[NN], to[NN], wei[NN], E;
int res[NN];

int make_edge(int u, int v, int w) {
	to[E]=v; wei[E]=w;
	nxt[E]=head[u]; head[u]=E++;
}
int main() {
	
	int N, M, T, i, u, v, t, e, cnt, uu, ccc, nr;
	
	scanf("%d%d%d", &N, &M, &T);

	memset(head, -1, sizeof(head));
	
	for (i=0; i<M; i++) {
		scanf("%d%d%d", &u, &v, &t); u--; v--;
		make_edge(u, v, t);
	}
	
	memset(dst, 0x3f, sizeof(dst));
	
	dst[0][1]=0;
	pq.push(pi3(dst[0][1], pii(0, 1)));
	
	while (!pq.empty()) {
		u=pq.top().y.x; cnt=pq.top().y.y; pq.pop();
		if (dst[u][cnt]>T) continue;
		
		for (e=head[u]; e!=-1; e=nxt[e]) {
			v=to[e];
			if (dst[v][cnt+1]>dst[u][cnt]+wei[e]) {
				dst[v][cnt+1]=dst[u][cnt]+wei[e];
				pq.push(pi3(dst[v][cnt+1], pii(v, cnt+1)));
				pre[v][cnt+1]=u;
			}
		}
	}
	
	for (i=N; i>=0; i--) {
		if (dst[N-1][i]<=T) break;
	}
	
	printf("%d\n", i);
	
	u=N-1; cnt=i;
	nr=0;
	while (1) {
		res[nr++]=u;
		if (u==0) break;
		uu=pre[u][cnt]; ccc=cnt-1;
		u=uu; cnt=ccc;
	}
	
	reverse(res, res+nr);
	for (i=0; i<nr; i++) printf("%d ", res[i]+1);
	puts("");
	
	return 0;
}