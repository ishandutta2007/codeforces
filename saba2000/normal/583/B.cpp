#include <iostream>
using namespace std;
int main()
{int n,a[1000],b[1000]={0},k=0,p=-1,s=0;
cin>>n;
for (int i=0; i<n; i++)
cin>>a[i];
while (1)
{k=1; 
for (int i=0; i<n; i++)
if (b[i]==0 && s>=a[i]) {s++; b[i]=1; k=0;} p++;
if (s==n) {cout<<p<<endl; return 0;}
for (int i=n-1; i>=0; i--)
if (b[i]==0 && s>=a[i]) {s++; b[i]=1; k=0;} p++;
if (s==n) {cout<<p<<endl; return 0;}
}
}