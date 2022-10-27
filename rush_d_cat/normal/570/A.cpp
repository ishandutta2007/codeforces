#include<iostream>
using namespace std;
typedef __int64 ll;
ll n,m,a[102];
int main()
{
    cin>>m>>n;
    memset(a,0,sizeof(a));
    for(ll i=1;i<=n;i++)
    {
        ll maxn=-1,win=0;
        for(ll j=1;j<=m;j++)
        {
            ll tmp;cin>>tmp;
            if(tmp>maxn){
                maxn=tmp;
                win=j;
            }
        }
        a[win]++;
    }
    ll maxn=-1,ans=0;

    for(ll i=1;i<=m;i++)
    {
        if(a[i]>maxn)
        {
            maxn=a[i];
            ans=i;
        }
    }

    cout<<ans<<endl;
    return 0;
}