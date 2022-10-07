#include <iostream>
using namespace std;
int main ()
{int n,t[20009],l=0,ans=0,r=0,p=0;
cin>>n;
for (int i=0; i<n; i++) 
{cin>>t[i]; ans+=t[i];}
for (int i=3; i<=n/2; i++) 
{if (n%i!=0) continue;

for (int j=0; j<n/i; j++) //0 - 1 0 2 4 6 1 3 5 7
{l=0;
for (int k=j; k<n; k+=n/i)
{l+=t[k];}ans=max(ans,l);
}
}
cout<<ans<<endl;
return 0;
}