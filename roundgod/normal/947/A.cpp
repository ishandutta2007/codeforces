#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int prime[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}
int main()
{
	int p=sieve(1000000);
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	int ans=n;
	for(int i=0;i<p;i++)
		for(int j=prime[i]*2;j<=1000000;j+=prime[i])
			a[j]=j-prime[i]+1;
	for(int i=0;i<p;i++)
	{
		if(n%prime[i]!=0) continue;
		for(int j=n-prime[i]+1;j<=n;j++)
		{
			if(is_prime[j]) continue;
			ans=min(ans,a[j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}