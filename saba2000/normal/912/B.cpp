#include<bits/stdc++.h>
using namespace std;
main()
{
    long long n,k;
    cin>>n >> k;
    long long x=1;
    if(k==1) cout<<n<<endl;
    else
    {
        while(2*x<=n) x*=2;
        cout<<2*x-1<<endl;
    }
}