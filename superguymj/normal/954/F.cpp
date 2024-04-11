#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=10005,mod=1000000007;
int n,a,b[5],tot;
LL m,f[5],f1[5],mxt[5][5],mxt1[5][5];
struct data{LL a,x,c;} pool[N<<2];

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

bool cmp(data a,data b)
{
	return a.x<b.x;
}

void solve(LL x)
{
	while(x)
	{
		if(x&1)
		{
			memset(f1,0,sizeof(f1));
			rep(i,1,3) rep(j,1,3) f1[i]=(f1[i]+mxt[i][j]*f[j])%mod;
			rep(i,1,3) f[i]=f1[i];
		}
		memset(mxt1,0,sizeof(mxt1));
		rep(i,1,3) rep(j,1,3) rep(k,1,3) mxt1[i][j]=(mxt1[i][j]+mxt[i][k]*mxt[k][j])%mod;
		rep(i,1,3) rep(j,1,3) mxt[i][j]=mxt1[i][j];
		x>>=1;
	}
}

int main()
{
	n=getint(),m=getLL();
	rep(i,1,n)
		a=getint(),pool[++tot]=(data){a,getLL(),1},pool[++tot]=(data){a,getLL()+1,-1};
	pool[++tot]=(data){1,1,1},pool[++tot]=(data){3,1,1};
	pool[++tot]=(data){1,2,-1},pool[++tot]=(data){3,2,-1};
	pool[++tot]=(data){0,m+1,0};
	sort(pool+1,pool+1+tot,cmp),f[2]=1;
	for(int i=1,p; i<tot; ++i)
	{
		b[pool[i].a]+=pool[i].c,p=i;
		while(pool[p].x==pool[p+1].x)
			++p,b[pool[p].a]+=pool[p].c;
		i=p;
		rep(j,1,3) if(!b[j]) f1[j]=(f[j-1]+f[j]+f[j+1])%mod; else f1[j]=0;
		rep(j,1,3) f[j]=f1[j];
		rep(j,1,3)
			rep(k,1,3)
				if(abs(j-k)<2 && !b[j] && !b[k])
					mxt[j][k]=1;
				else mxt[j][k]=0;
		solve(pool[i+1].x-pool[i].x-1);
	}
	printf("%lld\n",f[2]);
	return 0;
}