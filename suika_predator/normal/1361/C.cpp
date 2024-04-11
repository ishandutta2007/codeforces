#include<bits/stdc++.h>
using namespace std;
const int N=1111111;
const int M=1111111;
struct node
{
	int next,to;
} e[M<<1];
int head[N],cnt;
inline void add(int u,int v)
{
	++cnt;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int st;
int in[N];
int stk[M],top,vise[M];
inline int id(int x)
{
	return ((x+1)>>1);
}
inline void dfs(int x)
{
	for(int &i=head[x]; i; i=e[i].next)
	{
		int ct=id(i);
		if(vise[ct]) continue;
		vise[ct]=1;
		int tmp=i,v=e[i].to;
		dfs(v);
		stk[++top]=(tmp&1 ? ct:-ct);
	}
}
bool solve(int n,int m,int *a,int *b)
{
	memset(in,0,sizeof(in));
	memset(e,0,sizeof(e));
	memset(head,0,sizeof(head));
	memset(stk,0,sizeof(stk));
	memset(vise,0,sizeof(vise));
	cnt=0;st=0;top=0;
	for(int i=1; i<=m; i++)
	{
		int u=a[i],v=b[i];
		add(u,v),add(v,u),++in[u],++in[v];
		st=u;
	}
	for(int i=1;i<=n;i++)
	{
		if(in[i]&1)
		{
			return 0;
		}
	}
	dfs(st);
	if(top!=m)
	{
		return 0;
	}
	return 1;
}
int a[555555],b[555555],cc[555555],dd[555555];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int bb=20;bb>=0;bb--)
	{
		for(int i=1;i<=n;i++)cc[i]=(a[i]&((1<<bb)-1))+1,dd[i]=(b[i]&((1<<bb)-1))+1;
		if(solve(1<<bb,n,cc,dd))
		{
			cout<<bb<<endl;
			while(top)
			{
				int cur=stk[top--];
				if(cur>0)cout<<cur*2-1<<' '<<cur*2<<' ';
				else cout<<(-cur)*2<<' '<<(-cur)*2-1<<' ';
			}
			break;
		}
	}
	return 0;
}