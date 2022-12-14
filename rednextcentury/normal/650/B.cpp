#include <bits/stdc++.h>

using namespace std;
char f[1000000];
int cost1[1000000];
int cost2[1000000];
    int n,a,b,T;
int bs1(int s,int e,int t)
{
    int ans=n+1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if (cost2[mid]+(n-mid)*a<=t)
            ans=mid,e=mid-1;
        else
            s=mid+1;
    }
    return n-ans+1;
}
int bs2(int s,int e,int t)
{
    int ans=1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if (cost1[mid]-cost1[1]+(mid-2)*a<=t)
            ans=mid,s=mid+1;
        else
            e=mid-1;
    }
    return ans-1;
}
int main()
{
    cin>>n>>a>>b>>T;
    for (int i=1;i<=n;i++)
    {
        cin>>f[i];
        if (f[i]=='w')cost1[i]=b;
        cost1[i]++;
        cost1[i]+=cost1[i-1];
    }
    for (int i=n;i>=1;i--)
    {
        if (f[i]=='w')cost2[i]=b;
        cost2[i]++;
        cost2[i]+=cost2[i+1];
    }
    int cur_cost=0;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        cur_cost+=cost1[i]-cost1[i-1];
        if (T-cur_cost>=0)
            ans=max(ans,i);
        if (T-cur_cost-i*a>0)
        {


            int x=bs1(1,n,T-cur_cost-i*a);
            ans=max(ans,min(n,x+i));
        }
        cur_cost+=a;
    }
    cur_cost=a+cost1[1];
    for (int i=n;i>=1;i--)
    {
        cur_cost+=cost2[i]-cost2[i+1];

        if (T-cur_cost>=0)
            ans=max(ans,min(n,n-i+2));
        if (T-cur_cost-(n-i+2)*a>0)
        {


            int x=bs2(2,n,T-cur_cost-(n-i+2)*a);
            ans=max(ans,min(n,x+(n-i+2)));
        }
        cur_cost+=a;
    }
    cout<<ans<<endl;
}