#include <iostream>
using namespace std;
int main ()
{int n,m,a[109][109],a2=0,a3=0,l=0;
cin>>n>>m;
for (int i=0; i<n; i++)
for (int j=0; j<m; j++)
cin>>a[i][j];
for (int i=0; i<n-1; i++)
if (a[i][0]==1 && a[i+1][m-1]==1 || a[i][m-1]==1 && a[i+1][0]==1) a2=1;
for (int i=0; i<m-1; i++)
if (a[0][i]==1 && a[n-1][i+1]==1 || a[n-1][i]==1 && a[0][i+1]==1) a2=1;
for (int i=0; i<n; i++)
if (a[i][0]==1 || a[i][m-1]==1) a2=1;
for (int i=0; i<m; i++)
if (a[0][i]==1 || a[n-1][i]==1) a2=1;
for (int i=0; i<n; i++)
{l=0; for (int j=0; j<m; j++)
if (a[i][j]==1 && a[i][j+1]==1) l=1;
if (l==1 && (a[i-1][0]==1 || a[i+1][0]==1 || a[i-1][m-1]==1 || a[i+1][m-1]==1)) a3=1;
} l=0;
for (int j=0; j<m; j++)
{l=0; for (int i=0; i<n; i++)
if (a[i][j]==1 && a[i+1][j]==1) l=1;
if (l==1 && (a[0][j-1]==1 || a[0][j+1]==1 || a[n-1][j-1]==1 || a[n-1][j+1]==1)) a3=1;
}
if (a2==1) cout<<2<<endl; else
if (a3==1) cout<<3<<endl; else
cout<<4<<endl;
return 0;
}