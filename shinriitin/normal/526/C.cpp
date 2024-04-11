#include<iostream>
#include<cmath>
using namespace std;
long long i,n,pa,pb,ha,hb,ans;
int main()
{
//  freopen("brush.in","r",stdin);
//  freopen("brush.out","w",stdout);
    cin>>n>>ha>>hb>>pa>>pb;
    long long  xx=floor(sqrt(n))+1;
    for(i=0;i<=xx;i++)
    if (i*pa<=n)
    {
        long long yy=i*ha+(n-i*pa)/pb*hb;
        ans=yy>ans?yy:ans;  
    }
    for(i=0;i<=xx;i++)
    if (i*pb<=n)
    {
        long long yy=i*hb+(n-i*pb)/pa*ha;
        ans=yy>ans?yy:ans;  
    }
    cout<<ans;
    return 0;
}