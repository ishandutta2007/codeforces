#include<bits/stdc++.h>
#define cmin(a,b) a=min(a,b)
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
const int N=2e6+50;
int n,m,tot=0,cur,num,top,zs;
int p[N][2],dfn[N],low[N],ins[N],f[N],bel[N],stk[N],pl[N];
struct Comb{int id,u,v,c,t;}h[N];
vector<int> vec[N],e[N];
bool cmp(const Comb &a,const Comb &b){return a.t<b.t;}
bool cmp2(const int &a,const int &b){return h[a].c<h[b].c;}
void build(int x,int l,int r,int tp)
{
	if(l==r) return ;
	int i,now,id;
	now=++tot;id=vec[x][l];e[now].pb(p[id][tp^1]);
	for(i=l+1;i<=r;i++)
	{
		id=vec[x][i];
		//if(tp==0) printf("id %d  %d\n",id,h[id].t);
		e[p[id][tp]].pb(now);
		tot++;e[tot].pb(now);
		e[tot].pb(p[id][tp^1]);
		now=tot;
	}
 
	now=++tot;id=vec[x][r];e[now].pb(p[id][tp^1]);
	for(i=r-1;i>=l;i--)
	{
		
		id=vec[x][i];
		
		e[p[id][tp]].pb(now);
		tot++;e[tot].pb(now);
		e[tot].pb(p[id][tp^1]);
		now=tot;
	}
}
void tarjan(int x)
{
	dfn[x]=low[x]=++cur;ins[x]=1;stk[++top]=x;
	for(int v:e[x])
	{
		//if(x==21) printf("edge%d %d\n",x,v);
		if(!dfn[v])
		{
			tarjan(v);cmin(low[x],low[v]);
		}
		else if(ins[v]) cmin(low[x],dfn[v]);
	}
	if(low[x]>=dfn[x])
	{
		zs++;
		while(true)
		{
			bel[stk[top]]=zs;
			ins[stk[top]]=0;
			top--;if(stk[top+1]==x) break;
		}
	}
}
int solve(int W,int tp)
{
	int i;
	for(i=1;i<=m;i++) if(f[i]) f[i]=0,e[p[i][1]].pop_back();
	for(i=1;i<=m;i++)
	{
		if(h[i].t>W) f[i]=1,e[p[i][1]].pb(p[i][0]);
	}
	
	cur=0;top=0;zs=0;
	memset(dfn,0,sizeof(dfn));
	for(i=1;i<=tot;i++)
	{
		if(dfn[i]) continue;
		tarjan(i);
	}
	for(i=1;i<=m;i++)
	{
		//printf("#%d  %d %d  %d %d\n",i,dfn[5],dfn[6],bel[5],bel[6]);
		if(bel[p[i][0]]==bel[p[i][1]]) return 0;
	}
	if(tp==0) return 1;
	
	num=0;
	for(i=1;i<=m;i++)
	{
		if(bel[p[i][0]]>bel[p[i][1]]) pl[++num]=h[i].id;
	}
	puts("Yes");
	printf("%d %d\n",W,num);
	sort(pl+1,pl+num+1);
	for(i=1;i<=num;i++) printf("%d ",pl[i]);
	return 1;
}
int main()
{
	int i,l,r,x,vsi,sl,sr,mid;
	n=rd();m=rd();
	for(i=1;i<=m;i++)
	{
		h[i].id=i;h[i].u=rd();h[i].v=rd();h[i].c=rd();h[i].t=rd();
	}
	sort(h+1,h+m+1,cmp);
	for(i=1;i<=m;i++) 
	{
		p[i][0]=++tot;p[i][1]=++tot;
		vec[h[i].u].pb(i);vec[h[i].v].pb(i);
	}
	
	for(x=1;x<=n;x++)
	{
		vsi=vec[x].size();
		if(vsi==0) continue;
		sort(vec[x].begin(),vec[x].end(),cmp2);
		build(x,0,vsi-1,1);
		for(l=0;l<vsi;l=r+1)
		{
			r=l;
			
			while(r<vsi-1&&h[vec[x][r+1]].c==h[vec[x][l]].c) r++;
			//printf("U%d  %d %d\n",x,l,r);
			build(x,l,r,0);
		}
		//puts("OK");
	}
	//cout<<"ans"<<solve(353409763,0)<<endl;
	//return 0;
	if(solve(h[m].t,0)==0) 
	{
		puts("No");return 0;
	}
	
	sl=0;sr=m;
	while(sl<sr)
	{
		mid=(sl+sr)>>1;
		//printf("S%d %d %d %d\n",sl,sr,h[mid].t,solve(5,0));
		if(solve(h[mid].t,0)==1) sr=mid;
		else sl=mid+1;
	}
	solve(h[sl].t,1);
	return 0;
}