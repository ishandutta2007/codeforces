#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define pb push_back

using namespace std;
const int N=100005,mod=998244353;
typedef long long LL;
int n,h[N],cnt,bin[N<<2],len,pool[N],tot;
int dep[N],top[N],dfn[N],pos[N],fa[N],siz[N],son[N];
LL A[N<<2],B[N<<2],C[N<<2],c[N],ans,lim,Wn[20][N<<2];
vector <LL> dt1[N],dt2[N],dt3[N],vt[N];
struct edge{int v,n;} e[N<<1];
struct data{int x,y;} dat[N];
int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

LL getLL()
{
	char ch;
	while(!isdigit(ch=getchar()));
	LL x=ch-48;
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

struct num
{
	LL x,c;

	num operator * (LL t)
	{
		num rt=(num){x,c};
		while(t%mod==0) t/=mod,++rt.c;
		t%=mod,rt.x=rt.x*t%mod;
		return rt;
	}

	num operator / (LL t)
	{
		num rt=(num){x,c};
		while(t%mod==0) t/=mod,--rt.c;
		t%=mod,rt.x=rt.x*getmi(t,mod-2)%mod;
		return rt;
	}

	LL cnt()
	{
		return c?0:x;
	}
};

void FFT(LL a[],int len,int tp)
{
	rep(i,0,len-1) bin[i]=bin[i>>1]>>1|((i&1)*(len>>1));
	rep(i,0,len-1) if(i<bin[i]) swap(a[i],a[bin[i]]);
	for(int i=1,cnt=0; i<len; ++cnt,i<<=1)
	{
		for(int j=0; j<len; j+=i<<1)
		{
			LL w=0,x,y;
			rep(k,0,i-1)
			{
				x=a[j+k],y=a[i+j+k]*Wn[cnt][w+i]%mod,w+=tp;
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

void pre_Wn()
{
	rep(i,0,18)
	{
		int x=1<<i;
		Wn[i][x]=1;
		LL wn=getmi(3,(mod-1)/(x<<1));
		rep(j,1,x-1) Wn[i][j+x]=Wn[i][j+x-1]*wn%mod;
		wn=getmi(wn,mod-2);
		rep(j,1,x-1) Wn[i][-j+x]=Wn[i][-j+x+1]*wn%mod;
	}
}

void addedge(int u,int v)
{
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,h[v]},h[v]=cnt++;
}

void dfs(int x,int f,int d)
{
	fa[x]=f,dep[x]=d,siz[x]=1;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=f)
		{
			dfs(e[i].v,x,d+1);
			siz[x]+=siz[e[i].v];
			if(!son[x] || siz[son[x]]<siz[e[i].v])
				son[x]=e[i].v;
		}
}

void dfs(int x,int t)
{
	top[x]=t,pos[dfn[x]=++*dfn]=x;
	if(son[x]) dfs(son[x],t);
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa[x] && e[i].v!=son[x])
			dfs(e[i].v,e[i].v);
}

bool cmp(data a,data b)
{
	return dep[pos[a.x]]>dep[pos[b.x]];
}

void prepare()
{
	rep(i,1,n) if(!son[i]) dat[++tot]=(data){dfn[top[i]],dfn[i]};
	sort(dat+1,dat+1+tot,cmp);
}

void get(int x)
{
	*pool=0;
	for(int j=h[x]; j!=-1; j=e[j].n)
		if(e[j].v!=fa[x] && e[j].v!=son[x])
			pool[++*pool]=e[j].v;
}

void solve1(int l,int r)
{
	if(l==r)
	{
		dt1[l]=vt[pool[l]];
		dt1[l][0]=1;
		return;
	}
	solve1(l,mid),solve1(mid+1,r);
	int sizl=dt1[l].size()-1;
	int sizr=dt1[mid+1].size()-1;
	for(len=1; len<=sizl+sizr; len<<=1);
	rep(i,0,len-1) A[i]=B[i]=0;
	rep(i,0,sizl) A[i]=dt1[l][i];
	rep(i,0,sizr) B[i]=dt1[mid+1][i];
	FFT(A,len,1),FFT(B,len,1);
	rep(i,0,len-1) A[i]=A[i]*B[i]%mod;
	FFT(A,len,-1),dt1[l].clear();
	rep(i,0,sizl+sizr) dt1[l].pb(A[i]);
}

void solve2(int l,int r)
{
	if(l==r)
	{
		dt2[l]=dt3[l]=vt[pool[l]];
		return;
	}
	solve2(l,mid),solve2(mid+1,r);
	int sizl=dt2[l].size()-1;
	int sizr=dt2[mid+1].size()-1;
	for(len=1; len<=sizl+sizr; len<<=1);
	rep(i,0,len-1) A[i]=B[i]=C[i]=0;
	rep(i,0,sizl) A[i]=dt2[l][i];
	rep(i,0,sizr) B[i]=dt2[mid+1][i],C[i]=dt3[mid+1][i];
	FFT(A,len,1),FFT(B,len,1),FFT(C,len,1);
	rep(i,0,len-1) C[i]=C[i]*A[i]%mod,A[i]=A[i]*B[i]%mod;
	FFT(A,len,-1),FFT(C,len,-1);
	rep(i,0,sizl) C[i]=(C[i]+dt3[l][i])%mod;
	dt2[l].clear(),dt3[l].clear();
	rep(i,0,sizl+sizr) dt2[l].pb(A[i]),dt3[l].pb(C[i]);
}

void query(int l,int r)
{
	rep(i,l,r)
	{
		int x=pos[i];
		get(x);
		if(!(*pool))
		{
			vt[x].pb(0),vt[x].pb(1);
			continue;
		}
		solve1(1,*pool);
		int siz=dt1[1].size()-1;
		vt[x].pb(0);
		rep(j,0,siz) vt[x].pb(dt1[1][j]);
	}
	rep(i,1,r-l+1) pool[i]=pos[i+l-1];
	solve2(1,r-l+1),vt[pos[l]]=dt3[1];
}

void task1()
{
	prepare();
	rep(i,1,tot) query(dat[i].x,dat[i].y);
	rep(i,1,n) c[i]=vt[1][i];
}

void task2()
{
	num x=(num){1,0};
	rep(i,1,n) ans=(ans+x.cnt()*c[i])%mod,x=x*(lim+i)/i;
}

int main()
{
	n=getint(),lim=getLL();
	memset(h,-1,sizeof(h));
	rep(i,1,n-1) addedge(getint(),getint());
	dfs(1,0,1),dfs(1,1);
	pre_Wn();
	task1();
	task2();
	printf("%lld\n",ans);
	return 0;
}