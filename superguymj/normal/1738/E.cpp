#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back

using namespace std;
typedef long long LL;
const int N=100005,mod=998244353;
int n,a[N];
LL flv[N],ans,inv[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

LL getmi(LL a,LL x)
{
	LL rt=1;
	while(x)
	{
		if(x&1) rt=rt*a%mod;
		a=a*a%mod,x>>=1;
	}
	return rt;
}

LL C(int n,int m)
{
	return n<m?0:flv[n]*inv[m]%mod*inv[n-m]%mod;
}

LL calc(int x,int y)
{
	LL ret=0;
	if(x<0 || y<0) return 1;
	rep(i,0,min(x,y)+1)
		ret=(ret+C(x+1,i)*C(y+1,i))%mod;
	return ret;
}

void solve()
{
	n=getint();
	rep(i,1,n) a[i]=getint();
	int l=1,r=n;
	while(l<=n && !a[l]) ++l;
	if(l==n+1)
	{
		printf("%lld\n",getmi(2,n-1));
		return;
	}
	while(!a[r]) --r;
	int x,y;
	x=l-2,y=n-r-1;
	ans=calc(x,y);
	while(l<=r)
	{
		LL s=0,t=0;
		bool jdg=0;
		int p=r;
		rep(i,l,r)
		{
			s+=a[i];
			while(t+a[p]<=s)
			{
				t+=a[p--];
				if(s==t) break;
				if(p<i) break;
			}
			if(p<i) break;
			if(s==t) {l=i+1,r=p,jdg=1; break;}
		}
		if(!jdg) break;
		if(l>r)
		{
			ans=ans*2%mod;
			break;
		}
		int len=r-l+1;
		x=0,y=0;
		while(l<=r && !a[l]) ++l,++x;
		if(l>r) {ans=ans*getmi(2,len+1)%mod; break;}
		while(!a[r]) --r,++y;
		ans=ans*calc(x,y)%mod;
	}
	printf("%lld\n",ans);
}

int main()
{
//	freopen("e.in","r",stdin);
	int T=getint();
	n=100000;
	flv[0]=1;
	rep(i,1,n) flv[i]=flv[i-1]*i%mod;
	inv[n]=getmi(flv[n],mod-2);
	repd(i,n,1) inv[i-1]=inv[i]*i%mod;
	while(T--) solve();
	return 0;
}