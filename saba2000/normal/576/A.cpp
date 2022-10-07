#include <iostream>
using namespace std;
int n,l[1000],p,s;
int usg(int a, int b)
{if (max(a,b)%min(a,b)==0) return min(a,b);
return usg(b,a%b); 
}
int main ()
{
cin>>n;
for (int i=2; i<=n; i++)
{p=i;
for (int j=i-1; j>1; j--)
p/=usg(l[j],p);
if (p!=1) s++;
l[i]=p;
}
cout<<s<<endl;
for (int i=2; i<=n; i++)
{p=i;
for (int j=i-1; j>1; j--)
p/=usg(l[j],p);
if (p!=1) cout<<i<<" ";
}cout<<endl;}