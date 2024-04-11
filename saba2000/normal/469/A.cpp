#include <iostream>
using namespace std;
int main ()
{int a[100]={0};
int n,p,q,r;
cin>>n>>p;
for (int i=0; i<p; i++)
{cin>>r; a[r-1]=1;
}
cin>>q;
for (int i=0; i<q; i++)
{cin>>r; a[r-1]=1;
}
r=0;
for (int i=0; i<n; i++)
{
r+=a[i];}
if (r==n) cout<<"I become the guy."<<endl; else cout<<"Oh, my keyboard!"<<endl;
//system ("pause");
return 0;
}