#include <iostream>
using namespace std;
int n,a[100009],b[100009],c[100009],l;
int main ()
{cin>>n;
for (int i=0; i<n; i++)
{cin>>a[i]; b[a[i]]=1;}
for (int i=1; i<=n; i++)
if (b[i]==0) {c[l]=i; l++;}
l=0;
for (int i=0; i<n; i++)
{if (b[a[i]]==2 || a[i]>n) {a[i]=c[l]; l++;}
b[a[i]]=2;}
for (int i=0; i<n; i++)
cout<<a[i]<<" ";

}