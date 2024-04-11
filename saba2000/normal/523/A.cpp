#include <iostream>
using namespace std;
int main ()
{ int m,n;
char r[100][100];
cin>>m>>n;
for (int i=0; i<n; i++)
for (int j=0; j<m; j++)
cin>>r[i][j];
for (int i=0; i<m; i++)
for (int k=0; k<2; k++)
{for (int j=0; j<n; j++)
cout<<r[j][i]<<r[j][i];
cout<<endl;}
//system ("pause");
return 0;
}