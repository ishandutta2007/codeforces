#include <iostream>
using namespace std;
main()
{long long t,n;
cin>>t;
for (int i=0; i<t; i++)
{cin>>n; int k=1;
for (int i=n; i!=0; i/=2)
k*=2;
cout<<(long long)(n*(n+1)/2-(2*k-2))<<endl;
}}