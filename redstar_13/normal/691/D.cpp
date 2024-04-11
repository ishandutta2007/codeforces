#include <bits/stdc++.h>

using namespace std;
#define NN 1111111
vector<int> adj[NN];
int vst[NN], p[NN], val[NN], pp[NN];
int qf, qb, q[NN];

int main() {
	
	int n, m, i, u, v, j, deg;
	
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++) {
		scanf("%d", p+i); p[i]--;
		adj[i].clear();
	}
	
	for (i=0; i<m; i++) {
		scanf("%d%d", &u, &v);
		u--; v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	
	memset(vst, 0, sizeof(vst));
	
	for (i=0; i<n; i++) {
		if (vst[i]) continue;
		qf=qb=0;
		q[qb++]=i; vst[i]=1;
		while (qf<qb) {
			u=q[qf++];
			for (j=0, deg=adj[u].size(); j<deg; j++) {
				v=adj[u][j];
				if (vst[v]) continue;
				vst[v]=1; q[qb++]=v;
			}
		}
		
		for (j=0; j<qb; j++) {
			pp[j]=q[j]; val[j]=p[q[j]];
		}
	
		sort(pp, pp+qb); sort(val, val+qb);
		reverse(val, val+qb);
		for (j=0; j<qb; j++) p[pp[j]]=val[j];
	}
	
	for (i=0; i<n; i++) {
		if (i) printf(" ");
		printf("%d", p[i]+1);
	}
	
	
	return 0; 
}