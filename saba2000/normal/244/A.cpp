#include <iostream>
using namespace std;
int main ()
{int n,k,a[1000]={0},b[40]={0};
cin>>n>>k;
for (int i=0; i<k; i++)
{cin>>b[i]; a[b[i]]=1;}
for (int i=0; i<k; i++)
{cout<<b[i]<<" ";
for (int j=1; j<n; j++)
{for (int p=1; p<1000; p++)
if (a[p]==0) {a[p]=1; cout<<p<<" "; break;}}cout<<endl;}
return 0;
}