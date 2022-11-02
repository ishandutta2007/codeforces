#include<cstdio>
#include<algorithm>

#define mo 1000000007
 
using namespace std;
 
long long m,n,l,r,ans;
 
int main()
{
    scanf("%I64d%I64d",&n,&m);
    ans=0;
    if(m>n){ans+=(m-n)%mo*(n%mo)%mo;m=n;}
    for(long long i=1;i<=n;)
    {
        l=n/(i+1)+1;
        r=min((n/i),m);
        if(l<=r)ans+=(n%l+n%r)%mo*((r-l+1)%mo)%mo*(((mo+1)/2)%mo)%mo;
        if(ans>=mo)ans-=mo;
        if(i==n)break;
        i=n/(n/(i+1));
    }
    printf("%I64d\n",ans);
}