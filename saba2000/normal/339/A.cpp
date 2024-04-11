#include <iostream>
#include <string>
using namespace std;
int main ()
{string s;
int n1=0,n2=0,n3=0,m;
cin>>s;
for (int i=0; i<s.length(); i++)
{if (s[i]=='1') n1++;
if (s[i]=='2') n2++;
if (s[i]=='3') n3++;
}
m=n1+n2+n3;
for (int i=0; i<n1; i++)
{cout<<1;
m--;
if (m>0)cout<<"+"; }
for (int i=0; i<n2; i++)
{cout<<2;
m--;
if (m>0)cout<<"+"; }
for (int i=0; i<n3; i++)
{cout<<3;
m--;
if (m>0)cout<<"+"; }
cout<<endl;
//system ("pause");
return 0;
}