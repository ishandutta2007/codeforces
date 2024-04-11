#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back

using namespace std;
typedef long long LL;
const int N=1005;
int n,d[N],fa[N],vis[N],c[N],p[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

bool cmp(int x,int y)
{
	return d[x]>d[y];
}

int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}

void merge(int x,int y)
{
	x=getfa(x),y=getfa(y);
	fa[y]=x;
}

int query(int u)
{
	printf("? %d\n",u);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}

void solve()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&d[i]);
	rep(i,1,n) vis[i]=0,fa[i]=i,p[i]=i;
	sort(p+1,p+1+n,cmp);
	rep(i,1,n)
	{
		int x=p[i];
		if(vis[x]) continue;
		vis[x]=1;
		rep(j,1,d[x])
		{
			int y=query(x);
			if(vis[y])
			{
				merge(x,y);
				break;
			}
			else
			{
				vis[y]=1;
				merge(x,y);
			}
		}
	}
	int tot=0;
	rep(i,1,n) if(getfa(i)==i) c[i]=++tot;
	printf("!");
	rep(i,1,n) printf(" %d",c[getfa(i)]);
	puts("");
	fflush(stdout);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}