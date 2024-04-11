#include<iostream>
# include <iomanip>
using namespace std;
long double a[10000];
long double b[10000];
int main()
{
    long double ans=1;
    int n,m,h;
    cin>>n>>m>>h;
    long double sum=0;
    long double k=0;
    for (int i=1;i<=m;i++)
    {
        long double f;
        cin>>f;
        if (i==h)
            k=f;
        else
            sum+=f;
    }
    if (sum+k<n)
    {
        cout<<-1<<endl;
        return 0;
    }
    if (sum<n-1)
    {
        cout<<1<<endl;
        return 0;
    }
    int j=sum+k-n+1;
    int i=sum-n+2;
    while(1)
    {
        if (i<=sum)
            ans*=(long double)(i);
        if (j<=sum+k-1)
            ans/=(long double)(j);
        if (i>sum && j>sum+k-1)
            break;
        i++;
        j++;
    }
    cout<<setprecision(7)<<fixed<<1.0-ans<<endl;
}