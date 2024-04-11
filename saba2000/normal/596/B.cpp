#include<iostream>
#include<cmath>
using namespace std;
long long n,b,k,ans;
main()
{
cin>>n;
for (int i=0; i<n; i++)
{cin>>b;
ans+=abs(b-k);
k=b;         
}
cout<<ans<<endl;
}