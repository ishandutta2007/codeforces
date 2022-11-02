#include <bits/stdc++.h>



using namespace std;

#define MM 100010

typedef pair <int, int>pii;



int  n, vis[MM], ans[MM], cnt;

vector <int> adj[MM];

map<pii, int>mp;



void dfs(int u, int fa=0)

{

	for (int i=0; i<adj[u].size(); i++){

		int v=adj[u][i];

		if (v==fa) continue;

		if(mp[pii(u, v)]==2 || mp[pii(v, u)]==2) vis[v]=1, vis[u]=0;

		dfs (v, u);

	}

}

int re_dfs(int u, int fa=0)

{

	bool flag=0;

	for (int i=0; i<adj[u].size(); i++){

		int v=adj[u][i];

		if (v==fa) continue;

		if (re_dfs(v, u)){ 

			vis[u]=0, flag=1;	

		}

	}

	if(flag || vis[u]==1) return 1;

	else return 0;

}

int main()

{

	int u, v, t;

//	freopen ("in.txt", "r", stdin);

	scanf ("%d", &n); mp.clear();

	for (int i=0; i<n-1; i++){

		scanf ("%d%d%d", &u, &v, &t);

		adj[u].push_back(v);

		adj[v].push_back(u);

		mp[pii(u, v)]=mp[pii(v, u)]=t;

	}

	dfs(1);  re_dfs(1);

	for (int i=1; i<=n; i++) 

		if(vis[i]) ans[cnt++]=i;

	cout<<cnt<<endl;

	for (int i=0; i<cnt; i++) cout<<ans[i]<<" "; cout<<endl;

	return 0;

}