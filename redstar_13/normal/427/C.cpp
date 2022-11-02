#include <bits/stdc++.h>



using namespace std;

typedef long long INT;

#define MM 100010

#define NN 300010

#define mod 1000000007

int dfn[MM], low[MM], st[NN], bel[MM], ins[MM];

vector<int> adj[MM], vec[MM];

int n, m;

int ind, top, cnt, pre[NN];

INT ans=1LL, mn[MM], sum, a[MM];

void Tarjan(int u) //strongly connected component

{

	dfn[u]=low[u]=++ind;

	st[++top]=u;

	ins[u]=1;

	for(int i=0; i<adj[u].size(); i++){

		int v=adj[u][i];

		if(!dfn[v])Tarjan(v),low[u]=min(low[u],low[v]);

		else  if(ins[v]) low[u]=min(low[u],low[v]);

	}

	if(dfn[u]==low[u]){

		++cnt;

		while(1){

			bel[st[top]]=cnt;

			vec[cnt].push_back(st[top]);

			ins[st[top]]=0;

			if(st[top--]==u)break;

		}

	}

}

int main()

{

	int u, v;

//	freopen ("in.txt", "r", stdin);

	scanf ("%d", &n);

	for (int i=1; i<=n; i++){

		scanf ("%I64d", a+i);

	}

	scanf ("%d", &m);

	for (int i=0; i<m; i++){

		scanf ("%d%d", &u, &v);

		adj[u].push_back(v);

	}

	for (int i=1; i<=n; i++){

		if (dfn[i]) continue;

		ind=0; top=0;

		Tarjan(i);

	}

	for (int i=1; i<=cnt; i++) mn[i]=mod;

	for (int i=1; i<=cnt; i++){

		for (int j=0; j<vec[i].size(); j++){

			int v=vec[i][j];

			mn[i] = min(mn[i], a[v]);

		}

	}

	for (int i=1; i<=cnt; i++){

		for (int j=0; j<vec[i].size(); j++){

			int v=vec[i][j];

			if (a[v]== mn[i]) pre[i]++;

		}

	}

	for (int i=1; i<=cnt; i++) sum+=mn[i];

	for (int i=1; i<=cnt; i++) ans=ans*pre[i]*1LL, ans%=mod;

	printf("%I64d %I64d\n",sum, ans);

	return 0;

}