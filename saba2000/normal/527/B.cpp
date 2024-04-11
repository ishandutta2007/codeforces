#include <string>
#include <iostream>
using namespace std;
int main ()
{int a[125][125]={0};
for (int i=0; i<125; i++)
for (int j=0; j<125; j++)
a[i][j]=-1;
int n,l=0,i1=-1,j1=-1,i2=-1,j2=-1;
string s,k;
cin>>n; cin>>s>>k;
for (int i=0; i<n; i++)
if (s[i]!=k[i]) {l++; a[s[i]][k[i]]=i;}
for (int i=97; i<124; i++)
for (int j=97; j<124; j++)
{
if (a[i][j]>=0 && a[j][i]>=0) {i2=a[i][j]+1; j2=a[j][i]+1;}
if (a[i][j]>=0)
for (int k=97; k<124; k++)
{if (a[i][j]>=0 && a[k][i]>=0) {i1=a[i][j]+1; j1=a[k][i]+1;}}}
if (i2!=-1) cout<<l-2<<endl<<i2<<" "<<j2<<endl; else if (i1!=-1) cout<<l-1<<endl<<i1<<" "<<j1<<endl; else cout<<l<<endl<<-1<<" "<<-1<<endl;}