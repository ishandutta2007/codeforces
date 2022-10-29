#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
typedef long long LL;
const int N=200005;
int n,m,R[N];
vector <int> vt[N];
int id[N][2],tot,fa[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
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
	n=getint(),m=getint();
	rep(i,1,n) R[i]=getint();
	rep(i,1,m)
	{
		int k=getint();
		rep(j,1,k) vt[getint()].pb(i);
	}
	rep(i,1,m) id[i][0]=++tot,id[i][1]=++tot;
	rep(i,1,tot) fa[i]=i;
	rep(i,1,n)
	{
		int x=vt[i][0],y=vt[i][1];
		if(R[i]==0)
		{
			merge(id[x][0],id[y][1]);
			merge(id[x][1],id[y][0]);
		}
		else
		{
			merge(id[x][0],id[y][0]);
			merge(id[x][1],id[y][1]);
		}
	}
	rep(i,1,m) if(getfa(id[i][0])==getfa(id[i][1])) return puts("NO"),0;
	puts("YES");
	return 0;
}