#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
typedef __int64 ll;
const ll inf=1000000000;
const int maxn=1000000+10;
ll a,b,n,m,t,l;
ll sum[maxn];
bool ok(ll x)
{
    if(((m*t)>=sum[x]-sum[l-1])&&(x>=l)&&(b*(x-1)+a)<=t) return 1;
    else return 0;
}
int main()
{
    cin>>a>>b>>n;
    for(ll i=1;i<=1000000;i++)
    {
        sum[i]=i*a+(i-1)*i/2*b;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>l>>t>>m;

        ll R=maxn,L=l,mid;
        while(R-L>1)
        {
            mid=(L+R)/2;
            if(ok(mid))
            {
                L=mid;
            }else{
                R=mid;
            }
        }
        if(ok(L)) cout<<L<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}