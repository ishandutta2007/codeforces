#include <iostream>
using namespace std;
int main ()
{char a[50],b[50];
int n,k,t=0,u=0;
cin>>n;
k=n;
for (int i=0; i<n; i++)
cin>>a[i];
for (int i=0; i<n; i++)
{t=0; k=n-u;
for (int j=0; j<k-1; j++)
{if (i%2==0) {if (a[j]!=a[j+1]) {b[t]=a[j]; t++;} else u++; }
else {if (b[j]!=b[j+1]) {a[t]=b[j]; t++; } else u++; }
}
if (i%2==0) b[n-u-1]=a[k-1]; else a[n-u-1]=b[k-1];
}
cout<<u<<endl;
//system ("pause");
return 0;
}