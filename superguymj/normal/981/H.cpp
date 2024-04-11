#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)
#define pb push_back

using namespace std;
typedef long long LL;
const int N=100005,mod=998244353;
int n,k,cnt,h[N],siz[N],pool[N],len,bin[N<<2];
LL a[N<<2],b[N<<2],flv[N],inv[N],ans,f[N],vis[N];
struct edge{int v,n;} e[N<<1];
vector <LL> c[N],dat[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
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

void FFT(LL a[],int len,int tp)
{
	rep(i,0,len-1) bin[i]=bin[i>>1]>>1|((i&1)*(len>>1));
	rep(i,0,len-1) if(i<bin[i]) swap(a[i],a[bin[i]]);
	for(int i=1; i<len; i<<=1)
	{
		LL wn=getmi(3,(mod-1)/(i<<1));
		if(tp==-1) wn=getmi(wn,mod-2);
		for(int j=0; j<len; j+=i<<1)
		{
			LL w=1,x,y;
			rep(k,0,i-1)
			{
				x=a[j+k],y=a[i+j+k]*w%mod,w=w*wn%mod;
				a[j+k]=(x+y)%mod,a[i+j+k]=(x-y+mod)%mod;
			}
		}
	}
	if(tp==-1)
	{
		LL x=getmi(len,mod-2);
		rep(i,0,len-1) a[i]=a[i]*x%mod;
	}
}

void solve(int l,int r)
{
	if(l>r)
	{
		dat[1].clear();
		dat[1].pb(1);
		return;
	}
	if(l==r)
	{
		dat[l].clear();
		dat[l].pb(1),dat[l].pb(siz[pool[l]]);
		return;
	}
	solve(l,mid),solve(mid+1,r);
	int sizl=dat[l].size()-1,sizr=dat[mid+1].size()-1;
	for(len=1; len<=sizl+sizr; len<<=1);
	rep(i,0,len-1) a[i]=b[i]=0;
	rep(i,0,sizl) a[i]=dat[l][i];
	rep(i,0,sizr) b[i]=dat[mid+1][i];
	FFT(a,len,1),FFT(b,len,1);
	rep(i,0,len-1) a[i]=a[i]*b[i]%mod;
	FFT(a,len,-1),dat[l].clear();
	rep(i,0,sizl+sizr) dat[l].pb(a[i]);
}

void addedge(int u,int v)
{
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,h[v]},h[v]=cnt++;
}

void prepare()
{
	flv[0]=1;
	rep(i,1,k) flv[i]=flv[i-1]*i%mod;
	inv[k]=getmi(flv[k],mod-2);
	repd(i,k,1) inv[i-1]=inv[i]*i%mod;
}

LL C(int n,int m)
{
	return n<m?0:flv[n]*inv[n-m]%mod;
}

void dfs1(int x,int fa)
{
	siz[x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa)
		{
			dfs1(e[i].v,x);
			siz[x]+=siz[e[i].v];
		}
	
	*pool=0;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa) pool[++*pool]=e[i].v;
	solve(1,*pool);
	int s=dat[1].size()-1;
	rep(i,0,s)
	{
		LL tmp=dat[1][i];
		f[x]=(f[x]+C(k,i)*tmp)%mod;
	}
	ans=(ans+f[fa]*f[x])%mod,f[fa]=(f[fa]+f[x])%mod;
	
	c[x].pb(1);
	rep(i,1,s+1)
	{
		LL tmp=dat[1][i-1]*(n-siz[x])%mod;
		if(i<=s) tmp=(tmp+dat[1][i])%mod;
		c[x].pb(tmp);
	}
}

void dfs2(int x,int fa)
{
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa)
			dfs2(e[i].v,x);
	
	*pool=0;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa)
			pool[++*pool]=siz[e[i].v],vis[siz[e[i].v]]=(vis[siz[e[i].v]]+f[e[i].v])%mod;

	rep(i,1,*pool) if(vis[pool[i]])
	{
		LL tmp=0,nw=vis[pool[i]];
		int s=c[x].size()-1;
		vis[pool[i]]=0;
		rep(j,0,s)
		{
			tmp=(c[x][j]-tmp*pool[i])%mod;
			ans=(ans+C(k,j)*tmp%mod*nw)%mod;
		}
	}
}

int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=getint(),k=getint();
	if(k==1)
	{
		printf("%lld\n",n*(n-1ll)/2%mod);
		return 0;
	}
	memset(h,-1,sizeof(h));
	rep(i,1,n-1) addedge(getint(),getint());
	prepare();
	dfs1(1,0);
	dfs2(1,0);
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}