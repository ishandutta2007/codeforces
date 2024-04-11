#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define id(i,j) ((i-1)*m+j)
#define pb push_back

using namespace std;
typedef long long LL;
const int N=800005;
const int hx[]={0,0,1,-1};
const int hy[]={1,-1,0,0};
int n,m,dis[N],frm[N],q[N],head,tail;
bool vis[N];
int s,t,tot;
char S[N];
vector <int> vt0[N],vt1[N],mp[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void addedge(int u,int v,int d)
{
	if(d==0) vt0[u].pb(v);
	else vt1[u].pb(v);
}

void ins(int x,int d,int lst)
{
	if(dis[x]!=-1) return;
	dis[x]=d;
	frm[x]=lst;
	q[++tail]=x;
	for(auto v:vt0[x]) ins(v,d,x);
}

void solve()
{
	n=getint(),m=getint();
	rep(i,1,n)
		mp[i].clear();
	rep(i,1,n)
	{
		scanf("%s",S+1);
		mp[i].pb(0);
		rep(j,1,m) mp[i].pb(S[j]=='#');
	}
	rep(i,1,n) rep(j,1,m) vis[id(i,j)]=0;
	rep(i,1,n)
		rep(j,1,m) if(mp[i][j])
			rep(k,0,3)
			{
				int x=i+hx[k];
				int y=j+hy[k];
				if(x>0 && x<=n && y>0 && y<=m)
					vis[id(x,y)]=1;
			}
	tot=n*m;
	s=tot*2+1,t=s+1;
	rep(i,1,t) vt0[i].clear(),vt1[i].clear();
	rep(i,1,n) rep(j,1,m) if(!vis[id(i,j)])
		addedge(id(i,j),tot+id(i,j),!mp[i][j]);
	rep(i,1,n) addedge(s,id(i,1),0),addedge(tot+id(i,m),t,0);
	rep(j,1,m-1)
		rep(i,1,n)
		{
			if(i-1>0)
			{
				addedge(tot+id(i,j),id(i-1,j+1),0);
				addedge(tot+id(i-1,j+1),id(i,j),0);
			}
			if(i+1<=n)
			{
				addedge(tot+id(i,j),id(i+1,j+1),0);
				addedge(tot+id(i+1,j+1),id(i,j),0);
			}
		}
	rep(i,1,t) dis[i]=-1;
	head=0,tail=-1;
	ins(s,0,0);
	while(head<=tail)
	{
		int x=q[head++];
		for(auto v:vt1[x])
			ins(v,dis[x]+1,x);
	}
	if(dis[t]==-1)
	{
		puts("NO");
		return;
	}
	puts("YES");
	int x=t;
	while(x!=s)
	{
		if(x<=tot)
			mp[(x-1)/m+1][(x-1)%m+1]=1;
		x=frm[x];
	}
	rep(i,1,n)
	{
		rep(j,1,m) if(mp[i][j]) putchar('#'); else putchar('.');
		puts("");
	}
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}