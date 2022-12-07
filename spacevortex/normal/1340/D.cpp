#include<bits/stdc++.h>
#define pb push_back

using namespace std;
int rd()
{
	int rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const int N=1e6+50;
int n,D,num=0;
int pt[N],pv[N],ds[N];
vector<int> e[N];
void add(int t,int x)
{
	num++;pt[num]=t;pv[num]=x;
	//printf("%d %d\n",x,t);
}
void dfs(int x,int nf,int bt)
{
	int nt,nd,pos;
	//printf("P%d\n",x);
	nt=bt;
	nd=0;
	for(int v:e[x])
	{
		if(v==nf) continue;
		if(nt<D)
		{
			add(nt,x);
			dfs(v,x,nt+1);
			nt++;nd++;
		}
		else
		{
			add(nt,x);
			pos=bt-1-(ds[x]-1-nd);
			nt=pos;
			add(nt,x);
			dfs(v,x,nt+1);
			nt++;
		}
	}
	if(nt>=bt) add(nt,x);
	add(bt-1,x);
}
int main()
{
	int i,u,v,w;
	n=rd();
	for(i=1;i<n;i++)
	{
		u=rd();v=rd();
		e[u].pb(v);e[v].pb(u);
		ds[u]++;ds[v]++;
	}
	D=ds[1]+1;
	for(i=2;i<=n;i++) D=max(D,(ds[i]-1)+2);
	//printf("D%d\n",D);
	w=1;
	for(int v:e[1])
	{
		add(w,1);
		dfs(v,1,w+1);
		w++;
	}
	add(w,1);
	printf("%d\n",num);
	for(i=1;i<=num;i++) printf("%d %d\n",pv[i],pt[i]-1);
	return 0;
}