#include <bits/stdc++.h>
using namespace std;
long double a[1000000];
int main()
{
    int n,k;
    cin>>n>>k;
    long double ret=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        long double sum=0;
        for (int j=i;j>=0;j--)
        {
            sum+=a[j];
            if (i-j+1 >= k)
            {
                ret=max(ret,sum/(i-j+1));
            }
        }
    }
    cout<<setprecision(10)<<fixed<<ret<<endl;
}