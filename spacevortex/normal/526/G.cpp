#include<bits/stdc++.h>
#define cmax(a,b) a=max(a,b)
using namespace std;
const int N=1e5+50,E=N<<1,Log=18;
int n,Q,cnt=1,pos,A,B;
int he[N],dis[N];
struct Edge{int v,w,nxt;}e[E];
void eadd(int u,int v,int w)
{
	cnt++;e[cnt].v=v;e[cnt].w=w;e[cnt].nxt=he[u];he[u]=cnt;
}
void dfs(int x,int nf)
{
	if(dis[x]>dis[pos]) pos=x;
	int i,v,w;
	for(i=he[x];i;i=e[i].nxt)
	{
		v=e[i].v;w=e[i].w;
		if(v==nf) continue;
		dis[v]=dis[x]+w;
		dfs(v,x);
	}
}
int val2[N];
bool cmp(const int &a,const int &b){return val2[a]>val2[b];}
struct ATSolve 
{
	int rt,tot,bx,num,ans;
	int fa[N],det[N],dis[N],vmx[N],son[N],bel[N],tf[N],hl[N],hr[N],vf[Log+3][N],vm[Log+3][N],val[N],pl[N],rk[N],sum[N];
	void dfs(int x,int nf)
	{
		int i,v,w;
		fa[x]=nf;det[x]=det[nf]+1;
		vmx[x]=dis[x];
		for(i=he[x];i;i=e[i].nxt)
		{
			v=e[i].v;w=e[i].w;
			if(v==nf) continue;
			dis[v]=dis[x]+w;
			dfs(v,x);
			cmax(vmx[x],vmx[v]);
			if(vmx[v]>vmx[son[x]]) son[x]=v;
		}
	}
	void dfs2(int x,int bf)
	{
		int i,v;
		if(x==bf) bel[x]=++tot,hl[tot]=x;
		else bel[x]=bel[bf];
		hr[bel[x]]=x;
		if(son[x]) dfs2(son[x],bf);
		for(i=he[x];i;i=e[i].nxt)
		{
			v=e[i].v;
			if(v==fa[x]||v==son[x]) continue;
			dfs2(v,v);
			tf[bel[v]]=bel[x];
		}
	}
	
	void solve()
	{
		int i,j;
		tot=0;
		dfs(rt,0);
		//puts("OK");
		dfs2(rt,rt);
		for(i=1;i<=tot;i++) val[i]=dis[hr[i]]-dis[fa[hl[i]]];
		for(i=1;i<=tot;i++) pl[i]=i,val2[i]=val[i];
		sort(pl+1,pl+tot+1,cmp);
		for(i=1;i<=tot;i++) rk[pl[i]]=i,sum[i]=sum[i-1]+val[pl[i]];
		for(i=1;i<=tot;i++) vf[0][i]=tf[i],vm[0][i]=rk[i];
		for(i=1;i<=Log;i++)
		{
			for(j=1;j<=tot;j++) vf[i][j]=vf[i-1][vf[i-1][j]],vm[i][j]=min(vm[i-1][vf[i-1][j]],vm[i-1][j]);
		}
	}
	int qry(int X,int Y)
	{
		int x,i,bvl,id;
		bx=X;
		if(bx==rt) return sum[min(Y*2-2,tot)];
		num=Y*2-1;
		if(rk[bel[bx]]<=num) return sum[min(num,tot)];
		
		ans=0;
		//A
		x=bel[bx];
		for(i=Log;i>=0;i--) 
		{
			if(rk[vf[i][x]]>num) x=vf[i][x];
		}
		if(hl[x]!=rt)
		{
			id=bel[fa[hl[x]]];
			bvl=dis[hr[bel[bx]]]-dis[fa[hl[x]]];
			bvl-=dis[hr[id]]-dis[fa[hl[x]]];
			cmax(ans,bvl+sum[num]);
		}


		//B
		num--;
		x=bel[bx];
		for(i=Log;i>=0;i--) 
		{
			if(rk[vf[i][x]]>num) x=vf[i][x];
		}
		cmax(ans,dis[hr[bel[bx]]]-dis[fa[hl[x]]]+sum[num]);
		
		
		return ans;
	}
}h1,h2;
int main()
{
	ios::sync_with_stdio(false);
	int i,u,v,w,x,y,ans=0;
	cin>>n>>Q;
	for(i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		eadd(u,v,w);eadd(v,u,w);
	}
	pos=0;dis[1]=0;dfs(1,0);A=pos;
	pos=0;dis[A]=0;dfs(A,0);B=pos;
	h1.rt=A;h2.rt=B;
	h1.solve();h2.solve();

	while(Q--)
	{
		cin>>x>>y;
		x=(x+ans-1)%n+1;y=(y+ans-1)%n+1;
		//printf("Q%d %d\n",x,y);
		ans=max(h1.qry(x,y),h2.qry(x,y));
		printf("%d\n",ans);
	}
	return 0;
}