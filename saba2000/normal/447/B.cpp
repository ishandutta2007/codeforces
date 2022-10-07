#include <iostream>
#include <string>
using namespace std;
int main ()
{int k,an=0,p[26],r=0; string s;
cin>>s>>k;
for (int i=0; i<26; i++)
{cin>>p[i]; if (p[i]>r) r=p[i];}
for (int i=0; i<s.length(); i++)
an+=p[s[i]-97]*(i+1);
for (int i=1; i<=k; i++)
an+=r*(i+s.length());
cout<<an<<endl;
return 0;
}