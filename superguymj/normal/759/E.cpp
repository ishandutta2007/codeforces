#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back

using namespace std;
typedef long long LL;
const int N=300005,mod=1000000007;
char s[10005];
int n,m,L,x,res,ans,siz,a[N],b[N];
LL c[2000];
vector <int> f[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void inc(int &x,int y)
{
	if((x+=y)>=mod) x-=mod;
}

void dec(int &x,int y)
{
	if((x-=y)<0) x+=mod;
}

int div(int x)
{
	repd(i,L-1,1)
	{
		c[i]+=c[i+1]%x*1000000000;
		if(!(c[i+1]/=x)) L=i;
	}
	int rt=(int)(c[1]%x);
	if(!(c[1]/=x)) L=0;
	return rt;
}

int main()
{
	n=getint(),a[n+1]=1e9;
	rep(i,2,n) a[i]=getint();
	rep(i,1,n) b[i]=getint();
	scanf("%s",s),m=strlen(s);
	for(int i=m-1; i>=0; i-=9)
	{
		++L;
		rep(j,max(0,i-8),i) c[L]=c[L]*10+s[j]-48;
	}
	f[1].pb(1);
	rep(i,1,n)
	{
		res=a[i+1]==1?0:div(a[i+1]),siz=f[i].size(),x=0;
		rep(j,0,siz+b[i]-1)
		{
			if(j<siz) inc(x,f[i][j]);
			if(j>b[i]) dec(x,f[i][j-b[i]-1]);
			if(j%a[i+1]==res) f[i+1].pb(x);
		}
		if(ans=i,!L) break;
	}
	printf("%d\n",(L || f[ans+1].empty())?0:f[ans+1][0]);
	return 0;
}