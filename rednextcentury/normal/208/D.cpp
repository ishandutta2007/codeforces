#include <cstdio>
# include <iostream>
# include <string>
# include <set>
# include <queue>
# include <cstring>
# include <algorithm>
# include <cstdlib>
# include <ios>
using namespace std;
long long a[5];
long long num[5];
long long sum;
long long x[1000000];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    long long n;
    cin>>n;
    for (long long i=0;i<n;i++)
        cin>>x[i];
    for (long long i=0;i<5;i++)
        cin>>a[i];

    for (long long i=0;i<n;i++)
    {
        sum+=x[i];
        for (long long j=4;j>=0;j--)
        {
            num[j]+=sum/a[j];
            sum=sum%a[j];
        }
    }
    for (long long i=0;i<5;i++)
        cout<<num[i]<<" ";
    cout<<endl;
    cout<<sum<<endl;
}