#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string k;
    string p;
    string m="             ";
    int z=0,v=0,u=0;
    cin>>k;

    for (int i=0; i<=k.length(); i++)
    {
    z=0; v=0;
    for (int q=97; q<123; q++)
    {
    v=0; z=0;
    for (int t=0; t<=k.length(); t++)
    {if (t==i) {m[t]=(char)q; z=1;}
    else if (z==1) m[t]=k[t-1];
    else m[t]=k[t];}
    v=0;
    for (int y=0; y<=k.length(); y++)
    {if (m[y]!=m[k.length()-y]) v=1;
}
    if (v==0) {p=m; u=1; break;}
}
if (u==1) break;
}    
cout<<p<<endl;
if (u==0) cout<<"NA"<<endl;
return 0;
}