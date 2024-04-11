#include <iostream>
using namespace std;
int main ()
{int n,t,c,l=0,ans=0; cin>>n>>t>>c; int k[200009];
for (int i=0; i<n; i++)
cin>>k[i];
for (int i=0; i<n; i++)
{int j=i-c+1;
if (k[i]>t) {if (j<l) j=l;
for (j;j<=i;j++)
{if (j<n) k[j]=-1; }
l=i+1; 
}
}  
for (int i=0; i<=n-c; i++)
{if (k[i]!=-1) ans++; }
cout<<ans<<endl;
return 0;
}