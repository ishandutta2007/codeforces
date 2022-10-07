#include <iostream>
using namespace std;
int main ()
{int n;
cin>>n;
for (int i=0; i<n; i++)
{for (int j=1; j<=n/2; j++)
{cout<<i*(n/2)+j<<" "<<n*n+1-(i*(n/2)+j)<<" ";}
cout<<endl;
}
//system ("pause");
return 0;
}