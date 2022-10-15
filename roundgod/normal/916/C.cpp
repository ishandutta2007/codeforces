#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
using namespace std;
int n,m;
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
	scanf("%d%d",&n,&m);
	int p=sieve(100005);
	int save=0;
	for(int i=0;i<p;i++)
		if(prime[i]>n-2) {save=prime[i]; break;}
	printf("%d %d\n",save,save);
	for(int i=1;i<=n-1;i++)
	{
		if(i!=n-1) printf("%d %d %d\n",i,i+1,1);
		else printf("%d %d %d\n",i,i+1,save-n+2); 
	}
	int cnt=m-n+1;
	for(int i=1;i<=n;i++)
	{
		if(cnt==0) break;
		for(int j=i+2;j<=n;j++)
		{
			printf("%d %d %d\n",i,j,INF);
			cnt--;
			if(cnt==0) break;
		}
	}
	return 0;
}