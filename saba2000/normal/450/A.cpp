#include <iostream>
using namespace std;
int main ()
{int n,m,a[200],k;
cin>>n>>m;
for (int i=0; i<n; i++)
cin>>a[i];
for (int j=0; j<100; j++)
for (int i=0; i<n; i++)
if (a[i]>0) {k=i+1; a[i]-=m;}
cout<<k<<endl; 
//system ("pause");
return 0;
}