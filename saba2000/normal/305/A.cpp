#include<iostream>
using namespace std;
int s,a,b,c,d,e,f,m,n,l,k,p;
main()
{cin>>s;
for (int i=0; i<s; i++)
{cin>>e;
if (e==0) {a=1; m=0;} else
if (e==100) {b=1; n=e;} else
if (e%10==0) {c=1; l=e;} else
if (e/10==0) {d=1; k=e;} else
{f=1; p=e;}
}
cout<<a+b+max(f,c+d)<<endl;
if (a!=0) cout<<m<<" ";
if (b!=0) cout<<n<<" ";
if (c!=0 && c+d>f) cout<<l<<" ";
if (d!=0 && c+d>f) cout<<k<<" ";
if (f!=0 && f>=c+d) cout<<p<<" ";

}