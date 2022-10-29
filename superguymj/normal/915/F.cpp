#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=1000005;
typedef long long LL;
LL ans;
int n,bin[N],a[N],f[N],s[N],id[N],rk[N],h[N],cnt;
struct edge{int v,n;} e[N<<1];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void addedge(int u,int v)
{
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,h[v]},h[v]=cnt++;
}

int getfa(int x)
{
	return f[x]==x?x:f[x]=getfa(f[x]);
}\

int main()
{
	n=getint(),memset(h,-1,sizeof(h));
	rep(i,1,n) ++bin[a[i]=getint()];
	rep(i,1,n-1) addedge(getint(),getint());
	rep(i,1,1000000) bin[i]+=bin[i-1];
	rep(i,1,n) id[i]=bin[a[i]],rk[bin[a[i]]--]=i,f[i]=i,s[i]=1;
	rep(i,1,n)
	{
		int x=rk[i];
		for(int j=h[x]; j!=-1; j=e[j].n)
			if(id[e[j].v]<id[x])
			{
				int nw=getfa(e[j].v);
				ans-=(LL)a[x]*s[nw]*s[nw];
				f[nw]=x,s[x]+=s[nw];
			}
		ans+=(LL)a[x]*s[x]*s[x];
	}
	rep(i,1,n) f[i]=i,s[i]=1;
	repd(i,n,1)
	{
		int x=rk[i];
		for(int j=h[x]; j!=-1; j=e[j].n)
			if(id[e[j].v]>id[x])
			{
				int nw=getfa(e[j].v);
				ans+=(LL)a[x]*s[nw]*s[nw];
				f[nw]=x,s[x]+=s[nw];
			}
		ans-=(LL)a[x]*s[x]*s[x];
	}
	printf("%lld\n",ans/2);
	return 0;
}