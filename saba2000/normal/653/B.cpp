#include<iostream>
using namespace std;
char a[99],b[99],c[99];
int n,q,ans;
void tardis(string p)
{string s=p;
if(p.length()==n) {ans++; return;}
for (int i=0; i<q; i++)
if(c[i]==p[0]) {s[0]=b[i]; s=a[i]+s; tardis(s); s=p;}
}
main()
{
cin>>n>>q;
for (int i=0; i<q; i++)
cin>>a[i]>>b[i]>>c[i];
tardis("a");
cout<<ans<<endl;
}