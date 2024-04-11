#include <iostream>
#include <string>
using namespace std;
string wub(string k,int i)
{string b="";
b=b+k[i];
b=b+k[i+1];
b=b+k[i+2];
return b;
}
int main ()
{string a,b; int m=0,s,r;
cin>>a;
for (int i=0; i<a.length(); i++)
{s=i; m=0;
while ("WUB"==wub(a,i))
{i+=3; m=1; r=i;}
if (m==1 && s!=0 && r!=a.length()) cout<<" ";
if (r!=a.length()) cout<<a[i];
}}