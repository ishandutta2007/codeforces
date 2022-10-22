#include<bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int d[100100],s,h,q[100100],n,m,a,b;
void bfs()
{
	while (s != h)
	{
		int u=q[s++];
		for (int i=0; i<g[u].size(); i++) if (d[g[u][i]]>d[u]+1) d[g[u][i]]=d[u]+1,q[h++] = g[u][i];
	}
	s = 0,h = 0;
}
main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=0; i<n-1;++i) cin>>a>>b,g[a-1].push_back(b-1),g[b-1].push_back(a-1),d[a]=1<<30,d[b]=1<<30;
	q[h++] = 0,d[0]=0,bfs();
	while (m--)
	{
		int t,v;
		cin>>t>>v;
		if (t==1) d[v-1]=0,q[h++] = v-1; else bfs(),cout<<d[v-1]<<'\n';
	}
}