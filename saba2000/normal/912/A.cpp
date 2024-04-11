#include<bits/stdc++.h>
using namespace std;
main()
{
    long long A,B,x,y,z;
    cin>>A>>B>>x>>y>>z;
    long long b=3*z+y,a=y+2*x;
    cout<<max((long long)0,b-B)+max((long long)0,a-A)<<endl;
}