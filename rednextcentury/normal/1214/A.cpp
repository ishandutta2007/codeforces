#include <bits/stdc++.h>
using namespace std;
long long solve(long long n,long long x,long long y)
{
    long long orz=n;
    long long mx = n/x;
    n=n%x;
    long long ret=n%y;
    for (long long i=1;i<=mx;i++)
    {
        long long cur = n+x*i;
        if (cur>orz)break;

        ret=min(ret,cur%y);
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    long long n;
    long long a,b;
    cin>>n>>a>>b;
    b=b*5;
    long long x = min(solve(n,a,b),solve(n,b,a));
    cout<<x<<endl;
}