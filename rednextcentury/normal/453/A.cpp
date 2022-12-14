#include<bits/stdc++.h>
using namespace std;
long double power(long double x,int y)
{
    if (y==0)
        return 1;
    long double h=power(x,y/2);
    return (y%2)?h*h*x:h*h;
}
int main()
{
    int m,n;
    cin>>m>>n;
    long double ans=0;
    for (int i=1;i<=m;i++)
        ans+=i*(power(((long double)(i))/m,n)-power(((long double)(i-1))/m,n));
    cout<<setprecision(6)<<fixed<<ans<<endl;
}