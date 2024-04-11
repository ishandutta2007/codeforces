#include <bits/stdc++.h>



using namespace std;



#define MM 200



int n, m, vis[MM], flag, f, sta[MM],a[MM][MM], ans[MM], tot;

vector <int> adj[MM];





void dfs(int u, int s, int fa=-1)

{

	sta[u]=s; vis[u]=1;

	for (int i=0; i<adj[u].size(); i++){

		int v=adj[u][i]; 

		if (v==fa) continue;

		if(vis[v]){

			if (s^a[u][v]==sta[v]) {flag=1; return;}

			else continue;

		}

		dfs (v, !(s^a[u][v]), u);

	}

}

int main()

{

	int u, v, r;

//	freopen ("in.txt", "r", stdin);

	scanf ("%d%d", &n, &m);

	for (int i=0; i<m; i++){

		scanf ("%d%d%d", &u, &v, &r);

		adj[u].push_back(v);  

		adj[v].push_back(u);

		a[u][v]=a[v][u]=r;

	}

	for (int i=1; i<=n; i++){

		if(vis[i]) continue;

		memset (sta, -1, sizeof(sta));

		flag=0;  f=0; dfs (i, 0);

		if(!flag) {

			for (int i=1; i<=n; i++) if(vis[i] && sta[i]==1) ans[tot++]=i;

		    continue;

		}

		flag=0;

		dfs(i, 1);

		if(!flag){

			for (int i=1; i<=n; i++) if(vis[i] && sta[i]==1) ans[tot++]=i;

		    continue;

		}

		if(flag) {puts("Impossible"); return 0;}

	}

	cout<<tot<<endl;

	for (int i=0; i<tot; i++) cout<<ans[i]<<" "; cout<<endl;

	return 0;

}