#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005;
int n,m,f[N],x,y,ans;
bool h[N];
struct data{int x,y,c;} dat[N];

int getfa(int x)
{
	return f[x]==x?x:f[x]=getfa(f[x]);
}

bool cmp(data a,data b)
{
	return a.c>b.c;
}

int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n) f[i]=i;
	rep(i,1,m) scanf("%d%d%d",&dat[i].x,&dat[i].y,&dat[i].c);
	sort(dat+1,dat+1+m,cmp);
	rep(i,1,m)
	{
		x=getfa(dat[i].x),y=getfa(dat[i].y);
		if(x==y)
		{
			if(!h[x]) h[x]=1,ans+=dat[i].c;
		}
		else if(!h[x] || !h[y]) f[y]=x,h[x]|=h[y],ans+=dat[i].c;
	}
	printf("%d\n",ans);
	return 0;
}