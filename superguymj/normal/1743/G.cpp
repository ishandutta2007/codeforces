#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
typedef long long LL;
const int N=1005,M=35,mod=998244353;
int n,m,fib[M];
char s[N];
struct D{int i,l; LL cnt;} ;
vector <D> F,G;
LL ans,tot;

int get(int i,int x)
{
	if(i==0)
	{
		if(x>1) return -1;
		return 0;
	}
	if(i==1)
	{
		if(x>1) return -1;
		return 1;
	}
	if(x<=fib[i-1]) return get(i-1,x);
	return get(i-2,x-fib[i-1]);
} 

void ins(int c)
{
	G.clear();
	for(auto f:F)
	{
		int i=f.i;
		int l=f.l;
		int cnt=f.cnt;
		if(!i) continue;
		if(c!=get(i+1,l+1)) continue;
		++l;
		if(l==fib[i+1]) ++i;
		G.pb((D){i,l,cnt});
	}
	if(c==0) G.pb((D){0,1,ans});
	else G.pb((D){1,1,ans});
	ans=tot;
	for(auto g:G) if(g.l==fib[g.i]) ans=(ans-g.cnt+mod)%mod;
	tot=(tot+ans)%mod;
	F=G;
}

int main()
{
	fib[0]=fib[1]=1;
	rep(i,2,33) fib[i]=fib[i-1]+fib[i-2];
	ans=tot=1;
	scanf("%d",&n);
	rep(i,1,n)
	{
		scanf("%s",s+1),m=strlen(s+1);
		rep(j,1,m) 
			ins(s[j]-48);
		printf("%lld\n",ans);
	}
	return 0;
}