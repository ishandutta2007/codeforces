#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
const int N=200005,lim=1000000000;
typedef long long LL;
const LL INF=100000000000000000ll;
int n,m,k,x,K,cnt[N],tot0,tot1,tot2;
LL a[N],pool0[N],pool1[N],pool2[N];
LL s0[N],s1[N],s2[N],nw,ans,seed;

struct segment_tree
{
	int ls[N*35],rs[N*35],siz[N*35],tot,Root;
	LL t[N*35],ret;

	void ins(int l,int r,int &rt,int x,int y)
	{
		if(!rt) rt=++tot;
		if(l==r)
		{
			siz[rt]+=y;
			t[rt]+=y*x;
			return;
		}
		if(x<=mid) ins(l,mid,ls[rt],x,y);
		else ins(mid+1,r,rs[rt],x,y);
		t[rt]=t[ls[rt]]+t[rs[rt]];
		siz[rt]=siz[ls[rt]]+siz[rs[rt]];
	}

	void query(int l,int r,int rt)
	{
		if(!K || !rt) return;
		if(l==r)
		{
			int x=min(siz[rt],K);
			K-=x,ret+=(LL)l*x;
			return;
		}
		if(siz[ls[rt]]>=K) query(l,mid,ls[rt]);
		else K-=siz[ls[rt]],ret+=t[ls[rt]],query(mid+1,r,rs[rt]);
	}

	void insert(int x)
	{
		ins(0,lim,Root,x,1);
	}

	void erase(int x)
	{
		ins(0,lim,Root,x,-1);
	}

	LL query()
	{
		ret=0,query(0,lim,Root);
		return ret;
	}
} t;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int main()
{
	n=getint(),m=getint(),k=getint(),ans=INF;
	rep(i,1,n) a[i]=getint();
	x=getint();
	rep(i,1,x) cnt[getint()]=1;
	x=getint();
	rep(i,1,x) cnt[getint()]|=2;
	rep(i,1,n)
	{
		if(cnt[i]==0) t.insert(a[i]);
		if(cnt[i]==1) pool1[++tot1]=a[i];
		if(cnt[i]==2) pool2[++tot2]=a[i];
		if(cnt[i]==3) pool0[++tot0]=a[i],t.insert(a[i]);
	}
	sort(pool0+1,pool0+1+tot0);
	sort(pool1+1,pool1+1+tot1);
	sort(pool2+1,pool2+1+tot2);
	
	rep(i,1,tot0) s0[i]=s0[i-1]+pool0[i];
	
	rep(i,k+1,tot1) t.insert(pool1[i]);
	tot1=min(tot1,k);
	rep(i,1,tot1) s1[i]=s1[i-1]+pool1[i];
	
	rep(i,k+1,tot2) t.insert(pool2[i]);
	tot2=min(tot2,k);
	rep(i,1,tot2) s2[i]=s2[i-1]+pool2[i];

	rep(i,0,min(k,tot0))
	{
		if(i) t.erase(pool0[i]);
		int add=max(0,k-i);
		if(add<=tot1 && add<=tot2 && m-2*k+i>=0)
		{
			nw=s0[i]+s1[add]+s2[add];
			K=m-2*k+i,nw+=t.query();
			if(!K) ans=min(ans,nw);
		}
		if(add && add<=tot1) t.insert(pool1[add]);
		if(add && add<=tot2) t.insert(pool2[add]);
	}
	if(ans==INF) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}