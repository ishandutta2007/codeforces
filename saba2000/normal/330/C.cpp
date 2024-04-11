#include<iostream>
using namespace std;
int n,a[109],b[109],c[109],d[109],p,q;
main()
{
char k;
cin>>n;
for (int i=0; i<n; i++)
for (int j=0; j<n; j++)
{cin>>k;
if(k=='.' &&  a[i+1]==0) {p++; a[i+1]=i+1; b[i+1]=j+1;}
if(k=='.' &&  c[j+1]==0) {q++; c[j+1]=i+1; d[j+1]=j+1;}
}
if (p<n && q<n) cout<<-1<<endl; 
else
for (int i=1; i<=n; i++)
{if(p==n) cout<<a[i]<<" "<<b[i]<<endl;
else cout<<c[i]<<" "<<d[i]<<endl;

}}