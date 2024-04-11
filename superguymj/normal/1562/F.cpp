#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<ctime>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005,lim=200000,K1=100,K2=50;
bool vis[N];
int n,prm[N],mxp,m,a[N],id[N];
typedef long long LL;
LL f[105][105],tmp[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

LL gcd(LL a,LL b)
{
	return !b?a:gcd(b,a%b);
}

LL query(int x,int y)
{
//	return tmp[x]*tmp[y]/gcd(tmp[x],tmp[y]);

	printf("? %d %d\n",x,y),fflush(stdout);
	LL ret;
	scanf("%lld",&ret);
	return ret;
}

LL calc(int p)
{
	LL ret=0;
	rep(i,1,n) if(i!=p) ret=gcd(ret,f[i][p]);
	return ret;
}

void PRT()
{
	printf("!");
	rep(i,1,n) printf(" %d",a[i]);
	puts(""),fflush(stdout);
}

void solve1()
{
	rep(i,1,n) rep(j,1,i-1) f[i][j]=f[j][i]=query(i,j);
	rep(i,1,n) a[i]=calc(i);
	if(n==3)
	{
		int mn=lim;
		rep(i,1,n) mn=min(mn,a[i]);
		if(!(mn&1)) rep(i,1,n) if(a[i]==(mn+1)*2) a[i]/=2;
	}
	PRT();
}

void solve2()
{
	srand(time(0));
	rep(i,1,n) id[i]=i;
	random_shuffle(id+1,id+1+n);
	mxp=0,m=0;
	rep(i,1,min(n,K1))
	{
		int x=id[i];
		LL p=0;
		rep(j,1,K2)
		{
			int y=rand()%n+1;
			while(x==y) y=rand()%n+1;
			p=gcd(query(x,y),p);
		}
		if(p<=lim && !vis[p] && p>mxp) mxp=p,m=x;
	}
	a[m]=mxp;
	rep(i,1,n) if(i!=m) a[i]=query(m,i)/mxp;
	PRT();
}

void solve()
{
	n=getint();
//	rep(i,1,n) tmp[i]=getint();
	if(n<=100) solve1();
	else solve2();
}

void pre()
{
	n=lim,vis[1]=1;
	rep(i,2,n)
	{
		if(!vis[i]) prm[++*prm]=i;
		rep(j,1,*prm)
		{
			if(i*prm[j]>n) break;
			vis[i*prm[j]]=1;
			if(i%prm[j]==0) break;
		}
	}
}

int main()
{
	pre();
	int T=getint();
	while(T--) solve();
	return 0;
}