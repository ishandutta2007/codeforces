/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-26 03:18:17
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,ans,p[MAXN],f[MAXN],F[MAXN];
ll s[MAXN];
int _mod(int x) {return x>=MOD?x-MOD:x;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
    for(int i=2;i<=n;i++) scanf("%d",&p[i]);
    for(int i=n;i>=2;i--) s[p[i]]+=s[i];
    for(int i=n;i>=1;i--)
    {
        ll x=s[1]/__gcd(s[1],s[i]);
        if(x<=n) f[x]++;
    }
    for(int i=n;i>=1;i--)
        for(int j=2*i;j<=n;j+=i)
            f[j]=_mod(f[j]+f[i]);
    F[1]=1;
    for(int i=1;i<=n;i++)
    {
        if(f[i]==i)
        {
            ans=_mod(ans+F[i]);
            for(int j=2*i;j<=n;j+=i)
                F[j]=_mod(F[j]+F[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}