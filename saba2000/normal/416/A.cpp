#include <iostream>
#include <string>
using namespace std;
int main ()
{int n,mi=-1000000009,ma=1000000009;
cin>>n;
for (int i=0; i<n; i++)
{
string s; int n; string k;
cin>>s>>n>>k;
if ((s==">" && k=="Y" || s=="<=" && k=="N") && n+1>mi) mi=n+1;
if ((s==">=" && k=="Y" || s=="<" && k=="N") && n>mi) mi=n;
if ((s==">" && k=="N" || s=="<=" && k=="Y") && n<ma) ma=n;
if ((s==">=" && k=="N" || s=="<" && k=="Y") && n-1<ma) ma=n-1;
}
if (mi>ma) cout<<"Impossible"<<endl; else cout<<mi<<endl;
return 0;
}