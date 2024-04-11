#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
const int N=200005,mod=1000000007;
typedef long long LL;
int n,m;
LL a[N],w[N];
struct bit
{
	LL t[N];

	void insert(int x,LL y)
	{
		for(int i=x; i<=n; i+=i&-i) t[i]+=y;
	}

	LL query(int x)
	{
		LL rt=0;
		for(int i=x; i; i-=i&-i) rt+=t[i];
		return rt;
	}

	LL query(int l,int r)
	{
		return query(r)-query(l-1);
	}
} t1,t2;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

LL getLL()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	LL x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,1,n) w[i]=getint(),t1.insert(i,w[i]),t2.insert(i,(LL)(a[i]-i)*w[i]%mod);
	while(m--)
	{
		int x=getint(),y=getint();
		if(x<0)
		{
			x=-x;
			t1.insert(x,y-w[x]),t2.insert(x,(LL)(a[x]-x)*(y-w[x])%mod);
			w[x]=y;
		}
		else
		{
			int l=x,r=y;
			int p=l,q=r;
			LL sum=t1.query(l,r);
			while(l<=r)
			{
				LL nw=t1.query(p,mid);
				if(nw>=sum-nw) r=mid-1;
				else l=mid+1;
			}
			LL ans=0;
			++r;
			ans=(-t2.query(p,r)+t1.query(p,r)%mod*(a[r]-r))%mod;
			ans=(ans+t2.query(r+1,q)-t1.query(r+1,q)%mod*(a[r]-r))%mod;
			printf("%lld\n",(ans+mod)%mod);
		}
	}
	return 0;
}