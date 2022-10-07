#include <iostream>
using namespace std;
int n,h[100000],cmh;
int main ()
{cin>>n;
for (int i=0; i<n; i++)
cin>>h[i];
for (int i=n-1; i>=0; i--)
{if (h[i]>cmh) {cmh=h[i]; h[i]=0;}
else h[i]=cmh-h[i]+1;}
for (int i=0; i<n; i++)
cout<<h[i]<<" ";
cout<<endl;}