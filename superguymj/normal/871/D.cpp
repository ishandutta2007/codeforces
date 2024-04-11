#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=10000005;
typedef long long LL;
int n,phi[N],prm[N],p[N];
bool vis[N];
LL ans,t[N];

void prepare()
{
	phi[1]=1;
	rep(i,2,n)
	{
		if(!vis[i]) prm[++*prm]=i,p[i]=i,phi[i]=i-1;
		rep(j,1,*prm)
		{
			if(i*prm[j]>n) break;
			vis[i*prm[j]]=1,p[i*prm[j]]=prm[j];
			if(i%prm[j]) phi[i*prm[j]]=phi[i]*(prm[j]-1);
			else {phi[i*prm[j]]=phi[i]*prm[j]; break;}
		}
	}
}

void add(int x)
{
	for(; x<=n; x+=x&-x) ++t[x];
}

LL query(int x)
{
	LL rt=0;
	for(; x; x-=x&-x) rt+=t[x];
	return rt;
}

int main()
{
	scanf("%d",&n);
	prepare();
	rep(i,2,n)
		if(p[i]*2<=n)
			ans+=-query(n/p[i])-(i-phi[i]-1)+3*query(n/2),add(p[i]);
	printf("%I64d\n",ans);
	return 0;
}