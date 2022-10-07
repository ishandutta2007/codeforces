#include<bits/stdc++.h>
using namespace std;

main()
{
    long long n,k;
    cin >> n >>k;
    for (long long i=2; i<=min(k,(long long)100000); i++)
    {
        if(n%i!=(i-1)) {cout<<"No"<<endl; return 0;}
    }
    cout<<"Yes"<<endl;
}