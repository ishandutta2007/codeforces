#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<vector>
#include<set>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=100005;
typedef long long LL;
LL k;
int n,h[N],cnt,low;
struct edge{int v,n;} e[N<<1];
int mx[N],siz[N],root,f[N],d[N],tot;
set <int> son[N];
struct data
{
	int x,cnt;
	
	bool operator < (const data &t) const
	{
		return cnt==t.cnt?x<t.x:cnt>t.cnt;
	}
} ;
set <data> st,vt[N];
typedef set<data>::iterator it;

void addedge(int u,int v)
{
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,h[v]},h[v]=cnt++;
}

void dfs(int x,int fa)
{
	siz[x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa)
			dfs(e[i].v,x),siz[x]+=siz[e[i].v],mx[x]=max(mx[x],siz[e[i].v]);
}

void getroot()
{
	dfs(1,0);
	rep(i,1,n)
	{
		mx[i]=max(mx[i],n-siz[i]);
		if(!root || mx[root]>mx[i]) root=i;
	}
}

void dfs(int tp,int x,int fa,int dep)
{
	f[x]=fa,d[x]=dep,siz[x]=1;
	k-=dep,vt[tp].insert((data){x,dep});
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa)
			dfs(tp,e[i].v,x,dep+1),siz[x]+=siz[e[i].v],son[x].insert(e[i].v);
	low+=(siz[x]&1);
}

void find(int p)
{
	for(it x=vt[p].begin(); x!=vt[p].end(); ++x)
	{
		if(x->cnt==k && !son[x->x].empty())
		{
			int u=x->x,v=*son[u].begin();
			vt[p].erase((data){u,d[u]}),vt[p].erase((data){v,d[v]});
			printf("%d %d\n",u,v);
			return;
		}
	}
}

void fin()
{
	while((st.begin()->cnt)>0)
	{
		int p1=st.begin()->x,cnt1=st.begin()->cnt;
		st.erase(st.begin());
		int p2=st.begin()->x,cnt2=st.begin()->cnt;
		st.erase(st.begin());
		st.insert((data){p1,cnt1-1});
		st.insert((data){p2,cnt2-1});
		int u=vt[p1].begin()->x,v=vt[p2].begin()->x;
		vt[p1].erase(vt[p1].begin());
		vt[p2].erase(vt[p2].begin());
		printf("%d %d\n",u,v);
	}
}

int main()
{
	scanf("%d%lld",&n,&k);
	memset(h,-1,sizeof(h));
	rep(i,1,n-1)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	getroot();
	LL lowk=k;
	for(int i=h[root]; i!=-1; i=e[i].n)
		dfs(++tot,e[i].v,root,1),st.insert((data){tot,siz[e[i].v]});
	st.insert((data){++tot,1}),vt[tot].insert((data){root,0});
	if(k=-k,lowk<low || k<0 || k&1) return puts("NO"),0;
	puts("YES"),k>>=1;
	while(k)
	{
		int p=st.begin()->x,cnt=st.begin()->cnt;
		st.erase(st.begin()),st.insert((data){p,cnt-2});
		int x,u,v;
		x=f[vt[p].begin()->x];
		if(k-d[x]<0) {find(p); break;}
		k-=d[x];
		if((int)(son[x].size())>1)
		{
			u=*son[x].begin(),son[x].erase(son[x].begin()); 
			v=*son[x].begin(),son[x].erase(son[x].begin());
		}
		else
		{
			if(f[u=x]!=root) son[f[u]].erase(u);
			v=*son[x].begin(),son[x].erase(son[x].begin());	
		}
		vt[p].erase((data){u,d[u]}),vt[p].erase((data){v,d[v]});
		printf("%d %d\n",u,v);
	}
	fin();
	return 0;
}