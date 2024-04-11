#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
typedef __int64 ll;
struct node{
    ll m,s;
}p[100000+10];
ll n,d;
bool cmp(node a,node b)
{
    return a.m<b.m;
}
int main()
{
    ll res=0,ans=0;
    cin>>n>>d;
    for(ll i=1;i<=n;i++)
    {
        cin>>p[i].m>>p[i].s;
    }
    sort(p+1,p+1+n,cmp);
    ll j=1;
    for(ll i=1;i<=n;i++)
    {
        while(j<=n&&p[j].m-p[i].m<d)
        {
            res+=p[j].s;
            j++;
        }
        ans=max(ans,res);
        res-=p[i].s;
    }
    cout<<ans<<endl;
}