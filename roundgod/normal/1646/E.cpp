#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
bool valid[20*MAXN];
int ans[21];
int prime[MAXN];
bool is_prime[MAXN];
int fact[MAXN];
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
int main()
{
	
	scanf("%d%d",&n,&m);

	int p=sieve(n);
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!valid[i*j])
			{
				ans[i]++;
				valid[i*j]=true;
			}
		}
	}
	for(int i=0;i<p;i++)
	{
		for(int j=prime[i];j<=n;j+=prime[i])
		{
			int cnt=0,tmp=j;
			while(tmp%prime[i]==0) cnt++,tmp/=prime[i];
			fact[j]=__gcd(fact[j],cnt);
		}
	}
	ll res=1;
	for(int i=2;i<=n;i++) 
		res+=ans[fact[i]];
	printf("%lld\n",res);
}