/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-25 00:43:09
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],cnt[MAXN];
bool used[MAXN];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=2*n;i++)
        scanf("%lld",&a[i]);
    ll ans=0;
    memset(used,false,sizeof(used));
    for(ll i=1;i<=n-1;i++)
    {
        ll id=-1,num=INF;
        memset(cnt,0,sizeof(cnt));
        for(ll j=2*i-1;j<=2*n;j++)
            cnt[a[j]]+=j;
        for(ll j=1;j<=n;j++)
        {
            if(!used[j]&&cnt[j]<num)
            {
                num=cnt[j];
                id=j;
            }
        }
        //printf("%lld %lld\n",id,num);
        used[id]=true;
        ans+=num-(2*i-1)-(2*i);
        for(ll j=2*i-1;j<=2*n;j++)
        {
            if(a[j]==id)
            {
                for(ll k=j;k>=2*i;k--)
                    a[k]=a[k-1];
                a[2*i-1]=id;
                break;
            }
        }
        for(ll j=2*i;j<=2*n;j++)
        {
            if(a[j]==id)
            {
                for(ll k=j;k>=2*i+1;k--)
                    a[k]=a[k-1];
                a[2*i]=id;
                break;
            }
        }
        /*for(ll i=1;i<=2*n;i++)
            printf("%lld ",a[i]);
        puts("");*/
    }
    printf("%lld\n",ans);
    return 0;
}