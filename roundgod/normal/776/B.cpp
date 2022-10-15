#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
int prime[MAXN];
bool is_prime[MAXN];
int n,t,a[MAXN];
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
    scanf("%d",&n);
    if (n==1)
    {
        printf("1\n");
        printf("1");
        return 0;
    }
    if (n==2)
    {
        printf("1\n");
        printf("1 1\n");
        return 0;
    }
    sieve(n+1);
    printf("2\n");
    for(int i=2;i<=n+1;i++)
        if(is_prime[i]) printf("1 "); else printf("2 ");
    return 0;
}