# include <iostream>
# include <vector>
# include <cstring>
#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
long long a[1000000];
long long sum;
int main()
{
    long long n,s;
    cin>>n>>s;
    for (int i=0;i<n;i++)
        cin>>a[i],sum+=a[i];
    if (n==1)
        cout<<a[0]-1<<endl;
    else
    {
        for (int i=0;i<n;i++)
        {
            long long mn=1,mx=a[i];
            long long Sum=sum-a[i];
            mx=min(a[i],s-n+1);
            if (Sum<s)
                mn=s-Sum;
               
            cout<<a[i]-(mx-mn+1)<<" ";
        }
        cout<<endl;
    }
}