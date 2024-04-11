#include<bits/stdc++.h>



#define NN 200011

using namespace std;

typedef pair<int, int> pii;



int adj[NN][30], deg[NN], V[NN], ans[NN], ok, cnt=3;

map<pii, int> vst;



void dfs(int u, int fa1){

	

	int vv=0;

	for(int i=0; i<4; i++){

		int v=adj[u][i];

		if(V[v]) continue;

//		cout<<v<<' '<<fa1<<' '<<fa2<<endl;

		if(vst[pii(v, fa1)]) {

			V[v]=1;

			ans[cnt++]=v;

			dfs(v, u);

		}

	}

}



int main(){

	int n,m,i,j;

	

	cin>>n;

	

	for(i=0; i<2*n; i++){

		int u, v;

		scanf("%d%d", &u, &v);

		adj[u][deg[u]++]=v;

		adj[v][deg[v]++]=u;

		if(deg[u]>4 || deg[v]>4) {puts("-1"); return 0;} 

		vst[pii(u, v)]=1;

		vst[pii(v, u)]=1;

//		cout<<u<<' '<<v<<' '<<vst[pii(u, v)]<<' '<<vst[pii(v, u)]<<endl;

	}

	int uu, vv, flag=0;

	

	for(i=1; i<=n; i++) adj[i][4]=i;

	

	for(i=0; i<4; i++){

		int cnt=0;

		int u=adj[1][i];

		for(j=0; j<5; j++){

			for(int p=0; p<5; p++){

				if(adj[1][p]==adj[u][j]) cnt++;

			}

		}

		if(cnt>=4 && flag) {uu=u; break;}

		if(cnt>=4 && flag==0) vv=u, flag=1;

	}

	

	ans[0]=vv, ans[1]=1, ans[2]=uu;

	V[1]=V[vv]=V[uu]=1;

	dfs(uu, 1);

	if(cnt!=n) puts("-1");

	else for(i=0; i<n; i++) printf("%d ", ans[i]);

	puts("");

	

	return 0;

	

	

}