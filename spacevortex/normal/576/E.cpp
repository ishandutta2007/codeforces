#include<bits/stdc++.h>
#define pb push_back
#define ls (rt<<1)
#define rs ((rt<<1)|1)
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
const int N=5e5+50,V=2e6+50,P=55;
int n,m,K,Q,top=0;
int a[N],b[N],las[N],qas[N],R[N],bel[N];
struct Act{int e,c;}q[N];
struct Bdata
{
	int c,x,y,si;
}stk[N];
struct Maton
{
	int C;
	int fa[N],fw[N],dis[N],siz[N];
	void init()
	{
		int i;
		for(i=1;i<=n;i++)
		{
			siz[i]=1;fa[i]=i;dis[i]=0;
		}
	}
	int getft(int x)
	{
		if(x==fa[x]) return x;
		int tmp=getft(fa[x]);
		dis[x]=dis[fa[x]]^fw[x];
		return tmp;
	}
	bool chk(int x,int y)
	{
		int af,bf;
		af=getft(x);bf=getft(y);
		if(af!=bf) return 1;
		else return dis[x]!=dis[y];
	}
	void merge(int x,int y)
	{
		int af,bf,d;
		af=getft(x);bf=getft(y);
		if(af==bf) return ;
		if(siz[af]<siz[bf]) swap(x,y),swap(af,bf);
		d=(dis[x]^dis[y])^1;
		stk[++top]=(Bdata){C,af,bf,siz[bf]};
		fa[bf]=af;siz[af]+=siz[bf];dis[bf]=fw[bf]=d;
	}
}mt[P];
void back(int pos)
{
	Bdata bno;
	int c;
	while(top>pos)
	{
		bno=stk[top];
		c=bno.c;
		mt[c].fa[bno.y]=bno.y;
		mt[c].fa[bno.y]=bno.y;
		mt[c].siz[bno.x]-=bno.si;
		mt[c].dis[bno.y]=mt[c].fw[bno.y]=0;
		top--;
	}
}
struct Segment_tree
{
	vector<int> vec[V];
	
	void add(int rt,int l,int r,int x,int y,int id)
	{
		if(l>=x&&r<=y)
		{
			vec[rt].pb(id);
			return ;
		}
		int mid=(l+r)>>1;
		if(mid>=x) add(ls,l,mid,x,y,id);
		if(mid<y) add(rs,mid+1,r,x,y,id);
	}
	void dfs(int rt,int l,int r)
	{
		int vsi,i,bkp;
		Act act;
		bkp=top;
		vsi=vec[rt].size();
		for(i=0;i<vsi;i++)
		{
			act=q[vec[rt][i]];
			mt[act.c].merge(a[act.e],b[act.e]);
		}
		if(l==r)
		{
			//puts("chk");
			if(mt[q[l].c].chk(a[q[l].e],b[q[l].e])==1)
			{
				qas[l]=1;
				bel[q[l].e]=l;
				if(l<R[l]) add(1,1,Q,l+1,R[l],l);
			}
			else
			{
				if(bel[q[l].e]&&l<R[l]) add(1,1,Q,l+1,R[l],bel[q[l].e]);
			}
			back(bkp);
			return ;
		}
		int mid=(l+r)>>1;
		dfs(ls,l,mid);dfs(rs,mid+1,r);
		back(bkp);
	}
}sgt;
int main()
{
	int i,id;
	n=rd();m=rd();K=rd();Q=rd();
	for(i=1;i<=m;i++) 
	{
		a[i]=rd();b[i]=rd();
	}
	for(i=1;i<=Q;i++)
	{
		q[i].e=rd();q[i].c=rd();
		if(las[q[i].e])
		{
			id=las[q[i].e];R[id]=i-1;
		}
		las[q[i].e]=i;
	}
	for(i=1;i<=m;i++)
	{
		if(las[i])
		{
			id=las[i];R[id]=Q;
		}
	}
	for(i=1;i<=K;i++) 
	{
		mt[i].C=i;mt[i].init();
	}
	sgt.dfs(1,1,Q);
	for(i=1;i<=Q;i++)
	{
		if(qas[i]) puts("YES");
		else puts("NO");
	}
	return 0;
}