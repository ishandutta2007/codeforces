#include<iostream>
#include<cmath>
using namespace std;
long long n,m,k,q,ans,p;
main()
{
q=1;
cin>>n>>m;
for (int i=0; i<m; i++)
{cin>>p;
ans+=(p-q+n)%n;
q=p;
}
cout<<ans<<endl;
}