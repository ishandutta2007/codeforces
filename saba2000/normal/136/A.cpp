#include <iostream>
using namespace std;
int main ()
{ int n,a[200];
cin>>n; int k;
for (int i=0; i<n; i++)
{cin>>k;
a[k-1]=i+1;
}
for (int i=0; i<n; i++)
cout<<a[i]<<" ";
return 0;
}