#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n,p,q,k,a[100009];
int s[320][100009];
main()
{
cin>>n;
for(int i=1; i<=n; i++)
cin>>a[i];
cin>>q;
for(int i=1; i<=sqrt(n); i++)
for(int j=n; j>=0; j--)
{if(j+a[j]+i>n) s[i][j]=1;
else s[i][j]=s[i][j+a[j]+i]+1;}
for(int i=0; i<q;i++)
{cin>>p>>k;
if(k<=sqrt(n)) cout<<s[k][p]<<endl;
else{
int z=0;
while(p<=n){p+=a[p]+k; z++;}
cout<<z<<endl;
}}
}