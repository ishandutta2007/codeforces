#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int L[233333],R[233333],deg[233333],dep[233333],del[233333];
queue<int> q;
inline void upd(int u)
{
	deg[L[u]]--;
	if(deg[L[u]]==0)q.push(L[u]);
	deg[R[u]]--;
	if(deg[R[u]]==0)q.push(R[u]);
}
inline void fuck(int u)
{
	del[u]=1;
	if(deg[L[u]]==1)del[L[u]]=0;
	if(deg[R[u]]==1)del[R[u]]=0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		n++;
		for(int i=1;i<=n;i++)L[i]=R[i]=dep[i]=deg[i]=del[i]=0;
		int x,y;
		for(int i=1;i<=m;i++)
		{
			cin>>x>>y;
			if(L[x])R[x]=y;
			else L[x]=y;
			deg[y]++;
		}
		for(int i=1;i<n;i++)
		{
			if(!L[i])L[i]=n;
			if(!R[i])R[i]=n;
			if(!deg[i])q.push(i);
		}
		L[n]=R[n]=n;
		deg[n]+=2;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			upd(u);
			if(dep[u]==2)del[u]=1;
			else
			{
				dep[L[u]]=max(dep[L[u]],dep[u]+1);
				dep[R[u]]=max(dep[R[u]],dep[u]+1);
			}
		}
		int cnt=0;
		for(int i=1;i<n;i++)
		{
			if(del[i]==1)cnt++;
		}
		cout<<cnt<<endl;
		for(int i=1;i<n;i++)
		{
			if(del[i]==1)cout<<i<<' ';
		}
		cout<<endl;
	}
	return 0;
}