#include <iostream>
using namespace std;
int main ()
{int n,m,l=0; char c[2]={'B','W'},k[100][100];
cin>>n>>m;
for (int i=0; i<n; i++)
for (int j=0; j<m; j++)
{cin>>k[i][j];
if (k[i][j]=='.') k[i][j]=c[(i+j)%2];
}
for (int i=0; i<n; i++)
{for (int j=0; j<m; j++)
cout<<k[i][j];
cout<<endl;
}
return 0;
}