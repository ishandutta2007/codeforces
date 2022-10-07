#include <iostream>
using namespace std;
int main ()
{int n,a=0,b=0,c=0,d=0,e=0,t[1000]; cin>>n;
for (int i=0; i<n; i++)
{cin>>t[i]; if (t[i]>0) b=t[i]; else if (t[i]<0) if( c==0) c=t[i]; else if (d==0) d=t[i]; else e=t[i];}
cout<<1<<" "<<c<<endl;
if (b!=0) {cout<<1<<" "<<b<<endl<<n-2<<" "; d=0; e=0;} else
{b=0; cout<<2<<" "<<d<<" "<<e<<endl<<n-3<<" "; }
for (int i=0; i<n; i++)
if ((b==0 || t[i]!=b) && (d==0 || t[i]!=d) && (e==0 || t[i]!=e) && t[i]!=c) cout<<t[i]<<" ";
cout<<endl;
return 0;
}