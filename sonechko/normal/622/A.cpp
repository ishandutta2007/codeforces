#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long l=0, r=(long long)sqrt(n)*5;
    while (r-l>1)
    {
        long long k=(l+r)/2;
        if ((k*(k+1))/2>=n) r=k; else l=k;
    }
long long k=r;
    if ((k*(k+1))/2<n) l=r;
    k = (l*(l+1))/2;
    n=n-k;
    cout<<n<<endl;
}