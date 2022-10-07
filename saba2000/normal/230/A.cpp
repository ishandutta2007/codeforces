#include <iostream>
using namespace std;
int main ()
{int ds[1500],bfdd[1500],n,s,u=0;
cin>>s>>n;
for (int i=0; i<n; i++)
cin>>ds[i]>>bfdd[i];
for (int j=0; j<n; j++)
for (int i=0; i<n; i++)
{if (s>ds[i] && ds[i]>0) {u++; s+=bfdd[i]; ds[i]=-1;}
}
if (u==n) cout<<"YES"<<endl; else cout<<"NO"<<endl;
//system ("pause");
return 0;
}