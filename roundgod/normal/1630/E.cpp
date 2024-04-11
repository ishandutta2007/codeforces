#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN],cnt[MAXN];
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
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
vector<int> v;
int prime[MAXN],phi[MAXN];
bool is_prime[MAXN];
int fact[MAXN],invf[MAXN];
int sieve(int n)
{
    int p=0;
    phi[1]=1;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; phi[i]=i-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            phi[i*prime[j]]=phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int calc_ans(int d)
{
	int res=0,sum=n/d;
	int inv=pow_mod(n/d-1,MOD-2);
	for(int i=0;i<(int)v.size();i++)
	{
		add(res,1LL*(v[i]/d)*(sum-v[i]/d)%MOD*(2*inv)%MOD);
		sum-=v[i]/d;
	}
	res=1LL*res*d%MOD;
	return res;
}
int main()
{
	fact[0]=1;
	for(int i=1;i<=1000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
	invf[1000000]=pow_mod(fact[1000000],MOD-2);
	for(int i=999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
	sieve(1000000);
	scanf("%d",&t);
	while(t--)
	{
		v.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		int g=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt[i])
			{
				g=__gcd(g,cnt[i]);
				v.push_back(cnt[i]);
			}
		}
		if(v.size()==1)
		{
			puts("1");
			continue;
		}
		int ans=0,sum=0;
		for(int i=1;i<=g;i++)
		{
			if(g%i) continue;
			int f=calc_ans(i);
			int c=fact[n/i];
			for(auto x:v) c=1LL*c*invf[x/i]%MOD;
			c=1LL*c*phi[i]%MOD;
			add(ans,1LL*f*c%MOD);
			add(sum,c);
		}
		ans=1LL*ans*pow_mod(sum,MOD-2)%MOD;
		printf("%d\n",ans);
	}
	return 0;
}