#include<bits/stdc++.h>



#define NN 100011

using namespace std;

typedef pair<int, int> pii;



vector<int> adj[NN];

int vst[NN], ans[NN], id=1, pos, cnt, k;



void dfs(int u, int fa=0){

	

	ans[id++]=u;

//	cout<<u<<' '<<vst[u]<<endl;

	for(int i=0; i<adj[u].size(); i++){

		int v=adj[u][i];

		if(vst[v] ) {

			if(id-vst[v]>k) { pos=vst[v]; cnt=id-vst[v]; return ;}

			else continue;

		}

		vst[v]=id;

		dfs(v, u);

		break;

	}

}



int main(){

	

	int n,m,i,j;

	cin>>n>>m>>k;

	

	for(i=0; i<m; i++){

		int u, v;

		scanf("%d%d", &u, &v);

		adj[u].push_back(v);

		adj[v].push_back(u);

	}

	vst[1]=1;

	dfs(1); 

	

	printf("%d\n", cnt);

	for(i=pos; i<pos+cnt; i++) printf("%d ", ans[i]);

	return 0;

	

	

}