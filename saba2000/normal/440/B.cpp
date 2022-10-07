#include<iostream>
#include <algorithm>
using namespace std;
int main ()
{long long int a[50009],t,s;
long long int n; cin>>n;
for (int i=0; i<n; i++)
{cin>>a[i]; s+=a[i];} s/=n;
for (int i=0; i<n; i++)
{t+=abs(a[i]-s);
a[i+1]+=a[i]-s;}
cout<<t<<endl;
return 0;
}