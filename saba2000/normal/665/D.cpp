#include<iostream>
using namespace std;
int n,a[1380],b[2300800],p,q,t=-1,a1=0,a2=0;
main()
{
cin>>n;
p=0; q=0;
for (int i=2; i<=2200; i++)
for (int j=2*i; j<=2200000; j+=i)
b[j]=1;
for (int i=0; i<n; i++)
{cin>>a[i];
if (a[i]==1) a1++;
if (a[i]+1!=2 && b[a[i]+1]==0) t=i;
for (int j=0; j<i; j++)
if (b[a[i]+a[j]]==0) {p=i; q=j;}
}
if (t!=-1 && a1>0) {cout<<a1+1<<endl<<a[t]<<" "; 

for (int i=0; i<a1; i++) cout<<1<<" ";}
else 
if (a1>1){cout<<a1<<endl;for (int i=0; i<a1; i++) cout<<1<<" ";}
else if (p==0 && q==0) cout<<1<<endl<<a[0]<<endl;
else cout<<2<<endl<<a[p]<<" "<<a[q]<<endl;

}