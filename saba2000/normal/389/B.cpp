#include <iostream>
using namespace std;
int main ()
{char c[100][100];
int n; int an=0;
cin>>n;
for (int i=0; i<n; i++)
for (int j=0; j<n; j++)
cin>>c[i][j];
for (int i=0; i<n; i++)
for (int j=0; j<n; j++)
if (c[i][j]=='#' && c[i-1][j]=='#'  && c[i+1][j]=='#'  && c[i][j+1]=='#'  && c[i][j-1]=='#' ) {c[i][j]='.'; c[i+1][j]='.'; c[i-1][j]='.'; c[i][j+1]='.'; c[i][j-1]='.';}
for (int i=0; i<n; i++)
for (int j=0; j<n; j++)
if (c[i][j]=='#') an=1;
if (an==1) cout<<"NO"<<endl; else cout<<"YES"<<endl;
return 0;
}