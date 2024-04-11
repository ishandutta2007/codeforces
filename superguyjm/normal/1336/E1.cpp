#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=55,S=1<<18,mod=998244353;
typedef long long LL;
int n,m,k,p[N];
LL a[200005],pw,bin[N],ans[N],val[N],f[2][N][S];

LL getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	LL x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void inc(LL &x,LL y)
{
	if((x+=y)>=mod) x-=mod;
}

void ins(LL x)
{
	repd(i,m-1,0) if(x&(1ll<<i)) x^=bin[i];
	if(!x) pw=2*pw%mod;
	else
	{
		repd(i,m-1,0) if(x&(1ll<<i))
		{
			bin[i]=x;
			rep(j,i+1,m-1) if(bin[j]&(1ll<<i)) bin[j]^=x;
			break;
		}
	}
}

int cnt(LL x)
{
	int ans=0;
	rep(i,0,m-1) if(x&(1ll<<i)) ++ans;
	return ans;
}

void task1()
{
	rep(i,0,(1<<(*p))-1)
	{
		LL x=0;
		rep(j,0,(*p)-1) if(i&(1ll<<j)) x^=bin[p[j+1]];
		inc(ans[cnt(x)],1);
	}
	rep(i,0,m) printf("%lld ",ans[i]*pw%mod);
	puts("");
}

LL trf(LL x)
{
	LL rt=0;
	repd(i,m-1,0)
		if(!bin[i])
			rt=rt<<1|((bool)(x&(1ll<<i)));
	return rt;
}

void task2()
{
	k=m-*p;
	rep(i,1,*p) val[i]=trf(bin[p[i]]);
	f[0][0][0]=1;
	rep(i,1,*p)
		rep(j,0,i-1)
			rep(s,0,(1<<k)-1)
				if(f[(i-1)&1][j][s])
				{
					LL tmp=f[(i-1)&1][j][s];
					inc(f[i&1][j+1][s^val[i]],tmp);
					inc(f[i&1][j][s],tmp);
					f[(i-1)&1][j][s]=0;
				}
	rep(i,0,*p) rep(s,0,(1<<k)-1)
		inc(ans[i+cnt(s)],f[(*p)&1][i][s]);
	rep(i,0,m) printf("%lld ",ans[i]*pw%mod);
	puts("");
}

int main()
{
	n=getint(),m=getint(),pw=1;
	rep(i,1,n) a[i]=getint();
	rep(i,1,n) ins(a[i]);
	rep(i,0,m-1) if(bin[i]) p[++*p]=i;
	if(*p<=20) task1();
	else 
		task2();
	return 0;
}