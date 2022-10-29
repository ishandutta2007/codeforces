#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
const int N=100005,mod=1000000007;
bool h[N<<1];
int n,s[N<<1],f[N<<1],pool[N<<1],x,y,id1[N<<1],id2[N<<1];
long long tot,ans;
struct data{int x,y;} dat[N];

int find(int x)
{
	int l=1,r=*pool;
	while(l<=r)
		pool[mid]<=x?l=mid+1:r=mid-1;
	return l-1;
}

int getfa(int x)
{
	return x==f[x]?x:f[x]=getfa(f[x]);
}

void merge(int x,int y)
{
	x=getfa(x),y=getfa(y);
	if(x==y) h[x]=1;
	else f[y]=x,h[x]|=h[y],s[x]+=s[y];
}

void query(int l,int r)
{
	rep(i,l,r)
		if(f[i]==i)
		{
			tot=1;
			rep(j,1,s[i]) tot=tot*2%mod;
			if(h[i]) ans=ans*tot%mod;
			else ans=ans*(tot-1)%mod;
		}
}

int main()
{
	scanf("%d",&n);
	rep(i,1,2*n) s[i]=1,f[i]=i;
	rep(i,1,n) scanf("%d%d",&dat[i].x,&dat[i].y),pool[++*pool]=dat[i].x,pool[++*pool]=dat[i].y;
	sort(pool+1,pool+1+*pool);
	rep(i,1,n) dat[i].x=find(dat[i].x),dat[i].y=find(dat[i].y);
	rep(i,1,n)
	{
		x=id1[dat[i].x]?id1[dat[i].x]:id1[dat[i].x]=++*id1;
		y=id2[dat[i].y]?id2[dat[i].y]:id2[dat[i].y]=++*id2;
		merge(x,y+n);
	}
	ans=1,query(1,*id1),query(n+1,n+*id2);
	printf("%I64d\n",ans);
	return 0;
}