#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long INT;

typedef priority_queue<pii, vector<pii>, greater<pii> > PQ;
PQ pq;

#define NN 222222
#define y second

int dst[NN], deg[NN], adj[NN][4];

int main() {
	
	int n, i, u, v;
	scanf("%d", &n);
	memset(deg, 0, sizeof(deg));
	
	for (i=0; i<n; i++) {
		scanf("%d", &u);
		u--;
		adj[i][deg[i]++]=u;
	}
	for (i=0; i<n; i++) {
		if (i) adj[i][deg[i]++]=i-1;
		if (i<n-1) adj[i][deg[i]++]=i+1; 
	}
	
	memset(dst, 0x3f, sizeof(dst));
	dst[0]=0;
	pq=PQ();
	pq.push(pii(dst[0], 0));
	while (!pq.empty()) {
		u=pq.top().y; pq.pop();
		for (i=0; i<deg[u]; i++) {
			v=adj[u][i];
			if (dst[v]>dst[u]+1) {
				dst[v]=dst[u]+1;
				pq.push(pii(dst[v], v));
			}
		}
	}
	
	for (i=0; i<n; i++) {
		if (i) printf(" ");
		printf("%d", dst[i]);
	}
	puts("");
	
	return 0;
}