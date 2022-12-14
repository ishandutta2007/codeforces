#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x,y,z,t1,t2,t3;
    cin>>x>>y>>z>>t1>>t2>>t3;
    long long stairs = abs(x-y)*t1;
    long long elevator = abs(z-x)*t2+t3+t3+abs(y-x)*t2+t3;
    if (elevator<=stairs)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}