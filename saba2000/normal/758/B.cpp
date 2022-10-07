#include<iostream>
#include<cmath>
using namespace std;
int a=0,b=0,c=0,d=0,a1,b1,c1,d1;
main()
{string s;
cin>>s;
for (int i=0; i<s.size(); i++)
{if (s[i]=='R' && a1==0) {for (int j=i%4; j<s.size(); j+=4) if (s[j]=='!') a++; a1=1;}
if (s[i]=='B' && b1==0) {for (int j=i%4; j<s.size(); j+=4) if (s[j]=='!') b++; b1=1;}
if (s[i]=='Y' && c1==0) {for (int j=i%4; j<s.size(); j+=4) if (s[j]=='!') c++; c1=1;}
if (s[i]=='G' && d1==0) {for (int j=i%4; j<s.size(); j+=4
) if (s[j]=='!') d++; d1=1;}
}
cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
}