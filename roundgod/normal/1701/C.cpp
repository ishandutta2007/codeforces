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
int t,n,m,a[MAXN];
int cnt[MAXN];
bool check(int x)
{
    ll rem=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]>=x)
        {
            rem-=(cnt[i]-x);
        }
        else rem+=(x-cnt[i])/2;
    }
    return (rem>=0);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=m;i++)
        {
            int x;scanf("%d",&x);
            cnt[x]++;
        }
        int l=0,r=2*m;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(check(mid)) r=mid; else l=mid;
        }
        printf("%d\n",r);
    }
    return 0;
}