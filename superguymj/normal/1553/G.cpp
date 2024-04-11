#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=150005,M=2000000;
bool vis[M];
int n,q,mx,a[N],prm[M],fa[M];
vector <int> vt[M];
map <int,bool> mp[M];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void ins(int x,int y)
{
	mp[x][y]=mp[y][x]=1;
}

void pre()
{
	rep(i,2,mx)
	{
		if(!vis[i])
		{
			prm[++*prm]=i;
			for(int j=i; j<=mx; j+=i) vt[j].pb(i);
		}
		rep(j,1,*prm)
		{
			if(i*prm[j]>mx) break;
			vis[i*prm[j]]=1;
			if(i%prm[j]==0) break;
		}
	}
	rep(i,1,mx+n) fa[i]=i;
}

int getfa(int x)
{
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}

void merge(int x,int y)
{
	x=getfa(x),y=getfa(y);
	fa[x]=y;
}

int main()
{
	n=getint(),q=getint();
	rep(i,1,n) mx=max(mx,a[i]=getint());
	++mx,pre();
	rep(i,1,n)
	{
		vector <int> p=vt[a[i]];
		rep(j,0,p.size()-1) merge(p[j],mx+i);
	}
	rep(i,1,n)
	{
		vector <int> p=vt[a[i]+1];
		vector <int> p2=vt[a[i]];
		rep(j,0,p.size()-1)
		{
			rep(k,j+1,p.size()-1)
			{
				int x=getfa(p[j]),y=getfa(p[k]);
				if(x!=y) ins(x,y);
			}
			rep(k,0,p2.size()-1)
			{
				int x=getfa(p[j]),y=getfa(p2[k]);
				if(x!=y) ins(x,y);
			}
		}
	}
	while(q--)
	{
		int x=getfa(mx+getint()),y=getfa(mx+getint());
		if(x==y) puts("0");
		else if(mp[x][y]) puts("1");
		else puts("2");
	}
	return 0;
}