#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
typedef long long LL;
const int N=300005,K=25,mod=998244353;
int n,m,cnt,bin[1<<21],l[N],r[N],a[K],b[K],In[N];
bool vis[N];
LL f[K<<1],flv[N],inv[N],ans;
vector <int> vt[N];

bool check(int x)
{
	rep(i,1,m)
	{
		if(a[i]==x && vis[b[i]]) return 1;
		if(b[i]==x && vis[a[i]]) return 1;
	}
	return 0;
}

int in(int S)
{
	rep(i,1,m) In[a[i]]=In[b[i]]=0;
	rep(i,1,m) if(S&(1<<i-1))
	{
		if(!vis[a[i]] || !vis[b[i]]) return -1;
		In[a[i]]=1,In[b[i]]=1;
	}
	int rt=0;
	rep(i,1,m) rt+=In[a[i]],In[a[i]]=0,rt+=In[b[i]],In[b[i]]=0;
	return rt;
}

void init()
{
	rep(i,0,2*m) f[i]=0;
	rep(i,0,(1<<m)-1)
	{
		int x=in(i);
		if(x==-1) continue;	
		if(bin[i]&1) f[x]=(f[x]-1)%mod;
		else f[x]=(f[x]+1)%mod;
	}
}			

void del(int x)
{
	vis[x]=0,--cnt;
	if(check(x)) init();
}

void ins(int x)
{
	vis[x]=1,++cnt;
	if(check(x)) init();
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
	if(n<0 || m<0 || n<m) return 0;
	return flv[n]*inv[m]%mod*inv[n-m]%mod;
}

LL calc(int s,int r)
{
	LL rt=0;
	rep(i,0,2*m) rt=(rt+f[i]*C(s-i,r-i))%mod;
	return rt;
}

int main()
{
	scanf("%d%d",&n,&m);

	flv[0]=1,inv[0]=1;
	rep(i,1,n) flv[i]=flv[i-1]*i%mod,inv[i]=getmi(flv[i],mod-2);

	rep(i,1,(1<<m)-1) bin[i]=bin[i^(i&-i)]+1;
	rep(i,1,n) scanf("%d%d",&l[i],&r[i]),vt[l[i]].pb(i),vt[r[i]+1].pb(i);
	rep(i,1,m) scanf("%d%d",&a[i],&b[i]);
	init();
	rep(i,1,n)
	{
		int sz=vt[i].size();
		rep(j,0,sz-1)
		{
			int x=vt[i][j];
			if(vis[x]) del(x);
			else ins(x);
		}
		ans=(ans+calc(cnt,i))%mod;
	}
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}