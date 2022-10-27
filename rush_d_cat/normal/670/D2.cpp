#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
typedef __int64 ll;
ll n,k,b[100000+2],c[100000+2];
bool ok(ll x)
{

    ll num=0;
    for(int i=1;i<=n;i++)
    {
        num += c[i]-x*b[i]<0?x*b[i]-c[i]:0;
        if(num>k) return false;
    }
    return true;

}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    ll l=0,r=2000000000+1;
    while(r-l>1)
    {
        ll mid = (l+r)/2;
        if(ok(mid)) l=mid;
        else r=mid;
    }
    cout<<l<<endl;
    return 0;
}