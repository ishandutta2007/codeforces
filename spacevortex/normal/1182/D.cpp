#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+50;
int n,cnt=0,pos,A,B,C,pd,tot;
int he[N],det[N],ds[N],val[N],fa[N],bval[N],del[N];
vector<int> e[N],rub;
inline void dfs(int x,int nf)
{
	det[x]=det[nf]+1;
	fa[x]=nf;
	if(det[x]>det[pos]) pos=x;
	for(auto&vv:e[x])
	{
		if(vv==nf) continue;
		dfs(vv,x);
	}
}
inline void search(int x,int nf)
{
	det[x]=det[nf]+1;
	if(val[det[x]]>0&&val[det[x]]!=ds[x]) pd=0;
	val[det[x]]=ds[x];
	for(auto&vv:e[x])
	{
		if(vv==nf) continue;
		search(vv,x);
	}
}
inline void check(int rt)
{
	pd=1;
	memset(val,0,sizeof(val));
	search(rt,0);
	if(pd)
	{
		printf("%d",rt);
		exit(0);
	}
}
inline void rsearch(int x,int nf,int top)
{
	det[x]=det[nf]+1;
	if(det[x]>tot||bval[det[x]]!=ds[x]) 
	{
		if(!del[top]) del[top]=1,rub.pb(top);
	}
	for(auto&vv:e[x])
	{
		if(vv==nf) continue;
		rsearch(vv,x,top);
	}
}
inline void find(int x,int nf)
{
	if(ds[x]>2) return;
	if(ds[x]==1) 
	{
		printf("%d",x);
		exit(0);
	}
	for(auto&vv:e[x])
	{
		if(vv==nf) continue;
		find(vv,x);
	}
}
inline void rcheck(int rt)
{
	memset(det,0,sizeof(det));
	for(auto&vv:e[rt])
	{
		rsearch(vv,rt,vv);
	}
	if(rub.size()==1)
	{
		find(rub[0],rt);
	}
}
int main()
{
	//freopen("t.in","r",stdin);
	int i,uu,vv,mid;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&uu,&vv);
		ds[uu]++;ds[vv]++;
		e[uu].pb(vv);e[vv].pb(uu);
	}
	pos=0;dfs(1,0);A=pos;
	pos=0;dfs(A,0);B=pos;
	if(det[B]&1)
	{
		mid=(det[B]+det[A])>>1;
		C=B;
		while(det[C]>mid) 
		{
			bval[++tot]=ds[C];
			C=fa[C];
		}
		reverse(bval+1,bval+tot+1);
	}
	check(A);check(B);
	if(C>0)
	{
		check(C);
		rcheck(C);
	}
	puts("-1");
	return 0;
}