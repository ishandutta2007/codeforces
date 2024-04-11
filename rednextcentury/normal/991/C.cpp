#include<bits/stdc++.h>
using namespace std;
long long check(long long n,long long k)
{
    long long cur=0;
    long long x=n;
    while(x)
    {
        cur+=min(x,k);
        x-=min(x,k);
        x-=(x/10);
    }
    return cur;
}
int main()
{
    long long n;
    cin>>n;
    long long l=1,r=n;
    long long need = n/2 + n%2;
    long long ans=n;
    while(l<=r)
    {
        long long md = (l+r)/2;
        if (check(n,md)>=need)ans=md,r=md-1;
        else l=md+1;
    }
    cout<<ans<<endl;
}