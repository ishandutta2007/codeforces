#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main ()
{int n,t[109],s=0,d=0,k,r;
 cin>>n;
for (int i=0; i<n; i++)
{cin>>t[i]; if (t[i]==1) s++;} d=s; k=s; r=s; if (s==n) {cout<<n-1<<endl; return 0;}
for (int i=0; i<n; i++)
{s=r; k=r;
if (t[i]==0)  
for (int j=i; j<n; j++)
{
if (t[j]==0) s++; else s--;
k=max(k,s);
}
d=max(d,k);
}
cout<<d<<endl;
return 0;
}