#include<iostream>
using namespace std;
int n,a[300000],b[300000],k,p=0;
main()
{
cin>>n;
for(int i=0; i<n; i++)
cin>>a[i];
for(int i=0; i<n; i++)
cin>>b[i];
int s=b[0];
if(b[0]==0) s=b[1];
for(int i=0; i<n; i++)
if (a[i]==s) k=i;
for (int i=k; i<k+n; i++)
{if(b[p]==0) p++;
if(a[i%n]==0) i++;
if (i==k+n) break;
if(a[i%n]!=b[p]) {cout<<"NO"<<endl;  return 0;} 
p++;
}
cout<<"YES"<<endl;
}