#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll n,s;
int check(ll mid)
{
    ll res=n,num=1,sum=0,dep=1;
    while(res)
    {
        sum+=min(num,res)*dep;
        if(sum>s)
            return 0;
        res-=min(num,res);
        num*=mid;
        dep++;
    }
    return 1;
}
int fa[N],dep[N];
vector<int>vec[N];
int main()
{
    scanf("%lld%lld",&n,&s);
    if(n+n-1>s||(n+1)*n/2<s)
        return 0*printf("No\n");
    ll l=1,r=n,mid,ans=1;
    while(r>=l)
    {
        mid=l+r>>1;
        if(check(mid))
            r=mid-1,ans=mid;
        else
            l=mid+1;
    }
    printf("Yes\n");
    ll sum=(n+1)*n/2,head=2;
    for(int i=1;i<=n;i++)
        fa[i]=i-1,dep[i]=1;
    for(int i=n;i>=2;i--)
    {
        if(sum==s)
            break;
        if(dep[head]>=dep[head-1]*ans)
            head++;
        if(sum-s>=i-head)
        {
            dep[head]++,dep[i]--;
            sum-=(i-head);
        }
        else
        {
            dep[i-(sum-s)]++;
            dep[i]--;
            sum=s;
        }
    }
    vec[1].push_back(1);
    head=1;
    int now=2;
    while(now<=n)
    {
        for(int j=0;j<dep[head+1]&&now<=n;j++)
        {
            printf("%d ",vec[head][j/ans]);
            vec[head+1].push_back(now++);
        }
        head++;
    }
    printf("\n");
    return 0;
}