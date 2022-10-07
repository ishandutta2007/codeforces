#include <iostream>
using namespace std;
int n;
int a[5009];
int X[5009];
int c[5009],b[5009];
int dp[5009];
main(){
cin>>n;
for(int i=1; i<=n; i++)
{cin>>a[i];
c[a[i]]=i;
if(b[a[i]]==0)b[a[i]]=i;
}
for(int i=1; i<=n; i++)
{int x=0;int r=n,l=0;
dp[i]=dp[i-1];
for(int j=i; j>=1; j--)
{
r=min(r,b[a[j]]);
l=max(l,c[a[j]]);
if(j==b[a[j]]) x=(x^(a[j]));
if(j==r && i==l) dp[i]=max(dp[i],(x+dp[j-1])); 
}}
cout<<dp[n]<<endl;
}