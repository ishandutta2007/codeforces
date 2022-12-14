#include<bits/stdc++.h>
using namespace std;
#define mid (l+r)/2
int main()
{
    long long n,k;
    cin>>n>>k;
    long long X=0;
    long long l=0,r=n/k;
    while(l<=r)
    {
        if (mid*(k+1)>n/2)
            r=mid-1;
        else
            X=mid,l=mid+1;
    }
    cout<<X<<' '<<k*X<<' '<<n-(k+1)*X<<endl;
}