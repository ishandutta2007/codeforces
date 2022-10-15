#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
vector<pair<int,P> > G[MAXN];
int a[MAXN],b[MAXN];
int maxi[MAXN];
int prime[MAXN];
bool is_prime[MAXN];
vector<P> fact[MAXN];
int inv[MAXN];
int val[MAXN],sum;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int pow_mod(int a,int i)
{
	int s=1;
	while(i)
	{
		if(i&1) s=1LL*s*a%MOD;
		a=1LL*a*a%MOD;
		i>>=1;
	}
	return s;
}
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
void change(int x,int y)// /x *y
{
	for(auto p:fact[x]) b[p.F]+=p.S;
	for(auto p:fact[y]) a[p.F]+=p.S;
	for(auto p:fact[x]) {int z=min(a[p.F],b[p.F]); a[p.F]-=z; b[p.F]-=z; maxi[p.F]=max(maxi[p.F],b[p.F]);}
	for(auto p:fact[y]) {int z=min(a[p.F],b[p.F]); a[p.F]-=z; b[p.F]-=z; maxi[p.F]=max(maxi[p.F],b[p.F]);}
}
void dfs(int v,int p)
{
	add(sum,val[v]);
	for(auto e:G[v])
	{
		int to=e.F,x=e.S.F,y=e.S.S;
		if(to==p) continue;
		val[to]=1LL*val[v]*y%MOD*inv[x]%MOD;
		change(x,y);
		dfs(to,v);
		change(y,x);
	}
}
int main()
{
	scanf("%d",&t);
	int p=sieve(200000);
	for(int i=0;i<p;i++)
	{
		for(int j=prime[i];j<=200000;j+=prime[i])
		{
			int tmp=j/prime[i],cnt=1;
			while(tmp%prime[i]==0) cnt++,tmp/=prime[i];
			fact[j].push_back(P(i,cnt));
		} 
	}
	inv[1]=1;
    for (int i=2;i<=200000;i++)
        inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=0;i<n-1;i++)
		{
			int u,v,x,y;
			scanf("%d%d%d%d",&u,&v,&x,&y);
			G[u].push_back(make_pair(v,P(x,y)));
			G[v].push_back(make_pair(u,P(y,x)));
		}
		for(int i=0;i<p;i++) a[i]=b[i]=maxi[i]=0;
		val[1]=1; sum=0;
		dfs(1,0);
		for(int i=0;i<p;i++) sum=1LL*sum*pow_mod(prime[i],maxi[i])%MOD;
		printf("%d\n",sum);
	}
	return 0;
}