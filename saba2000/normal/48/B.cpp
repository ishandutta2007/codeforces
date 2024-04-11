#include <iostream>
using namespace std;
int g[60][60];
int f(int n,int m,int a,int b)
{int d=5000;
for (int i=0; i<=n-a; i++)
for (int j=0; j<=m-b; j++)
{int s=0;

for (int t=i; t<i+a; t++)
for (int z=j; z<j+b; z++)
s+=g[t][z];
d=min(s,d);
}
return d;
}
int main ()
{int n,m,a,b;
cin>>n>>m;
for (int i=0; i<n; i++)
for (int j=0; j<m; j++)
cin>>g[i][j];
cin>>a>>b;
cout<<min(f(n,m,a,b),f(n,m,b,a));
return 0;
}