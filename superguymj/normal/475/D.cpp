#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
const int N=100005,M=33,mod=19260817;
int n,m,x,a[20][N],bin[N],pool[mod],nxt[N*M],tot;
typedef long long LL;
struct data{int id; LL siz;} dat[N*M];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}

void build()
{
	rep(i,2,n) bin[i]=bin[i>>1]+1;
	rep(i,1,bin[n])
		rep(j,1,n)
			if(j+(1<<i-1)<=n) a[i][j]=gcd(a[i-1][j],a[i-1][j+(1<<i-1)]);
			else a[i][j]=a[i-1][j];
}

int get_gcd(int l,int r)
{
	int siz=r-l+1;
	return gcd(a[bin[siz]][l],a[bin[siz]][r-(1<<bin[siz])+1]);
}

int find(int x,int l)
{
	int r=n,y=get_gcd(x,l);
	while(l<=r) if(get_gcd(x,mid)==y) l=mid+1; else r=mid-1;
	return l-1;
}

void insert(int x,int y)
{
	int id=x%mod,p=pool[id];
	while(p)
	{
		if(dat[p].id==x)
		{
			dat[p].siz+=y;
			return;
		}
		p=nxt[p];
	}
	nxt[++tot]=pool[id],pool[id]=tot;
	dat[tot]=(data){x,y};
}

LL query(int x)
{
	int id=x%mod,p=pool[id];
	while(p)
	{
		if(dat[p].id==x) return dat[p].siz;
		p=nxt[p];
	}
	return 0;
}

int main()
{
	n=getint();
	rep(i,1,n) a[0][i]=getint();
	build();
	rep(i,1,n)
	{
		int x=i;
		while(x<=n)
		{
			int y=find(i,x);
			insert(get_gcd(i,x),y-x+1),x=y+1;
		}
	}
	m=getint();
	while(m--) x=getint(),printf("%lld\n",query(x));
	return 0;
}