/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-23 22:55:24
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p[MAXN],mx[MAXN],cnt[MAXN];
int prime[MAXN],fact[MAXN];
bool is_prime[MAXN];
int form[MAXN];
void add(int p,int x) 
{
    if(x>mx[p]) 
    {
        mx[p]=x;
        cnt[p]=1;
    }
    else if(x==mx[p]) cnt[p]++;
}
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
int main()
{
    scanf("%d",&n);
    int pp=sieve(2000000);
    for(int i=0;i<n;i++) scanf("%d",&p[i]);
    int ans=1;
    sort(p,p+n);
    for(int i=n-1;i>=0;i--)
    {
        int x=p[i];
        if(!mx[x]) {add(x,1); form[i]=x;}
        else
        {
            form[i]=x-1;
            for(x=p[i]-1;x>1;)
            {
                int v=fact[x],c=0;
                while(x%v==0) x=x/v,c++;
                add(v,c);
            }
        }
    }
    int s=0;
    for(int i=n-1;i>=0;i--)
    {
        int x=p[i];
        if(form[i]==x)
        {
            if(mx[x]>1||(mx[x]==1&&cnt[x]>1)) {s=1; break;}
        }
        else
        {
            bool f=false;
            for(x=p[i]-1;x>1;)
            {
                int v=fact[x],c=0;
                while(x%v==0) x=x/v,c++;
                if(mx[v]==c&&cnt[v]==1) {f=true; break;}
            }
            if(!f) {s=1; break;}
        }
    }
    for(int i=0;i<pp;i++)
        ans=1LL*ans*pow_mod(prime[i],mx[prime[i]])%MOD;
    printf("%d\n",(ans+s)%MOD);
    return 0;
}