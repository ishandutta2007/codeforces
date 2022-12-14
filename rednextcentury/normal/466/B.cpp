#include<bits/stdc++.h>
using namespace std;
long long ans=1000000000000000LL;
long long aa,bb;
    long long n,a,b;
void sol(long long x,long long y)
{
    if (x<a)
        x=a;
    if (y<b)
        y=b;
    if (x*y<ans)
    {
        ans=x*y;
        aa=x,bb=y;
    }
}
int main()
{
    cin>>n>>a>>b;
    if (a*b>=6*n)
        cout<<a*b<<endl<<a<<' '<<b<<endl;
    else
    {
        long long m=6*n;
        for (long long i=1;i*i<=m;i++)
        {
            if (m%i==0)
            {
                long long x=i,y=m/i;
                sol(x,y);
                sol(y,x);
            }
            else
            {
                long long x=i,y=m/i+1;
                sol(x,y);
                sol(y,x);

            }
        }
        cout<<ans<<endl<<aa<<' '<<bb<<endl;
    }
}