#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{long long int k[100009]={0},p[100009]={0},r[100009]={0};
int n,m;
cin>>n;
for (int i=1; i<=n; i++)
{cin>>k[i];
p[i]=p[i-1]+k[i];}
sort (k+1,k+n+1);
for (int i=1; i<=n; i++)
r[i]=r[i-1]+k[i];
cin>>m;
for (int i=0; i<m; i++)
{int a,b,t;
cin>>t>>a>>b;
if (t==1) cout<<p[b]-p[a-1]<<endl; 
else cout<<r[b]-r[a-1]<<endl;
}
return 0;
}