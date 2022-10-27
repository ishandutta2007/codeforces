#include<iostream>
using namespace std;
typedef __int64 ll;
ll n,A,d[200000+2],sum;
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a>b?b:a;}
int main()
{
    cin>>n>>A;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];sum+=d[i];
    }
    for(int i=1;i<=n;i++)
    {
        ll l=max(A+d[i]-sum,1);
        ll r=min(A+1-n,d[i]);
        ll res=d[i]-r+l-1;
        cout<<res;
        if(i!=n) cout<<" ";
    }
    return 0;
}