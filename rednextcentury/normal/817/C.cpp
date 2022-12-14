#include<bits/stdc++.h>
using namespace std;
long long s;
long long getSum(long long x)
{
    long long ret=0;
    while(x!=0)
    {
        ret+=x%10;
        x/=10;
    }
    return ret;
}
long long bs(long long l,long long r)
{
    long long ret=r+1;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if (mid-getSum(mid)<s)
            l=mid+1;
        else
            ret=mid,r=mid-1;
    }
    return ret;
}
int main()
{
    long long n;
    cin>>n>>s;
    cout<<n-bs(1,n)+1<<endl;
}