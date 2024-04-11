#include<iostream>
#include<string>
using namespace std;
main()
{string s;
int n,r,l,u,d,ans=0;
cin>>n>>s;
for (int i=0; i<n; i++)
for (int j=i+1; j<n; j++)
{r=0; l=0; u=0; d=0;
for (int k=i; k<=j; k++){
if (s[k]=='R') r++;
if (s[k]=='L') l++;
if (s[k]=='U') u++;
if (s[k]=='D') d++;
}
if (r==l && u==d) ans++;
}
cout<<ans<<endl;



}