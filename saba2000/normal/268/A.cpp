#include <iostream>
using namespace std;
int main ()
{int n,h[30],g[30],b,l,k=0;
cin>>n;
for (int i=0; i<n; i++)
{cin>>b>>l;
h[i]=b; g[i]=l;
}
for (int i=0; i<n; i++)
for (int j=0; j<n; j++)
if (i!=j)if (h[i]==g[j]) k++;
cout<<k<<endl;
//system ("pause");
return 0;
}