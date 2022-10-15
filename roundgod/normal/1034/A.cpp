/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-26 01:21:19
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define MAXA 15000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int prime[MAXA],fact[MAXA];
bool is_prime[MAXA];
int cnt[MAXA];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; fact[i]=i;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            fact[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    int cur=0;
    int p=sieve(15000000);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); cur=__gcd(cur,a[i]);}
    for(int i=1;i<=n;i++) a[i]/=cur;
    for(int i=1;i<=n;i++)
    {
        for(int x=a[i];x>1;)
        {
            cnt[fact[x]]++;
            int c=fact[x];
            while(x%c==0) x=x/c;
        }
    }
    int ans=n;
    for(int i=2;i<=15000000;i++)
        ans=min(ans,n-cnt[i]);
    if(ans==n) puts("-1"); else printf("%d\n",ans);
    return 0;
}