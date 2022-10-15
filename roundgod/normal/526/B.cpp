/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-12 10:59:17
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
int n,a[MAXN],cnt[MAXN],save[MAXN];
int main()
{
    scanf("%d",&n);
    n=(1<<(n+1))-1;
    for(int i=2;i<=n;i++) scanf("%d",&a[i]);
    int mx=0;
    for(int i=(n+1)/2;i<=n;i++)
    {
        int now=i;
        while(now!=1)
        {
            cnt[i]+=a[now];
            now=now/2;
        }
        mx=max(cnt[i],mx);
    }
    for(int i=n/2;i>=1;i--) cnt[i]=max(cnt[i*2],cnt[i*2+1]);
    int ans=0;
    for(int i=2;i<=n;i++) 
    {
        cnt[i]+=save[i];
        if(cnt[i]<=mx)
        {
            ans+=mx-cnt[i];
            save[i]+=mx-cnt[i];
            save[2*i]+=save[i];save[2*i+1]+=save[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}