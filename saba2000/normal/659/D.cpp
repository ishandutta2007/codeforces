#include<iostream>
using namespace std;
int n,a[10000],b[10000],m,k,l,ans,q;
main()
{
cin>>n;
for (int i=0; i<n; i++)
{cin>>a[i]>>b[i];}
for (int i=0; i<n; i++)
{q=ans;
if (i==0) m=n-1; else m=i-1;
if (i==n-1) k=0; else k=i+1;
if (a[m]==a[i]){
if (b[i]<b[m] && a[i]<a[k]) ans++;else
if (b[i]>b[m] && a[i]>a[k]) ans++;}
else
{if (a[i]<a[m] && b[i]>b[k]) ans++;
else if (a[i]>a[m] && b[i]<b[k]) ans++;

}
//if (ans>q) cout<<i<<endl;

}
cout<<ans<<endl;
}