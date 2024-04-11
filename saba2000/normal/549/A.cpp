#include <iostream>
using namespace std;
int main ()
{int n,m,a=0,an=0; char t[1000][1000];
cin>>n>>m;
for (int i=0; i<n; i++)
for (int j=0; j<m; j++)
cin>>t[i][j];
for (int i=0; i<n-1; i++)
{for (int j=0; j<m-1; j++)
{a=0;
if (t[i][j]=='f' || t[i+1][j]=='f' ||  t[i][j+1]=='f' || t[i+1][j+1]=='f') a++;
if (t[i][j]=='a' || t[i+1][j]=='a' ||  t[i][j+1]=='a' || t[i+1][j+1]=='a') a++;
if (t[i][j]=='c' || t[i+1][j]=='c' ||  t[i][j+1]=='c' || t[i+1][j+1]=='c') a++;
if (t[i][j]=='e' || t[i+1][j]=='e' ||  t[i][j+1]=='e' || t[i+1][j+1]=='e') a++;
if (a==4) an++;}}

cout<<an;
return 0;
}