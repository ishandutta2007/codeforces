#include <iostream>   
using namespace std;
int main ()
{int n,a[2009],b[2009]={0},sum=0;
cin>>n;
for (int i=0; i<n; i++)
{cin>>a[i]; b[a[i]]++;}
for (int i=2000; i>0; i--)
{
sum+=b[i]; b[i]=sum-b[i];}
for (int i=0; i<n; i++)
cout<<b[a[i]]+1<<" ";
return 0;
}