#include <iostream>
using namespace std;
int main ()
{int n,m,k[1009]={0},a,b;
cin>>n>>m;
for (int i=0; i<m; i++)
{cin>>a>>b; k[a]=1; k[b]=1;}
for (int i=1; i<=n; i++)
if (k[i]==0) a=i;
cout<<n-1<<endl;
for (int i=1; i<=n; i++)
if (i!=a) cout<<a<<" "<<i<<endl;
return 0;
}