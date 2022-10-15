#include<bits/stdc++.h>
#define MAXN 40005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,x,d,p;
int prime[MAXN];
bool is_prime[MAXN];
vector<P> fact;
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
void factorize(int x)
{
	fact.clear();
	for(int i=0;i<p;i++)
	{
		if(x%prime[i]==0)
		{
			int cnt=0;
			while(x%prime[i]==0) x/=prime[i],cnt++;
			fact.push_back(P(prime[i],cnt));
		}
	}
	if(x>1) fact.push_back(P(x,1));
}
int main()
{
	p=sieve(40000);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&d);
		if(x%d) {puts("NO"); continue;}
		if(1LL*d*d==x) {puts("NO"); continue;}
		if(x%(1LL*d*d)) {puts("NO"); continue;}
		int tmp=x,pcnt=0;
		while(tmp%d==0) tmp/=d,pcnt++;
		factorize(d);
		if(fact.size()==1)
		{
			if(fact[0].S==1)
			{
				factorize(tmp);
				int cnt=0;
				for(auto p:fact) cnt+=p.S;
				if(cnt<=1) puts("NO"); else puts("YES");
			}
			else if(fact[0].S==2&&pcnt==3&&tmp==fact[0].F) puts("NO");
			else if(pcnt>=3) puts("YES");
			else
			{
				factorize(tmp);
				int cnt=0;
				for(auto p:fact) cnt+=p.S;
				if(cnt<=1) puts("NO"); else puts("YES");
			}
		}
		else 
		{
			if(pcnt>=3) puts("YES");
			else
			{
				factorize(tmp);
				int cnt=0;
				for(auto p:fact) cnt+=p.S;
				if(cnt<=1) puts("NO"); else puts("YES");
			}
		}
	}
	return 0;
}