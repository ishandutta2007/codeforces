#include<iostream>
#include <string>
using namespace std;
int main ()
{
string k;
int l=0,p;
cin>>p>>k;
for (int i=65; i<91; i++)
for (int j=0; j<p; j++)
if (k[j]==i || k[j]-32==i) {l++; break;}
if (l==26) cout<<"YES"<<endl; else cout<<"NO"<<endl;
//system ("pause");
return 0;
}