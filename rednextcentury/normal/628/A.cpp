#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long n,b,p;
    cin>>n>>b>>p;
    long long a=0,bb=0;
    bb=p*n;
    while(n!=1)
    {
        long long k=1;
        while(k*2<=n)
            k*=2;
        a+=b*k + k/2;
        n=k/2+n-k;
    }
    cout<<a<<" "<<bb<<endl;
}