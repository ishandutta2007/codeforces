#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long uns;
struct rtime
{
    uns s,e;
};
bool cmp(rtime x,rtime y)
{
    return x.s<y.s;
}
int main()
{
    uns n,p1,p2,p3,t1,t2,ans=0; cin>>n>>p1>>p2>>p3>>t1>>t2;
    rtime data[n+1];
    for(uns i=1;i<=n;i++) cin>>data[i].s>>data[i].e;
    for(uns i=1;i<=n;i++)
    {
        ans+=(data[i].e-data[i].s)*p1;
        if(i==1) continue;
        uns dt=data[i].s-data[i-1].e;
        if(dt>=t1) ans+=t1*p1,dt-=t1;
        else
        {
            ans+=dt*p1; continue;   
        }
        if(dt>=t2) ans+=t2*p2,dt-=t2;
        else
        {
            ans+=dt*p2; continue;   
        }
        if(dt>0) ans+=dt*p3;
    }
    cout<<ans<<endl;
    return 0;
}