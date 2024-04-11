#include<bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;
ll x[300009];
main()
{
ll n;
cin>>n;
for (int i=0; i<n; i++)
cin>>x[i];
sort(x,x+n);
ll a=x[0],b=1,ans=0;
for (int i=1; i<n; i++)
{
ans=(ans+x[i]*(2*b-1)-a)%M;
a=(2*a+x[i])%M;
b=2*b%M;
}
cout<<ans<<endl;

}//1 3 4