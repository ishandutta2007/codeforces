#include<iostream>
#include<algorithm>
using namespace std;
main()
{int a[1009],b[1009];
int n;
cin>>n;
for (int i=0; i<n; i++)
cin>>a[i];
sort(a,a+n);
for (int i=0; i<n; i+=2)
b[i]=a[i/2];
for (int i=1; i<n; i+=2)
b[i]=a[n-1-i/2];
for (int i=0; i<n; i++)
cout<<b[i]<<' ';
}