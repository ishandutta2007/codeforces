#include<iostream>

using namespace std;

#define MAXI 10000000000000

long long a[100001];

int main ()
{
    long long n,i,mini=MAXI,f,res=MAXI;

    cin>>n;

    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=0;i<n;i++)
    {
        if(mini>a[i])
        {
            mini=a[i];
            f=i;
        }
    }

    for(i=f+1;i<n;i++)
    {
        if(mini==a[i])
        {
            if(i-f<res)res=i-f;
            f=i;
        }
    }

    cout<<res<<endl;

    return 0;
}