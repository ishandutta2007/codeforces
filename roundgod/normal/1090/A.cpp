/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-09 16:22:44
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],mx[MAXN];
int main()
{
    scanf("%d",&n);
    int maxi=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        for(int j=0;j<a[i];j++)
        {
            int x;scanf("%d",&x);
            mx[i]=max(mx[i],x);
        }
        maxi=max(maxi,mx[i]);
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=1LL*a[i]*(maxi-mx[i]);
    printf("%lld\n",ans);
    return 0;
}