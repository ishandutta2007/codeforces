#include<iostream>
using namespace std;
main()
{long long n,ans=0,k=2;
cin>>n;
for (int i=0; i<n; i++)
{ans+=k;
k*=2;}
cout<<ans<<endl;
}